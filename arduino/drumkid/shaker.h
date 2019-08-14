#ifndef shaker_H_
#define shaker_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"
 
#define shaker_NUM_CELLS 664
#define shaker_SAMPLERATE 16384
 
CONSTTABLE_STORAGE(int8_t) shaker_DATA [] = {1, 0, 0, 0, 0, 0, -1, 0, -1, 2, -1,
-1, 1, 0, 1, 0, 1, 0, 1, 1, -1, 0, 0, 1, 0, 0, 0, 0, -3, 2, 0, -1, 0, -1, 3, -5,
3, -1, 0, 2, -3, 1, 2, 1, -2, -2, 3, -1, -2, 1, 3, -4, 6, -3, -8, 9, -3, 2, -2,
2, -3, 2, -1, 2, -3, 3, -3, 4, 0, -6, 5, -7, 7, -2, 1, -3, 3, -1, 0, 0, 7, -18,
13, 5, -18, 14, -4, 3, -2, 1, -1, 1, 0, -2, 4, -5, 0, 4, -3, 0, -4, 8, -8, 1, 6,
-6, 3, 0, 1, 0, 2, -3, 0, 3, 0, -10, 13, -5, -6, 10, -5, 4, -3, 4, -4, 5, -6, 2,
-2, 6, -8, -2, 9, -10, 18, -24, 11, 4, -3, -1, 2, -5, 5, -4, -1, 4, -10, 13, -9,
9, -7, 4, -2, 5, -5, 7, -4, -6, 9, -3, -5, 15, -17, -4, 17, -11, 13, -16, 8, 0,
-4, 6, 1, -13, 11, 2, -11, 9, -2, -1, 0, -1, 0, 1, -3, 4, -5, 3, -2, 2, 3, -13,
11, 7, -23, 15, 0, -3, 4, -5, 9, -12, 6, -10, 5, 10, -5, 2, 0, 3, -1, -3, -6, 3,
-3, 5, 3, -6, 6, -8, 10, -9, -1, 7, -10, 7, -3, -1, 3, -2, 3, -1, -9, 15, -9, 0,
3, -6, 5, 3, -9, 7, -6, 4, 1, -5, 17, -26, 16, -1, -3, 2, -1, 1, -3, 5, -2, -10,
20, -10, -10, 23, -22, 10, 0, 1, -3, 2, -1, 4, -5, 3, 0, -1, 0, 0, 7, -14, 13,
-8, 1, 3, 2, -5, 14, -18, 4, 6, -3, 0, 2, -4, 6, -5, -4, 9, -9, 9, -11, 12, -12,
16, -18, 10, -1, 2, -7, 17, -17, -9, 23, -15, 21, -28, 17, -6, 11, -7, -10, 5,
-2, 6, -5, 2, 1, 0, 0, -1, 6, -11, 4, 0, -2, 10, -15, 5, 4, 3, -18, 11, 7, -5,
-10, 13, -7, 4, 1, -5, 8, -9, 12, -17, 28, -29, 2, 13, -5, 13, -22, 3, 0, 8, -1,
-3, 6, -9, 1, 2, 0, -2, 2, -2, 0, 14, -30, 22, -7, 4, 1, 1, -3, -12, 20, -15, 7,
-5, 7, -9, 14, -13, -5, 26, -29, 2, 25, -19, -1, 9, -8, 16, -18, -5, 24, -25,
17, -12, 11, -7, 6, 4, -18, 22, -34, 34, -9, -10, 12, 1, -7, 13, -19, 15, -9, 5,
3, -15, 24, -26, 16, -3, 2, -4, 7, -12, 19, -18, 14, 1, -21, 21, 2, -17, 12, -1,
-11, 16, -12, 10, -10, 10, -9, 13, -16, 8, 7, -15, 15, -10, 4, 0, 1, -6, 3, 13,
-13, -19, 27, -11, 6, -2, 0, -1, 2, 2, -5, 7, -8, 16, -25, 21, -14, 3, 10, -8,
3, -4, 6, -6, 8, -10, 16, -16, 5, 0, 4, 1, -3, 2, -6, 4, 0, 4, -5, 6, -5, 0, -1,
-2, 4, -3, 1, 0, -1, 2, -2, 1, 1, 1, 4, -10, -1, 4, 5, -2, -8, 9, -3, 2, -1, 3,
-3, 2, -1, 0, 3, -3, -6, 1, 9, -9, 4, -2, 0, 0, 0, -1, -1, 2, -1, 0, 1, 1, -2,
0, 0, 1, 0, 0, 1, 0, 0, 3, -5, 2, 2, -1, 1, 0, 1, 0, 1, 1, 0, 1, 0, -1, 2, -1,
1, 0, 1, 0, 0, -1, -1, 1, -1, 0, 0, -1, 1, 0, 0, 1, -3, 2, 0, 0, 0, 2, -1, 0, 0,
0, 0, -1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 1, 0, 0, 1, 0, 1, 0,
1, -1, 0, 0, 0, 0, 0, 1, -1, 0, -1, 0, 1, -1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

#endif /* shaker_H_ */
