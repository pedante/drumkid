#define DEBUGGING false
#define BREADBOARD true // switch to false if compiling code for PCB

// when in debugging mode you can see the current memory usage
// you'll need to download and install this library from https://github.com/McNeight/MemoryFree
#if DEBUGGING
#include <MemoryFree.h>
#endif

// include custom Mozzi library files - copied from a specific version of Mozzi and tweaked to give extra functionality
// original Mozzi library found at https://github.com/sensorium/Mozzi
#include "MozziDK/MozziGuts.h"
#include "MozziDK/Sample.h"
#include "MozziDK/EventDelay.h"
#include "MozziDK/mozzi_rand.h"
#include "MozziDK/mozzi_fixmath.h"
#include "MozziDK/Oscil.h"
#include "MozziDK/tables/saw256_int8.h"

// include debouncing library
#include <Bounce2.h>

// include EEPROM library for saving data
#include <EEPROM.h>

// include/initialise tap tempo library - copied into repo for now because I added some functions
// original ArduinoTapTempo library found at https://github.com/dxinteractive/ArduinoTapTempo
#include "ArduinoTapTempoDK/src/ArduinoTapTempo.cpp"
ArduinoTapTempo tapTempo;

// include audio data files
#include "kick.h"
#include "closedhat.h"
#include "snare.h"
#include "rim.h"
#include "tom.h"

// define pins
byte breadboardLedPins[5] = {5,6,7,8,13};
byte breadboardButtonPins[6] = {2,3,4,10,11,12};
byte breadboardAnalogPins[4] = {0,1,2,3};
byte pcbLedPins[5] = {6,5,4,3,2};
byte pcbButtonPins[6] = {13,12,11,10,8,7};
byte pcbAnalogPins[4] = {3,2,1,0};
byte (&ledPins)[5] = BREADBOARD ? breadboardLedPins : pcbLedPins;
byte (&buttonPins)[6] = BREADBOARD ? breadboardButtonPins : pcbButtonPins;

// define buttons
Bounce buttonA = Bounce();
Bounce buttonB = Bounce();
Bounce buttonC = Bounce();
Bounce buttonX = Bounce();
Bounce buttonY = Bounce();
Bounce buttonZ = Bounce();

#define CONTROL_RATE 256 // tweak this value if performance is bad, must be power of 2 (64, 128, etc)
#define NUM_BEATS 3
#define MAX_BEAT_STEPS 32
#define NUM_PARAM_GROUPS 5
#define NUM_KNOBS 4
#define NUM_LEDS 5
#define NUM_BUTTONS 6
#define NUM_SAMPLES_TOTAL 5 // total number of samples including those only triggered by chance
#define NUM_SAMPLES_DEFINED 5 // number of samples defined in the preset drumbeats (kick, hat, snare, rim, tom)
#define SAVED_STATE_SLOT_BYTES 32
#define MIN_TEMPO 40
#define MAX_TEMPO 295

#if MIN_TEMPO + 255 != MAX_TEMPO
#error "Tempo must have a range of exactly 255 otherwise I'll have to write more code"
#endif

bool sequencePlaying = false; // false when stopped, true when playing
byte numSteps = 32;
bool beatLedsActive = true;
bool firstLoop = true;
bool secondLoop = false;
byte sampleVolumes[NUM_SAMPLES_TOTAL] = {255,255,255,255,255}; // temp
byte midiNotes[NUM_SAMPLES_TOTAL] = {36,42,38,37,43};
bool noteDown[NUM_SAMPLES_TOTAL];
bool readyToSave = true;
bool readyToChooseSaveSlot = false;
bool readyToLoad = true;
bool readyToChooseLoadSlot = false;
bool newStateLoaded = false;

// variables relating to knob values
byte controlSet = 0;
bool knobLocked[NUM_KNOBS] = {true,true,true,true};
byte analogValues[NUM_KNOBS] = {0,0,0,0};
byte initValues[NUM_KNOBS] = {0,0,0,0};

