// include relevant mozzi libraries
#include <MozziGuts.h>
#include <Sample.h>
#include <EventDelay.h>
#include <mozzi_rand.h>
#include "Channel.h"

// include other stuff
#include <Bounce2.h>

// include custom sample files
#include "kick.h"
#include "closedhat.h"
#include "snare.h"

// define some numbers etc
#define CONTROL_RATE 64
#define START_STOP_PIN 7
#define SHIFT_PIN 8
#define BUTTON_A_PIN 10
#define BUTTON_B_PIN 11
#define BUTTON_C_PIN 12

#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6

// define buttons
Bounce buttonA = Bounce();
Bounce buttonB = Bounce();
Bounce buttonC = Bounce();
Bounce startStopButton = Bounce();
Bounce shiftButton = Bounce();

// define samples
Sample <kick_NUM_CELLS, AUDIO_RATE> aSample(kick_DATA);
Sample <closedhat_NUM_CELLS, AUDIO_RATE> bSample(closedhat_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> cSample(snare_DATA);

Sample <kick_NUM_CELLS, AUDIO_RATE> kick1(kick_DATA);
Sample <kick_NUM_CELLS, AUDIO_RATE> kick2(kick_DATA);
Sample <closedhat_NUM_CELLS, AUDIO_RATE> closedhat1(closedhat_DATA);
Sample <closedhat_NUM_CELLS, AUDIO_RATE> closedhat2(closedhat_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> snare1(snare_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> snare2(snare_DATA);

// define channels
Channel kick;

byte nextSample[3] = {0,0,0};
byte sampleVolumes[3][2] = {  {255,255},
                              {255,255},
                              {255,255},};

// define other mozzi things
EventDelay kTriggerDelay;

byte bitCrushLevel; // between 0 and 7
byte bitCrushCompensation;
int beatTime = 150;
byte beatIndex = 0;
float tempo = 30;
byte blend = 64;
byte controlSet = 0;
byte ledPins[] = {LED_1,LED_2,LED_3,LED_4,LED_5};
byte ledBrightness[] = {0,0,0,0,0};

// variables relating to knob values
bool knobLocked[3] = {true,true,true}; // use byte instead?
int analogValues[3] = {0,0,0};
int initValues[3] = {0,0,0};
int storedValues[6][3] = {  {0,0,0},
                            {0,0,0},
                            {0,0,0},
                            {0,0,0},
                            {0,0,0},
                            {0,0,0},};

// define beats (temporarily here, probably move to a separate file later?)
byte beat1[][16] = {  {255,0,0,0,0,0,0,0,255,0,255,0,64,128,212,255,},
                      {64,0,64,0,64,0,64,64,0,64,64,0,64,0,64,32,},
                      {0,0,0,0,255,0,0,0,0,0,0,0,255,0,64,32,},};

byte beat2[][16] = {  {255,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,},
                      {255,0,128,0,255,0,128,0,255,0,128,0,255,0,128,0,},
                      {0,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,},};

byte blendedBeat[3][16];
byte hyper = 0;


void setup(){
  Serial.begin(9600);
  byte ledIntroDelay = 50;
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);
  pinMode(LED_5,OUTPUT);
  digitalWrite(LED_1,HIGH);
  delay(ledIntroDelay);
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,HIGH);
  delay(ledIntroDelay);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,HIGH);
  delay(ledIntroDelay);
  digitalWrite(LED_3,LOW);
  digitalWrite(LED_4,HIGH);
  delay(ledIntroDelay);
  digitalWrite(LED_4,LOW);
  digitalWrite(LED_5,HIGH);
  delay(ledIntroDelay);
  digitalWrite(LED_5,LOW);
  startStopButton.attach(START_STOP_PIN, INPUT_PULLUP);
  shiftButton.attach(SHIFT_PIN, INPUT_PULLUP);
  buttonA.attach(BUTTON_A_PIN, INPUT_PULLUP);
  buttonB.attach(BUTTON_B_PIN, INPUT_PULLUP);
  buttonC.attach(BUTTON_C_PIN, INPUT_PULLUP);
  startStopButton.interval(25);
  shiftButton.interval(25);
  buttonA.interval(25);
  buttonB.interval(25);
  buttonC.interval(25);
  startMozzi(CONTROL_RATE);
  aSample.setFreq((float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
  bSample.setFreq((float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
  cSample.setFreq((float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
  aSample.setEnd(7000); // was getting a funny click at the end of the kick sample
  kick1.setFreq((float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
  kick2.setFreq((float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
  closedhat1.setFreq((float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
  closedhat2.setFreq((float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
  snare1.setFreq((float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
  snare2.setFreq((float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
  kick1.setEnd(7000);
  kick2.setEnd(7000);
  kTriggerDelay.set(beatTime);
  randSeed();
  for(int i=0;i<20000;i++) {
    kick1.next();
    kick2.next();
    closedhat1.next();
    closedhat2.next();
    snare1.next();
    snare2.next();
  }
}

// tidy these up soon...
bool started = false;
byte aVol;
byte bVol;
byte cVol;
float newKickFreq;
float newHatFreq;
float newSnareFreq;
int thisRand[3];
void updateControl(){
  bool startNow = false;
  buttonA.update();
  buttonB.update();
  buttonC.update();
  startStopButton.update();
  shiftButton.update();

  byte prevControlSet = controlSet;
  if(buttonA.fell()) controlSet = 0 + (!shiftButton.read()?3:0);
  else if(buttonB.fell()) controlSet = 1 + (!shiftButton.read()?3:0);
  else if(buttonC.fell()) controlSet = 2 + (!shiftButton.read()?3:0);
  bool controlSetChanged = (prevControlSet != controlSet);
  
  if((kTriggerDelay.ready() && started) || startNow){
    // blend beat (make more efficient later)
    int blendedStep;
    for(byte i=0;i<3;i++) {
      thisRand[i] = rand(0,hyper); // if you do this inline (with blendedStep =...) it goes weird, so i'm doing it here
      for(byte j=0;j<16;j++) {
        //blendedBeat[i][j] = constrain(blend * (float) beat1[i][j] + (1.0-blend) * (float) beat2[i][j] + rand(0, hyper), 0, 255);
        blendedStep = constrain(((unsigned int)(blend * beat1[i][j])>>8)+((unsigned int)((255-blend) * beat2[i][j])>>8) + thisRand[i], 0, 255);
        blendedBeat[i][j] = blendedStep;
      }
    }
    if(beatIndex==4||beatIndex==12) Serial.println(thisRand[1]);
    if(beatIndex==0) ledBrightness[0] = 255;
    else if(beatIndex%4==0) ledBrightness[0] = 32;
    if(beatIndex%2==0) ledBrightness[1] = 128;
    else ledBrightness[2] = 128;

    // temp
    if(blendedBeat[0][beatIndex]>0) {
      if(nextSample[0]==0) kick1.start();
      else if(nextSample[0]==1) kick2.start();
      sampleVolumes[0][nextSample[0]] = blendedBeat[0][beatIndex];
      nextSample[0] ++;
      nextSample[0] = nextSample[0]%2;
    }
    if(blendedBeat[1][beatIndex]>0) {
      if(nextSample[1]==0) closedhat1.start();
      else if(nextSample[1]==1) closedhat2.start();
      sampleVolumes[1][nextSample[1]] = blendedBeat[1][beatIndex];
      nextSample[1] ++;
      nextSample[1] = nextSample[0]%2;
    }
    if(blendedBeat[2][beatIndex]>0) {
      if(nextSample[2]==0) snare1.start();
      else if(nextSample[2]==1) snare2.start();
      sampleVolumes[2][nextSample[2]] = blendedBeat[2][beatIndex];
      nextSample[2] ++;
      nextSample[2] = nextSample[0]%2;
    }
    
    beatIndex ++;
    beatIndex = beatIndex % 16;
    kTriggerDelay.start(beatTime);
  }
  if(startStopButton.fell()) {
    started = !started;
    if(started) {
      beatIndex = 0;
      startNow = true;
    }
  }
  for(int i=0;i<3;i++) {
    analogValues[i] = mozziAnalogRead(i);
  }
  if(controlSetChanged) {
    for(int i=0;i<3;i++) {
      knobLocked[i] = true;
      initValues[i] = analogValues[i];
      digitalWrite(ledPins[i], HIGH);
    }
  } else {
    for(int i=0;i<3;i++) {
      if(knobLocked[i]) {
        if(initValues[i]<storedValues[controlSet][i]) {
          if(analogValues[i]>=storedValues[controlSet][i]) {
            knobLocked[i] = false;
            digitalWrite(ledPins[i], LOW);
          }
        } else {
          if(analogValues[i]<=storedValues[controlSet][i]) {
            knobLocked[i] = false;
            digitalWrite(ledPins[i], LOW);
          }
        }
      }
      if(!knobLocked[i]) storedValues[controlSet][i] = analogValues[i];
    }
  }
  switch(controlSet) {
    case 0:
    hyper = storedValues[controlSet][0]>>2;
    //ceiling = storedValues[controlSet][1]>>2;
    //zoom = storedValues[controlSet][2]>>2;
    break;
    case 1:
    newKickFreq = ((float) storedValues[controlSet][0] / 255.0f) * (float) kick_SAMPLERATE / (float) kick_NUM_CELLS;
    newHatFreq = ((float) storedValues[controlSet][0] / 255.0f) * (float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS;
    newSnareFreq = ((float) storedValues[controlSet][0] / 255.0f) * (float) snare_SAMPLERATE / (float) snare_NUM_CELLS;
    kick1.setFreq(newKickFreq);
    closedhat1.setFreq(newHatFreq);
    snare1.setFreq(newSnareFreq);
    kick2.setFreq(newKickFreq);
    closedhat2.setFreq(newHatFreq);
    snare2.setFreq(newSnareFreq);
    bitCrushLevel = 7-(storedValues[controlSet][2]>>7);
    bitCrushCompensation = bitCrushLevel;
    if(bitCrushLevel >= 6) bitCrushCompensation --;
    if(bitCrushLevel >= 7) bitCrushCompensation --;
    break;
    case 2:
    // could probably optimise this maths
    tempo = 40.0 + ((float) storedValues[controlSet][0]) / 5.0;
    beatTime = 15.0 / (tempo/1000.0);
    break;
    case 3:

    break;
    case 4:

    break;
    case 5:
    blend = storedValues[controlSet][0]>>2;
    break;
  }
}

const byte atten = 10;
int updateAudio(){
  char asig = ((sampleVolumes[0][0]*kick1.next())>>atten)+((sampleVolumes[0][1]*kick2.next())>>atten)+((sampleVolumes[1][0]*closedhat1.next())>>atten)+((sampleVolumes[1][1]*closedhat2.next())>>atten)+((sampleVolumes[2][0]*snare1.next())>>atten)+((sampleVolumes[2][1]*snare2.next())>>atten);
  asig = (asig>>bitCrushLevel)<<bitCrushCompensation;
  return (int) asig;
}


void loop(){
  audioHook();
}

void updateLEDs() {
  static byte count_1=0;
  static byte count_2=85;
  static byte count_3=170;
  static byte count_4=32;
  static byte count_5=96;
// PORTD maps to Arduino digital pins 0 to 7
// http://playground.arduino.cc/Learning/PortManipulation
  (count_1++ >= ledBrightness[0]) ? PORTD &= ~(1 << ledPins[0]) : PORTD |= (1 << ledPins[0]);
  (count_2++ >= ledBrightness[1]) ? PORTD &= ~(1 << ledPins[1]) : PORTD |= (1 << ledPins[1]);
  (count_3++ >= ledBrightness[2]) ? PORTD &= ~(1 << ledPins[2]) : PORTD |= (1 << ledPins[2]);
  (count_4++ >= ledBrightness[3]) ? PORTD &= ~(1 << ledPins[3]) : PORTD |= (1 << ledPins[3]);
  (count_5++ >= ledBrightness[4]) ? PORTD &= ~(1 << ledPins[4]) : PORTD |= (1 << ledPins[4]);
}

