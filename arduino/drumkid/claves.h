#ifndef claves_H_
#define claves_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"
 
#define claves_NUM_CELLS 783
#define claves_SAMPLERATE 16384
 
CONSTTABLE_STORAGE(int8_t) claves_DATA [] = {0, 0, 0, 0, 1, -1, 1, 0, 1, -1, 1,
-1, 1, -2, 2, -3, 2, -3, 4, -6, 22, 86, -3, -94, -101, -21, 76, 105, 44, -56,
-102, -63, 34, 98, 77, -12, -87, -88, -12, 73, 93, 32, -54, -94, -50, 35, 89,
65, -15, -81, -75, -5, 68, 83, 24, -52, -84, -41, 35, 80, 55, -18, -74, -65, -1,
64, 71, 18, -50, -74, -33, 35, 73, 46, -19, -67, -56, 4, 59, 62, 12, -47, -66,
-27, 35, 65, 38, -21, -62, -48, 6, 55, 54, 8, -45, -58, -20, 35, 58, 32, -22,
-55, -41, 9, 51, 46, 4, -42, -50, -15, 33, 52, 26, -22, -50, -34, 10, 46, 40, 1,
-39, -44, -10, 31, 45, 20, -22, -44, -29, 11, 42, 35, -2, -36, -39, -8, 30, 39,
16, -21, -40, -24, 13, 38, 30, -4, -33, -33, -4, 27, 35, 13, -21, -36, -19, 12,
34, 25, -5, -30, -29, -2, 25, 31, 10, -19, -31, -15, 13, 30, 22, -7, -28, -25,
-1, 24, 27, 7, -19, -27, -13, 13, 26, 18, -6, -24, -21, 1, 21, 23, 5, -17, -24,
-10, 13, 24, 14, -8, -23, -17, 2, 19, 21, 3, -16, -21, -8, 12, 21, 11, -8, -20,
-15, 2, 18, 17, 2, -15, -18, -5, 12, 18, 9, -8, -17, -12, 3, 16, 15, 1, -14,
-16, -4, 10, 17, 8, -7, -15, -10, 4, 14, 12, 0, -12, -13, -3, 10, 14, 6, -7,
-13, -8, 4, 12, 10, -1, -10, -12, -2, 10, 13, 4, -7, -11, -7, 5, 11, 9, -1, -9,
-10, 0, 8, 10, 4, -7, -10, -5, 5, 10, 7, -2, -9, -7, 0, 8, 9, 2, -5, -9, -4, 4,
8, 6, -3, -8, -7, 0, 7, 7, 1, -5, -8, -4, 4, 7, 5, -2, -7, -6, 1, 6, 7, 2, -5,
-6, -3, 3, 7, 4, -2, -6, -5, 1, 5, 5, 0, -5, -6, -2, 3, 6, 3, -1, -4, -4, 1, 4,
4, 0, -4, -5, -1, 3, 4, 2, -2, -4, -3, 1, 4, 4, 0, -3, -4, -1, 3, 4, 1, -1, -4,
-3, 2, 3, 3, 0, -3, -4, -1, 2, 3, 1, -2, -4, -2, 1, 3, 2, -1, -3, -3, 0, 2, 2,
1, -1, -2, -2, 1, 3, 1, -1, -2, -2, 0, 2, 2, 1, -2, -2, -1, 1, 2, 1, -1, -1, -2,
1, 1, 2, 1, -2, -2, -2, 1, 1, 1, -1, -2, -2, 0, 1, 2, 0, -1, -1, -1, 0, 2, 1,
-1, -2, -2, 1, 2, 1, 0, -2, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, 1, 0, -1, -1, -1,
1, 2, 0, 0, -1, -1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, -1, -1, 0, 1, 0, 0, -1, -1,
0, 1, 1, 1, -1, -2, 0, 0, 1, 1, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 1, 1, 1, 0, -1,
-1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 0, 0, 0, 0, 1, 0, 1, -1, 0, -1, -1, 1, 0, 0, 0,
0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 1, 0, -1, 0, 0, 0, 0, 0, 0,
1, 0, 0, 1, 1, 1, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, -1, 0,
0, 1, -1, -1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, -1, -1, 0, 0, 0, 1,
0, 0, 0, 1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, 0, };

#endif /* claves_H_ */