// parameters
byte paramChance;
byte paramMidpoint;
byte paramRange;
byte paramZoom;
byte paramPitch;
byte paramCrush;
byte paramCrop;
unsigned int paramGlitch;
byte crushCompensation;
int paramSlop;
byte paramSwing;
byte paramDelayMix;
unsigned int paramDelayTime;
byte paramBeat;
byte paramTimeSignature;
byte paramDrift;
byte paramDrop;
byte oscilGain1;
byte oscilGain2;
float paramDronePitch;
byte paramDroneMod;
bool droneMod2Active = false;
#define PARAM_CHANCE 0
#define PARAM_ZOOM 1
#define PARAM_MIDPOINT 2
#define PARAM_RANGE 3
#define PARAM_PITCH 4
#define PARAM_CRUSH 5
#define PARAM_CROP 6
#define PARAM_GLITCH 7
#define PARAM_SLOP 8
#define PARAM_SWING 9
#define PARAM_DELAY_TIME 10
#define PARAM_DELAY_MIX 11
#define PARAM_BEAT 12
#define PARAM_TEMPO 13
#define PARAM_TIME_SIGNATURE 14
#define PARAM_DRIFT 15
#define PARAM_DROP 16
#define PARAM_DRONE_MOD 17
#define PARAM_DRONE 18
#define PARAM_DRONE_PITCH 19
byte storedValues[NUM_PARAM_GROUPS*NUM_KNOBS];

