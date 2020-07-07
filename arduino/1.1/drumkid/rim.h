#ifndef rim_H_
#define rim_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"
 
#define rim_NUM_CELLS 427
#define rim_SAMPLERATE 16384
 
CONSTTABLE_STORAGE(int8_t) rim_DATA [] = {1, -1, 2, -7, -10, 3, 6, 3, 5, -3,
-41, -32, -28, -10, 40, 51, 36, 44, -14, -38, -26, -14, -15, 15, 62, 57, 32,
-49, -28, -19, -16, -13, 17, 63, 32, 40, -9, -99, -42, -29, -3, 45, 24, 31, 8,
20, -38, -67, -45, -16, 27, 23, 20, 19, -16, -41, -25, -20, -8, -4, 12, 25, 13,
14, 15, 17, 14, 16, 11, 40, 57, 37, -5, -86, -51, -15, 11, 35, 20, 15, 4, -1,
-11, -22, -36, -20, -20, -17, -18, -13, -28, -43, -28, -17, -3, 7, 17, 24, 30,
32, 33, 30, 29, 24, 21, 16, 16, 10, 5, -6, -9, -6, 1, 19, 15, 4, -5, -14, -21,
-25, -29, -30, -30, -27, -24, -19, -21, -28, -22, -12, -1, 9, 17, 23, 28, 30,
31, 30, 28, 24, 20, 16, 11, 7, 3, 0, -3, -5, -4, -1, 3, 6, 1, -5, -11, -17, -19,
-21, -22, -21, -21, -19, -19, -19, -15, -10, -4, 1, 8, 13, 18, 19, 23, 21, 22,
19, 17, 14, 12, 9, 5, 2, 1, -1, -4, -4, -4, -5, -4, -5, -5, -6, -7, -8, -10,
-10, -12, -13, -13, -13, -11, -10, -6, -3, 0, 4, 6, 9, 10, 12, 13, 13, 12, 11,
9, 8, 6, 5, 4, 1, 0, -2, -2, -2, -4, -4, -3, -4, -5, -5, -5, -5, -6, -6, -7, -7,
-7, -6, -4, -3, -2, 0, 2, 3, 4, 6, 6, 6, 7, 7, 7, 6, 5, 4, 4, 3, 2, 0, -1, -1,
0, -2, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -4, -5, -4, -2, -2, -1, 0, 0, 1,
2, 4, 3, 4, 4, 5, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -1, -3, -1, -2, -2,
-3, -3, -3, -3, -3, -3, -1, -1, -2, -1, 0, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3,
3, 2, 1, 1, 1, 1, 0, -1, -1, -1, -2, -1, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1,
-2, 0, 0, 0, 1, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 0, 1, 0, 0, 0, 0, -1, -1, -1, -1,
-1, -2, -2, -1, -1, -1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
0, 0, -1, 0, 0, 0, -1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
0, 0, };

#endif /* rim_H_ */