// define samples
Sample <kick_NUM_CELLS, AUDIO_RATE> kick(kick_DATA);
Sample <closedhat_NUM_CELLS, AUDIO_RATE> closedhat(closedhat_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> snare(snare_DATA);
Sample <rim_NUM_CELLS, AUDIO_RATE> rim(rim_DATA);
Sample <tom_NUM_CELLS, AUDIO_RATE> tom(tom_DATA);

// define oscillators
Oscil<SAW256_NUM_CELLS, AUDIO_RATE> droneOscillator1(SAW256_DATA);
Oscil<SAW256_NUM_CELLS, AUDIO_RATE> droneOscillator2(SAW256_DATA);

// could just use bools instead of bytes to save space
// order of samples: kick, hat, snare, rim, tom
// USE PROGMEM LATER TO REDUCE SIZE
const byte beats[NUM_BEATS][NUM_SAMPLES_DEFINED][MAX_BEAT_STEPS] = {
  {
    {255,0,0,0,0,0,0,0,255,0,0,0,0,0,255,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,},
    {255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,},
    {0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,255,0,255,0,255,0,},
  },
  {
    {255,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,},
    {255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,},
    {0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  },
  {
    {255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,},
    {0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,},
  },
};  

float nextPulseTime = 0;
int pulseNum = 0;
byte stepNum = 0;
float tempSlop = 0.0;

void setup() {
  startMozzi(CONTROL_RATE);
  randSeed();

  kick.setFreq((float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
  closedhat.setFreq((float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
  snare.setFreq((float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
  rim.setFreq((float) rim_SAMPLERATE / (float) rim_NUM_CELLS);
  tom.setFreq((float) tom_SAMPLERATE / (float) tom_NUM_CELLS);
  
  #if DEBUGGING
  Serial.begin(9600);
  #else
  Serial.begin(31250);
  #endif
  for(byte i=0;i<NUM_LEDS;i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  buttonA.interval(25);
  buttonB.interval(25);
  buttonC.interval(25);
  buttonX.interval(25);
  buttonY.interval(25);
  buttonZ.interval(25);
  buttonA.attach(buttonPins[0], INPUT_PULLUP);
  buttonB.attach(buttonPins[1], INPUT_PULLUP);
  buttonC.attach(buttonPins[2], INPUT_PULLUP);
  buttonX.attach(buttonPins[3], INPUT_PULLUP);
  buttonY.attach(buttonPins[4], INPUT_PULLUP);
  buttonZ.attach(buttonPins[5], INPUT_PULLUP);

  // prevent samples from playing on startup
  for(int i=0;i<20000;i++) {
    kick.next();
    closedhat.next();
    snare.next();
    rim.next();
    tom.next();
  }

  droneOscillator1.setFreq(110);

  // add more default values here
  storedValues[PARAM_CHANCE] = 0;
  storedValues[PARAM_ZOOM] = 150;
  storedValues[PARAM_MIDPOINT] = 128;
  storedValues[PARAM_RANGE] = 255;
  storedValues[PARAM_CRUSH] = 255;
  storedValues[PARAM_PITCH] = 160;
  storedValues[PARAM_TIME_SIGNATURE] = 120; // this means 4/4, it's confusing...
  storedValues[PARAM_TEMPO] = 100 - MIN_TEMPO; // not BPM!
  storedValues[PARAM_DRONE] = 128;
  storedValues[PARAM_DRONE_PITCH] = 128;
  storedValues[PARAM_DRONE_MOD] = 128;
  storedValues[PARAM_CROP] = 255;

  for(byte i=0;i<NUM_PARAM_GROUPS;i++) {
    updateParameters(i);
  }

  tapTempo.setMinBPM((float) MIN_TEMPO);
  tapTempo.setMaxBPM((float) MAX_TEMPO);

  startupLedSequence();
}

bool syncReceived = false;
byte thisMidiByte;
bool testToggle = false;

void loop() {
  audioHook();
  while(Serial.available()) {
    thisMidiByte = Serial.read();
    if(thisMidiByte==0x90) {
      playMidiNote(midiNotes[4]);
      testToggle = !testToggle;
      digitalWrite(13,testToggle);      
    } else if(thisMidiByte==0xF8) {
      syncReceived = true;
      if(sequencePlaying) {
        if(pulseNum%3==0) {
          triggerNotes();
          stepNum ++;
          if(stepNum >= numSteps) stepNum = 0;
        }
        if(pulseNum%3==1) cancelMidiNotes();
        //if(pulseNum%24==0) digitalWrite(ledPins[3],HIGH);
        //else digitalWrite(ledPins[3],LOW);
        //nextPulseTime = nextPulseTime + msPerPulse;
        pulseNum = (pulseNum + 1) % 24;
      }
    }
  }
}

void toggleSequence() {
  if(sequencePlaying) stopSequence();
  else startSequence();
}

void startSequence() {
  Serial.write(0xFA); // MIDI clock start
  sequencePlaying = true;
  nextPulseTime = millis();
  pulseNum = 0;
  stepNum = 0;
}

void stopSequence() {
  Serial.write(0xFC); // MIDI clock stop
  sequencePlaying = false;
}

void updateControl() {
  byte i;
  bool controlSetChanged = false;
  newStateLoaded = false;
  
  buttonA.update();
  buttonB.update();
  buttonC.update();
  buttonX.update();
  buttonY.update();
  buttonZ.update();

  if(!buttonB.read() && !buttonC.read()) {
    readyToLoad = false;
    readyToSave = false;
    readyToChooseLoadSlot = true;
    readyToChooseSaveSlot = false;
    tapTempo.update(false);
  } else if(!buttonX.read() && !buttonY.read()) {
    readyToSave = false;
    readyToLoad = false;
    readyToChooseSaveSlot = true;
    readyToChooseLoadSlot = false;
    tapTempo.update(false);
  } else {
    readyToSave = true;
    readyToLoad = true;
    if(!readyToChooseLoadSlot&&!readyToChooseSaveSlot) {
      tapTempo.update(!buttonA.read());
    } else {
      tapTempo.update(false);
    }

    // handle button presses
    byte prevControlSet = controlSet;
    if(buttonA.fell()) {
      if(readyToChooseLoadSlot) loadParams(0);
      else if(readyToChooseSaveSlot) saveParams(0);
      else {
        controlSet = 0;
        storedValues[PARAM_TEMPO] = tapTempo.getBPM() - MIN_TEMPO;
      }
    } else if(buttonB.fell()) {
      if(readyToChooseLoadSlot) loadParams(1);
      else if(readyToChooseSaveSlot) saveParams(1);
      else controlSet = 1;
    } else if(buttonC.fell()) {
      if(readyToChooseLoadSlot) loadParams(2);
      else if(readyToChooseSaveSlot) saveParams(2);
      else controlSet = 2;
    } else if(buttonX.fell()) {
      if(readyToChooseLoadSlot) loadParams(3);
      else if(readyToChooseSaveSlot) saveParams(3);
      else controlSet = 3;
    } else if(buttonY.fell()) {
      if(readyToChooseLoadSlot) loadParams(4);
      else if(readyToChooseSaveSlot) saveParams(4);
      else controlSet = 4;
    }
    controlSetChanged = (prevControlSet != controlSet);
    
    if(buttonZ.fell()) {
      if(readyToChooseLoadSlot) loadParams(5);
      else if(readyToChooseSaveSlot) saveParams(5);
      else toggleSequence();
    }

    // messing everything up to make a glitchy effect
    if(paramGlitch>0) {
      byte minDelay = paramGlitch/4;
      byte maxDelay = (paramGlitch*paramGlitch)>>6;
      delay(rand(minDelay, maxDelay));
    }
  }
  
  if(sequencePlaying&&!syncReceived) {
    //byte tempoReading = mozziAnalogRead(breadboardAnalogPins[0])>>2;
    //tapTempo.setBPM((float) MIN_TEMPO + ((float) tempoReading));
    float msPerPulse = tapTempo.getBeatLength() / 24.0;
    if(millis()>=nextPulseTime) {
      Serial.write(0xF8); // MIDI clock continue
      if(pulseNum%3==0) {
        triggerNotes();
        stepNum ++;
        if(stepNum >= numSteps) stepNum = 0;
      }
      if(pulseNum%3==1) cancelMidiNotes();
      if(pulseNum%24==0) digitalWrite(ledPins[stepNum/8],HIGH);
      else if(pulseNum%24==2) digitalWrite(ledPins[stepNum/8],LOW);
      nextPulseTime = nextPulseTime + msPerPulse;
      pulseNum = (pulseNum + 1) % 24;
    }
  }

  for(i=0;i<NUM_KNOBS;i++) {
    if(firstLoop) {
      byte dummyReading = mozziAnalogRead(breadboardAnalogPins[i]);
    } else {
      if(BREADBOARD) {
        analogValues[i] = mozziAnalogRead(breadboardAnalogPins[i])>>2;
      } else {
        analogValues[i] = 255 - (mozziAnalogRead(pcbAnalogPins[i])>>2);
      }
    }
  }
  if(controlSetChanged||secondLoop) {
    // "lock" all knobs when control set changes
    // also do this on second loop (mozziAnalogRead doesn't work properly on first loop)
    for(byte i=0;i<NUM_KNOBS;i++) {
      knobLocked[i] = true;
      initValues[i] = analogValues[i];
    }
  } else {
    for(i=0;i<NUM_KNOBS;i++) {
      if(knobLocked[i]) {
        int diff = initValues[i]-analogValues[i];
        if(diff<-5||diff>5) knobLocked[i] = false;
      }
      if(!knobLocked[i]) {
        storedValues[NUM_KNOBS*controlSet+i] = analogValues[i]; // store new analog value if knob active
      }
    }
  }

  // do logic based on params
  if(!newStateLoaded) updateParameters(controlSet);
  
  if(firstLoop) {
    firstLoop = false;
    secondLoop = true;
  } else {
    secondLoop = false;
  }
}

void updateParameters(byte thisControlSet) {
  switch(thisControlSet) {
    case 0:
    break;
    case 1:
    {
      // pitch alteration (could do this is a more efficient way to reduce RAM usage)
      float thisPitch = fabs((float) storedValues[PARAM_PITCH] * (8.0f/255.0f) - 4.0f);
      float newKickFreq = thisPitch * (float) kick_SAMPLERATE / (float) kick_NUM_CELLS;
      float newHatFreq = thisPitch * (float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS;
      float newSnareFreq = thisPitch * (float) snare_SAMPLERATE / (float) snare_NUM_CELLS;
      float newRimFreq = thisPitch * (float) rim_SAMPLERATE / (float) rim_NUM_CELLS;
      float newtomFreq = thisPitch * (float) tom_SAMPLERATE / (float) tom_NUM_CELLS;
      kick.setFreq(newKickFreq);
      closedhat.setFreq(newHatFreq);
      snare.setFreq(newSnareFreq);
      rim.setFreq(newRimFreq);
      tom.setFreq(newtomFreq);
      bool thisDirection = storedValues[PARAM_PITCH] >= 128;
      kick.setDirection(thisDirection);
      closedhat.setDirection(thisDirection);
      snare.setDirection(thisDirection);
      rim.setDirection(thisDirection);
      tom.setDirection(thisDirection);
      
      // bit crush! high value = clean (8 bits), low value = dirty (1 bit?)
      paramCrush = 7-(storedValues[PARAM_CRUSH]>>5);
      crushCompensation = paramCrush;
      if(paramCrush >= 6) crushCompensation --;
      if(paramCrush >= 7) crushCompensation --;

      // crop - a basic effect to chop off the end of each sample for a more staccato feel
      paramCrop = storedValues[PARAM_CROP];
      kick.setEnd(thisDirection ? map(paramCrop,0,255,100,kick_NUM_CELLS) : kick_NUM_CELLS);
      closedhat.setEnd(thisDirection ? map(paramCrop,0,255,100,closedhat_NUM_CELLS) : closedhat_NUM_CELLS);
      snare.setEnd(thisDirection ? map(paramCrop,0,255,100,snare_NUM_CELLS) : snare_NUM_CELLS);
      rim.setEnd(thisDirection ? map(paramCrop,0,255,100,rim_NUM_CELLS) : rim_NUM_CELLS);
      tom.setEnd(thisDirection ? map(paramCrop,0,255,100,tom_NUM_CELLS) : tom_NUM_CELLS);
      kick.setStart(!thisDirection ? map(paramCrop,255,0,100,kick_NUM_CELLS) : 0);
      closedhat.setStart(!thisDirection ? map(paramCrop,255,0,100,closedhat_NUM_CELLS) : 0);
      snare.setStart(!thisDirection ? map(paramCrop,255,0,100,snare_NUM_CELLS) : 0);
      rim.setStart(!thisDirection ? map(paramCrop,255,0,100,rim_NUM_CELLS) : 0);
      tom.setStart(!thisDirection ? map(paramCrop,255,0,100,tom_NUM_CELLS) : 0);
      
      // experimental glitch effect
      paramGlitch = storedValues[PARAM_GLITCH];
    }
    break;
    case 4:
    paramDrop = storedValues[PARAM_DROP];
    // using values of 270 and 240 (i.e. 255±15) to give a decent "dead zone" in the middle of the knob
    oscilGain2 = constrain(2*storedValues[PARAM_DRONE]-270, 0, 255);
    if(storedValues[PARAM_DRONE] < 128) {
      oscilGain1 = constrain(240-2*storedValues[PARAM_DRONE], 0, 255);
    } else {
      oscilGain1 = oscilGain2;
    }
    // do same thing for drone modulation gains
    if(storedValues[PARAM_DRONE_MOD] < 128) {
      droneMod2Active = false;
      paramDroneMod = constrain(240-2*storedValues[PARAM_DRONE_MOD], 0, 255);
    } else {
      droneMod2Active = true;
      paramDroneMod = constrain(2*storedValues[PARAM_DRONE_MOD]-270, 0, 255);;
    }
    paramDronePitch = (float) storedValues[PARAM_DRONE_PITCH] * 0.768f + 65.41f; // gives range between "deep C" and "middle C"
    droneOscillator1.setFreq(paramDronePitch);
    droneOscillator2.setFreq(paramDronePitch*1.5f);
    break;
  }
}

void triggerNotes() {
  byte i;
  for(i=0; i<NUM_SAMPLES_TOTAL; i++) {
    if(beats[0][i][stepNum]>0) playMidiNote(midiNotes[i]);
    if(beats[0][i][stepNum]>8) { // don't bother with very quiet notes
      switch(i) {
        case 0:
        kick.start();
        break;
        case 1:
        closedhat.start();
        break;
        case 2:
        snare.start();
        break;
        case 3:
        rim.start();
        break;
        case 4:
        tom.start();
        break;
      }
    }
  }
}

const byte atten = 9;
char d1Next, d2Next;
int updateAudio() {
  d1Next = droneOscillator1.next();
  d2Next = droneOscillator2.next();
  char droneSig = ((oscilGain1*d1Next)>>10)+((oscilGain2*d2Next)>>10);
  char droneModSig = (d1Next>>2)+(droneMod2Active?(d2Next>>2):0);
  char asig = ((sampleVolumes[0]*kick.next())>>atten)+
    ((sampleVolumes[1]*closedhat.next())>>atten)+
    ((sampleVolumes[2]*snare.next())>>atten)+
    ((sampleVolumes[3]*rim.next())>>atten)+
    ((sampleVolumes[4]*tom.next())>>atten)+
    (droneSig>>2);
  asig = (asig * ((255-paramDroneMod)+((paramDroneMod*droneModSig)>>6)))>>8;
  asig = (asig>>paramCrush)<<crushCompensation;
  return (int) asig;
}

void startupLedSequence() {
  byte seq[15] = {0,1,2,3,4,3,2,1,0,1,2,3,4,3,2};
  for(byte i=0; i<15; i++) {
    digitalWrite(ledPins[seq[i]], HIGH);
    delay(30);
    digitalWrite(ledPins[seq[i]], LOW);
  }
}

void cancelMidiNotes() {
  byte i;
  for(i=0; i<NUM_SAMPLES_TOTAL; i++) {
    Serial.write(0x90);
    Serial.write(midiNotes[i]);
    Serial.write(0x00);
  }
}

void playMidiNote(byte noteNum) {
  Serial.write(0x90);
  Serial.write(noteNum);
  Serial.write(100);
}

void saveParams(byte slotNum) {
  // 1024 possible byte locations
  // currently need 20 bytes per saved state
  // currently planning choice of 6 slots for saved states (1 per button)
  // need to leave space for some possible extra saved state data
  // allot 32 bytes per saved state (nice round number), taking up total of 192 bytes
  readyToChooseSaveSlot = false;
  for(byte i=0; i<NUM_PARAM_GROUPS*NUM_KNOBS; i++) {
    EEPROM.write(slotNum*SAVED_STATE_SLOT_BYTES+i, storedValues[i]);
  }
}

void loadParams(byte slotNum) {
  readyToChooseLoadSlot = false;
  newStateLoaded = true;
  for(byte i=0; i<NUM_PARAM_GROUPS*NUM_KNOBS; i++) {
    byte thisValue = EEPROM.read(slotNum*SAVED_STATE_SLOT_BYTES+i);
    storedValues[i] = thisValue;
  }
  for(byte i=0;i<NUM_PARAM_GROUPS;i++) {
    updateParameters(i);
  }
}