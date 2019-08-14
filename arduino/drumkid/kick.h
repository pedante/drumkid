#ifndef kick_H_
#define kick_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"
 
#define kick_NUM_CELLS 7581
#define kick_SAMPLERATE 16384
 
CONSTTABLE_STORAGE(int8_t) kick_DATA [] = {-1, 2, 18, 33, 43, 51, 57, 65, 69,
73, 76, 79, 82, 82, 82, 84, 84, 82, 78, 73, 66, 60, 53, 47, 40, 33, 26, 20, 13,
5, -1, -8, -15, -21, -27, -34, -40, -46, -52, -56, -62, -67, -71, -76, -80, -84,
-88, -91, -94, -97, -100, -102, -103, -105, -106, -108, -108, -106, -104, -103,
-101, -99, -96, -95, -92, -91, -89, -86, -84, -82, -79, -75, -72, -69, -65, -60,
-56, -53, -48, -44, -40, -35, -30, -25, -19, -16, -10, -5, 1, 6, 11, 16, 21, 25,
29, 31, 34, 37, 39, 41, 42, 44, 45, 46, 48, 48, 49, 49, 50, 50, 52, 52, 52, 53,
53, 53, 53, 53, 54, 54, 54, 54, 53, 54, 54, 54, 54, 53, 53, 54, 54, 53, 53, 53,
53, 53, 53, 51, 52, 52, 51, 51, 51, 50, 50, 49, 49, 49, 49, 48, 47, 47, 46, 45,
45, 44, 45, 43, 42, 42, 41, 41, 41, 39, 39, 38, 37, 37, 37, 36, 35, 34, 33, 33,
32, 31, 30, 30, 29, 28, 26, 26, 26, 25, 23, 22, 22, 21, 20, 20, 18, 17, 17, 16,
15, 14, 12, 11, 10, 10, 8, 8, 6, 6, 6, 4, 3, 1, 1, 0, -1, -2, -2, -4, -4, -6,
-7, -9, -9, -11, -11, -12, -14, -15, -16, -18, -18, -20, -21, -22, -24, -25,
-27, -29, -29, -31, -33, -33, -35, -36, -38, -40, -42, -43, -43, -46, -46, -48,
-50, -52, -53, -53, -56, -56, -58, -59, -60, -61, -63, -64, -65, -66, -67, -69,
-69, -71, -71, -73, -72, -73, -74, -76, -75, -76, -77, -77, -77, -78, -79, -79,
-79, -80, -79, -80, -79, -79, -80, -80, -79, -79, -80, -79, -78, -78, -77, -77,
-76, -76, -75, -74, -73, -72, -71, -70, -68, -66, -66, -64, -63, -59, -58, -56,
-55, -52, -50, -49, -47, -45, -44, -41, -39, -37, -35, -33, -31, -29, -26, -25,
-22, -21, -18, -17, -15, -12, -11, -9, -6, -5, -4, -1, 1, 2, 4, 6, 8, 10, 11,
13, 15, 17, 18, 19, 21, 22, 24, 25, 27, 28, 30, 30, 32, 34, 35, 36, 37, 39, 40,
41, 42, 44, 45, 46, 46, 47, 48, 49, 50, 51, 53, 53, 54, 55, 56, 57, 57, 57, 59,
59, 60, 60, 61, 62, 62, 63, 63, 64, 65, 65, 66, 66, 66, 67, 66, 67, 67, 68, 68,
68, 68, 68, 69, 67, 68, 69, 68, 69, 68, 68, 68, 68, 68, 68, 67, 68, 67, 67, 66,
65, 66, 65, 64, 65, 64, 63, 63, 63, 63, 61, 61, 61, 60, 59, 58, 59, 57, 57, 55,
55, 55, 53, 53, 52, 51, 50, 49, 48, 49, 47, 46, 45, 44, 44, 42, 41, 40, 39, 38,
37, 36, 35, 34, 33, 32, 30, 30, 29, 27, 26, 25, 23, 23, 21, 20, 19, 18, 17, 15,
14, 12, 12, 11, 10, 9, 6, 5, 4, 3, 1, 0, -1, -1, -3, -5, -5, -6, -8, -8, -10,
-12, -13, -15, -15, -16, -17, -19, -20, -22, -23, -24, -26, -27, -28, -29, -32,
-33, -33, -35, -37, -38, -40, -41, -42, -44, -45, -46, -49, -50, -50, -52, -53,
-54, -57, -58, -58, -59, -61, -61, -63, -64, -64, -66, -68, -68, -68, -70, -71,
-72, -73, -73, -74, -75, -75, -75, -76, -77, -78, -78, -78, -78, -79, -78, -80,
-79, -79, -80, -80, -79, -78, -79, -79, -78, -78, -77, -77, -77, -76, -75, -75,
-74, -74, -73, -72, -71, -70, -68, -68, -67, -66, -65, -63, -62, -61, -60, -58,
-56, -56, -54, -53, -51, -49, -48, -46, -45, -43, -42, -39, -37, -36, -34, -32,
-30, -29, -27, -25, -23, -22, -20, -19, -17, -15, -13, -11, -10, -8, -6, -5, -4,
-2, 0, 1, 3, 4, 6, 8, 10, 11, 12, 13, 14, 16, 17, 18, 20, 21, 23, 24, 26, 26,
27, 28, 30, 31, 31, 33, 34, 35, 36, 37, 39, 40, 40, 41, 43, 43, 44, 45, 46, 47,
47, 48, 49, 50, 50, 51, 51, 52, 53, 53, 54, 54, 56, 57, 56, 57, 57, 59, 59, 60,
58, 59, 59, 60, 60, 61, 61, 61, 61, 61, 62, 62, 62, 62, 61, 61, 62, 62, 62, 62,
62, 62, 62, 62, 62, 62, 62, 62, 62, 61, 62, 62, 61, 61, 61, 60, 60, 59, 59, 58,
59, 58, 58, 56, 56, 56, 54, 54, 54, 53, 52, 52, 52, 51, 50, 49, 49, 47, 47, 46,
46, 45, 43, 43, 42, 40, 40, 39, 39, 37, 36, 35, 34, 33, 32, 31, 30, 30, 27, 27,
25, 25, 23, 22, 21, 20, 18, 17, 17, 15, 13, 12, 10, 10, 9, 7, 6, 5, 4, 3, 1, 0,
-2, -3, -4, -5, -7, -8, -9, -10, -12, -13, -14, -16, -16, -18, -19, -20, -21,
-23, -24, -25, -27, -28, -29, -30, -32, -33, -35, -36, -36, -38, -39, -40, -42,
-43, -44, -45, -47, -48, -49, -51, -52, -53, -54, -55, -57, -58, -59, -60, -61,
-63, -64, -65, -66, -66, -68, -68, -69, -70, -72, -73, -73, -73, -74, -74, -75,
-76, -76, -76, -78, -78, -78, -78, -78, -79, -79, -79, -78, -79, -78, -79, -79,
-79, -78, -78, -78, -77, -77, -76, -75, -76, -74, -75, -73, -72, -71, -71, -69,
-69, -68, -67, -65, -64, -63, -63, -61, -60, -58, -56, -55, -54, -52, -51, -50,
-47, -46, -45, -42, -42, -40, -38, -36, -35, -32, -31, -30, -28, -26, -24, -23,
-21, -19, -18, -17, -15, -13, -11, -10, -8, -6, -5, -3, -2, 0, 1, 2, 4, 5, 7, 8,
9, 11, 13, 13, 15, 17, 18, 19, 20, 21, 23, 24, 26, 26, 28, 28, 30, 30, 32, 33,
34, 35, 36, 37, 38, 39, 40, 41, 41, 42, 44, 45, 44, 46, 47, 48, 48, 49, 50, 51,
51, 51, 52, 53, 54, 55, 55, 55, 56, 56, 57, 57, 57, 58, 58, 59, 59, 60, 60, 61,
60, 60, 60, 60, 61, 61, 62, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 60, 60,
60, 60, 60, 59, 60, 59, 58, 58, 58, 57, 57, 56, 56, 55, 56, 54, 54, 54, 53, 53,
52, 51, 50, 50, 49, 48, 48, 47, 47, 45, 45, 44, 44, 43, 42, 40, 40, 39, 38, 37,
37, 36, 35, 34, 34, 31, 31, 30, 29, 28, 27, 26, 26, 25, 23, 21, 21, 20, 19, 18,
18, 16, 14, 13, 12, 11, 10, 9, 9, 7, 6, 4, 3, 3, 2, 1, -1, -2, -4, -5, -5, -7,
-7, -9, -9, -10, -12, -13, -14, -14, -15, -17, -18, -19, -20, -20, -22, -23,
-24, -25, -27, -28, -28, -29, -30, -32, -33, -34, -35, -36, -37, -38, -40, -41,
-42, -43, -44, -45, -47, -47, -49, -50, -50, -51, -52, -54, -55, -56, -56, -58,
-58, -59, -61, -61, -62, -63, -64, -64, -66, -66, -67, -68, -68, -68, -69, -69,
-70, -71, -72, -71, -71, -73, -73, -72, -73, -73, -73, -74, -73, -72, -73, -72,
-72, -73, -72, -72, -71, -70, -69, -71, -69, -68, -68, -67, -66, -66, -65, -64,
-63, -62, -60, -59, -58, -57, -56, -55, -54, -52, -51, -49, -48, -47, -45, -43,
-42, -41, -39, -37, -36, -35, -33, -31, -31, -28, -26, -25, -23, -22, -20, -18,
-18, -16, -15, -14, -12, -10, -9, -8, -6, -4, -3, -2, -1, 2, 2, 4, 5, 6, 8, 8,
10, 11, 13, 14, 15, 16, 17, 18, 19, 21, 23, 23, 25, 25, 27, 27, 29, 29, 30, 31,
33, 33, 34, 35, 35, 37, 38, 38, 40, 41, 41, 42, 42, 44, 44, 45, 46, 47, 47, 48,
48, 49, 50, 50, 51, 51, 52, 52, 53, 53, 53, 55, 54, 55, 55, 56, 55, 56, 57, 57,
56, 57, 57, 58, 58, 58, 57, 58, 57, 58, 58, 59, 58, 57, 57, 58, 57, 57, 57, 57,
56, 57, 57, 56, 57, 56, 56, 55, 55, 54, 54, 54, 53, 53, 52, 52, 52, 51, 50, 50,
50, 49, 48, 47, 47, 46, 45, 45, 44, 43, 42, 42, 41, 41, 40, 39, 38, 38, 36, 35,
35, 34, 33, 32, 32, 31, 30, 29, 27, 27, 26, 25, 24, 23, 23, 21, 20, 19, 18, 17,
16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 3, 3, 1, 0, -1, -1, -3, -3, -5, -6,
-7, -8, -9, -10, -11, -11, -13, -14, -14, -16, -16, -17, -19, -20, -20, -22,
-23, -23, -24, -25, -25, -28, -28, -29, -29, -31, -32, -33, -34, -35, -35, -37,
-38, -38, -39, -40, -41, -42, -43, -43, -45, -46, -46, -48, -49, -49, -50, -51,
-52, -52, -53, -54, -55, -56, -56, -57, -58, -59, -59, -59, -60, -60, -60, -61,
-62, -61, -62, -62, -63, -63, -63, -63, -64, -63, -63, -64, -64, -64, -64, -63,
-63, -63, -63, -63, -62, -61, -61, -61, -60, -60, -59, -58, -58, -58, -57, -56,
-56, -54, -53, -52, -52, -50, -50, -50, -48, -47, -46, -45, -44, -43, -42, -40,
-39, -38, -36, -35, -34, -33, -32, -31, -29, -27, -26, -25, -24, -22, -21, -19,
-18, -17, -15, -15, -13, -12, -11, -10, -9, -6, -6, -5, -3, -2, -1, 1, 1, 2, 4,
5, 6, 7, 8, 9, 11, 10, 12, 13, 14, 16, 16, 17, 18, 20, 21, 22, 22, 23, 24, 24,
26, 26, 28, 28, 29, 30, 31, 31, 33, 33, 34, 35, 36, 35, 37, 38, 38, 39, 39, 40,
40, 41, 42, 42, 43, 43, 44, 45, 46, 46, 47, 47, 48, 48, 48, 49, 50, 50, 51, 51,
51, 52, 52, 52, 52, 52, 53, 54, 53, 54, 55, 54, 55, 54, 54, 55, 54, 55, 54, 55,
55, 54, 55, 55, 54, 54, 54, 54, 54, 54, 53, 53, 53, 53, 53, 52, 52, 51, 51, 51,
50, 50, 50, 49, 48, 48, 47, 47, 47, 46, 45, 45, 43, 43, 43, 42, 42, 41, 40, 40,
39, 38, 38, 36, 36, 34, 33, 33, 32, 31, 30, 28, 27, 26, 26, 25, 24, 22, 22, 21,
21, 20, 18, 17, 16, 15, 14, 12, 12, 11, 10, 9, 7, 6, 5, 4, 4, 2, 2, 1, -1, -2,
-2, -3, -5, -6, -7, -8, -9, -10, -12, -12, -13, -15, -15, -16, -17, -18, -18,
-20, -22, -22, -22, -25, -25, -25, -26, -27, -28, -29, -30, -31, -31, -33, -34,
-35, -35, -36, -37, -38, -39, -40, -41, -41, -43, -43, -44, -46, -46, -46, -48,
-49, -49, -50, -50, -51, -52, -54, -54, -55, -55, -56, -57, -56, -57, -59, -58,
-60, -59, -60, -61, -61, -61, -62, -62, -63, -62, -63, -63, -63, -63, -63, -63,
-63, -62, -62, -63, -62, -62, -62, -61, -61, -60, -61, -59, -60, -58, -58, -57,
-57, -56, -55, -54, -55, -53, -53, -52, -51, -50, -49, -48, -47, -46, -45, -44,
-43, -41, -40, -39, -38, -37, -36, -35, -33, -32, -30, -29, -28, -27, -26, -24,
-23, -22, -21, -19, -19, -17, -16, -14, -13, -12, -11, -10, -9, -7, -6, -5, -4,
-2, -1, -1, 1, 2, 3, 4, 5, 6, 8, 8, 10, 10, 11, 13, 13, 15, 16, 17, 17, 19, 20,
20, 21, 23, 23, 24, 26, 26, 26, 27, 29, 30, 30, 31, 33, 32, 33, 34, 35, 35, 36,
37, 38, 38, 39, 40, 40, 41, 41, 42, 43, 43, 43, 43, 44, 44, 45, 45, 46, 47, 47,
47, 47, 48, 48, 48, 48, 49, 49, 49, 50, 49, 50, 50, 51, 50, 51, 50, 50, 51, 50,
51, 51, 51, 50, 50, 49, 50, 50, 50, 50, 50, 49, 49, 49, 48, 48, 48, 47, 47, 47,
46, 46, 46, 45, 45, 45, 44, 44, 43, 43, 42, 42, 41, 41, 40, 40, 40, 38, 37, 38,
36, 36, 35, 35, 35, 33, 33, 32, 31, 31, 30, 29, 28, 28, 27, 26, 25, 24, 23, 22,
22, 21, 20, 19, 19, 17, 16, 16, 15, 14, 13, 12, 12, 11, 10, 9, 8, 7, 5, 6, 4, 4,
3, 2, 1, 0, -1, -2, -3, -3, -4, -5, -7, -7, -8, -9, -11, -10, -12, -12, -12,
-13, -14, -15, -17, -18, -18, -20, -20, -21, -22, -23, -23, -23, -26, -26, -26,
-26, -28, -29, -29, -30, -31, -32, -33, -34, -34, -35, -36, -37, -38, -38, -39,
-40, -41, -41, -42, -42, -44, -44, -46, -45, -47, -47, -47, -48, -49, -50, -51,
-51, -51, -51, -52, -53, -54, -53, -54, -55, -56, -55, -56, -56, -57, -57, -57,
-57, -57, -57, -58, -57, -58, -56, -57, -57, -57, -57, -56, -56, -56, -56, -56,
-55, -54, -54, -54, -53, -52, -52, -51, -50, -50, -50, -49, -47, -46, -47, -45,
-44, -44, -42, -41, -40, -39, -38, -38, -36, -36, -34, -33, -31, -31, -30, -28,
-27, -26, -26, -24, -23, -21, -21, -19, -18, -17, -16, -14, -14, -13, -12, -11,
-10, -9, -8, -7, -5, -5, -4, -3, -1, 0, 2, 2, 3, 4, 6, 6, 7, 7, 9, 10, 11, 11,
13, 14, 14, 15, 17, 17, 18, 19, 20, 20, 22, 22, 23, 24, 24, 25, 27, 26, 28, 28,
30, 30, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 37, 36, 39, 38, 39, 39, 41, 41,
41, 41, 42, 42, 42, 43, 43, 44, 43, 43, 44, 45, 45, 44, 45, 46, 46, 46, 46, 46,
47, 45, 46, 46, 47, 46, 47, 47, 47, 46, 46, 47, 47, 46, 47, 46, 46, 46, 45, 45,
45, 45, 45, 44, 44, 44, 44, 44, 43, 43, 43, 42, 42, 41, 41, 40, 40, 39, 39, 38,
38, 37, 37, 36, 36, 35, 35, 34, 33, 33, 32, 31, 31, 31, 30, 30, 29, 27, 26, 27,
26, 25, 23, 24, 23, 22, 21, 20, 19, 18, 18, 18, 16, 15, 14, 15, 13, 12, 11, 11,
10, 9, 9, 7, 7, 6, 5, 5, 4, 2, 1, 1, 0, -1, -1, -3, -3, -4, -5, -5, -6, -8, -9,
-9, -9, -11, -12, -11, -13, -13, -14, -15, -16, -16, -17, -18, -19, -20, -21,
-21, -22, -23, -23, -24, -24, -25, -26, -27, -26, -28, -28, -29, -29, -30, -31,
-32, -32, -33, -34, -34, -35, -36, -36, -36, -38, -38, -38, -39, -40, -40, -41,
-41, -42, -42, -42, -43, -44, -44, -45, -45, -46, -46, -47, -46, -47, -48, -47,
-47, -48, -48, -48, -48, -49, -48, -49, -49, -48, -48, -49, -48, -48, -48, -48,
-49, -48, -48, -47, -46, -47, -46, -45, -46, -45, -45, -45, -44, -42, -43, -42,
-41, -41, -41, -39, -39, -38, -38, -37, -36, -35, -34, -33, -32, -32, -31, -30,
-29, -28, -27, -27, -26, -24, -24, -22, -22, -21, -19, -19, -18, -17, -15, -15,
-15, -13, -12, -11, -10, -11, -9, -8, -7, -6, -6, -4, -4, -2, -1, -1, 0, 1, 2,
3, 3, 4, 5, 6, 6, 8, 8, 9, 10, 11, 12, 12, 13, 14, 14, 15, 16, 17, 18, 19, 19,
20, 21, 22, 21, 22, 23, 24, 24, 24, 25, 26, 26, 27, 29, 29, 30, 30, 31, 30, 32,
32, 32, 33, 33, 34, 35, 35, 36, 36, 37, 37, 37, 38, 38, 39, 39, 40, 40, 40, 40,
40, 41, 41, 41, 41, 42, 42, 42, 42, 42, 43, 43, 43, 43, 43, 44, 44, 44, 44, 44,
43, 43, 44, 43, 44, 44, 43, 44, 44, 43, 43, 43, 43, 43, 43, 42, 41, 41, 41, 41,
41, 41, 39, 40, 40, 39, 39, 38, 38, 37, 37, 36, 36, 35, 35, 34, 33, 33, 32, 31,
31, 31, 30, 29, 28, 27, 27, 25, 25, 25, 23, 24, 23, 22, 21, 20, 20, 18, 18, 17,
17, 16, 14, 14, 14, 13, 12, 11, 11, 9, 9, 8, 7, 6, 5, 4, 3, 3, 2, 2, 1, 0, -1,
-2, -2, -4, -4, -5, -5, -7, -8, -8, -8, -10, -11, -11, -13, -13, -14, -15, -15,
-16, -17, -18, -18, -19, -20, -20, -21, -21, -23, -23, -24, -24, -24, -26, -26,
-26, -28, -28, -29, -29, -30, -30, -30, -32, -32, -33, -34, -34, -34, -35, -36,
-37, -37, -37, -38, -38, -39, -39, -40, -40, -41, -42, -42, -42, -43, -43, -44,
-44, -44, -44, -45, -44, -46, -46, -46, -46, -46, -47, -46, -46, -47, -47, -47,
-47, -46, -47, -47, -47, -46, -46, -46, -45, -46, -46, -46, -45, -45, -44, -44,
-44, -44, -43, -42, -42, -41, -41, -40, -39, -39, -38, -38, -37, -36, -36, -35,
-34, -33, -32, -32, -31, -30, -28, -28, -27, -27, -25, -25, -24, -24, -23, -21,
-20, -20, -19, -18, -17, -16, -15, -15, -13, -13, -11, -11, -10, -10, -7, -7,
-7, -5, -5, -4, -4, -2, -2, -1, 0, 1, 3, 3, 4, 4, 4, 6, 7, 8, 8, 9, 10, 11, 11,
12, 13, 13, 14, 14, 16, 16, 17, 17, 19, 20, 20, 20, 21, 21, 22, 24, 24, 25, 24,
25, 25, 26, 26, 28, 29, 29, 29, 29, 29, 30, 31, 31, 32, 32, 33, 32, 34, 34, 34,
35, 35, 35, 35, 36, 35, 36, 36, 36, 37, 38, 37, 37, 38, 38, 39, 38, 38, 38, 38,
38, 39, 38, 39, 39, 38, 39, 39, 39, 39, 38, 39, 39, 39, 38, 38, 38, 38, 37, 37,
37, 36, 37, 36, 36, 36, 35, 35, 36, 35, 34, 34, 34, 34, 34, 33, 33, 32, 32, 30,
30, 30, 30, 29, 28, 29, 28, 28, 27, 27, 25, 25, 24, 24, 23, 23, 23, 21, 21, 21,
20, 20, 20, 19, 18, 17, 17, 16, 16, 14, 14, 13, 12, 13, 11, 11, 10, 9, 9, 8, 8,
7, 7, 6, 5, 5, 3, 2, 2, 1, 1, 0, 0, -2, -2, -3, -5, -4, -5, -5, -6, -7, -7, -8,
-9, -10, -10, -11, -12, -12, -13, -13, -14, -15, -14, -16, -16, -18, -18, -18,
-20, -20, -20, -21, -22, -23, -23, -23, -23, -24, -25, -25, -26, -26, -27, -27,
-27, -28, -29, -29, -29, -30, -30, -31, -32, -32, -32, -33, -34, -35, -34, -35,
-35, -37, -36, -37, -37, -37, -38, -38, -38, -38, -39, -40, -39, -41, -40, -40,
-41, -41, -41, -41, -42, -41, -42, -42, -42, -41, -42, -42, -42, -41, -42, -41,
-41, -41, -41, -41, -40, -41, -39, -40, -39, -38, -38, -38, -37, -37, -36, -36,
-36, -35, -35, -34, -33, -32, -32, -31, -30, -29, -29, -28, -28, -27, -26, -25,
-25, -23, -24, -23, -22, -21, -19, -19, -19, -17, -18, -16, -15, -15, -14, -13,
-13, -11, -10, -11, -9, -9, -7, -7, -5, -5, -5, -4, -3, -3, -2, -2, -1, 1, 2, 2,
3, 3, 4, 4, 5, 6, 8, 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 13, 14, 14, 16, 16,
18, 17, 18, 18, 19, 19, 20, 21, 21, 22, 22, 22, 23, 24, 25, 24, 25, 25, 26, 27,
27, 27, 27, 28, 28, 28, 29, 29, 30, 29, 30, 31, 31, 31, 31, 32, 31, 32, 31, 32,
33, 33, 32, 33, 33, 32, 34, 33, 34, 34, 33, 34, 34, 34, 33, 34, 34, 34, 34, 33,
33, 34, 33, 34, 33, 33, 34, 33, 33, 32, 33, 32, 32, 31, 31, 31, 31, 31, 31, 30,
30, 30, 29, 29, 28, 29, 27, 28, 27, 28, 26, 26, 26, 26, 24, 25, 24, 23, 23, 23,
22, 22, 22, 22, 20, 20, 20, 19, 19, 17, 17, 16, 16, 16, 16, 15, 14, 14, 13, 12,
12, 11, 12, 10, 9, 9, 9, 8, 7, 7, 6, 6, 5, 4, 4, 4, 3, 2, 1, 0, 0, 0, -1, -1,
-2, -2, -3, -4, -4, -5, -5, -6, -6, -8, -7, -7, -9, -10, -10, -10, -11, -11,
-12, -13, -13, -13, -14, -14, -16, -15, -16, -16, -16, -17, -18, -17, -18, -19,
-19, -19, -20, -20, -21, -21, -22, -22, -23, -23, -23, -24, -24, -25, -24, -25,
-26, -26, -27, -27, -27, -27, -27, -27, -29, -28, -28, -29, -29, -30, -29, -30,
-30, -31, -30, -31, -30, -30, -32, -31, -32, -31, -31, -32, -32, -31, -32, -32,
-32, -32, -32, -31, -32, -32, -32, -31, -31, -31, -31, -30, -31, -31, -30, -30,
-30, -30, -29, -29, -28, -28, -28, -27, -27, -28, -26, -25, -25, -25, -24, -24,
-23, -24, -23, -21, -22, -21, -21, -20, -20, -18, -19, -18, -17, -16, -16, -16,
-15, -14, -14, -13, -12, -12, -11, -11, -10, -10, -9, -8, -7, -7, -7, -6, -6,
-5, -4, -3, -4, -2, -2, -1, -1, -1, -1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7,
7, 8, 8, 9, 9, 11, 10, 11, 10, 13, 13, 12, 13, 13, 14, 15, 14, 16, 16, 16, 16,
17, 17, 18, 18, 18, 19, 20, 19, 20, 19, 19, 20, 22, 21, 22, 22, 22, 22, 23, 23,
23, 23, 24, 24, 23, 25, 24, 24, 25, 25, 25, 26, 24, 25, 26, 25, 25, 26, 26, 25,
26, 26, 25, 25, 27, 26, 25, 26, 26, 26, 26, 26, 25, 25, 25, 26, 25, 25, 25, 25,
24, 25, 25, 24, 24, 24, 24, 24, 24, 24, 23, 24, 23, 22, 22, 22, 22, 22, 22, 21,
21, 21, 20, 20, 19, 19, 18, 19, 18, 17, 17, 17, 18, 16, 16, 15, 15, 15, 14, 14,
14, 14, 13, 13, 12, 12, 11, 11, 11, 10, 10, 8, 9, 9, 9, 8, 8, 7, 6, 6, 6, 5, 5,
4, 3, 2, 2, 2, 1, 2, 1, 1, 0, 0, 0, -2, -2, -2, -3, -3, -4, -4, -5, -6, -5, -5,
-6, -7, -7, -7, -7, -9, -9, -9, -9, -9, -10, -11, -11, -11, -12, -12, -12, -13,
-13, -14, -14, -14, -14, -15, -15, -16, -17, -16, -16, -17, -18, -17, -17, -18,
-18, -19, -18, -19, -19, -20, -20, -20, -20, -21, -21, -21, -22, -21, -21, -22,
-22, -22, -22, -22, -23, -23, -24, -23, -24, -23, -23, -24, -24, -25, -24, -24,
-25, -25, -25, -24, -25, -24, -25, -24, -24, -25, -23, -24, -24, -23, -24, -24,
-24, -24, -24, -24, -23, -22, -22, -22, -23, -22, -22, -21, -21, -21, -20, -20,
-21, -19, -20, -19, -18, -19, -17, -18, -17, -17, -17, -16, -16, -15, -15, -14,
-14, -14, -13, -13, -12, -12, -11, -11, -10, -10, -10, -10, -9, -8, -8, -8, -7,
-6, -7, -5, -5, -5, -5, -4, -3, -3, -3, -3, -2, -2, -1, 0, 0, 0, 0, 1, 1, 2, 2,
3, 3, 3, 4, 5, 5, 5, 5, 6, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 10, 10, 11, 11, 11, 12,
12, 12, 13, 13, 14, 13, 14, 14, 15, 14, 15, 15, 15, 16, 15, 16, 16, 17, 17, 17,
17, 17, 18, 17, 17, 17, 19, 18, 18, 18, 18, 19, 19, 20, 19, 20, 19, 19, 20, 19,
20, 19, 20, 20, 21, 19, 20, 20, 20, 20, 20, 21, 20, 20, 20, 20, 20, 20, 20, 20,
19, 19, 20, 20, 19, 19, 19, 19, 18, 19, 19, 18, 19, 18, 18, 17, 18, 18, 17, 17,
17, 17, 16, 16, 16, 15, 16, 16, 14, 16, 15, 14, 14, 13, 14, 13, 12, 13, 13, 12,
11, 12, 12, 11, 11, 11, 10, 10, 10, 8, 8, 8, 8, 7, 8, 7, 7, 7, 6, 6, 6, 5, 5, 4,
3, 3, 3, 3, 3, 2, 2, 1, 1, 1, 0, 0, 0, -1, 0, 0, -2, -2, -3, -2, -3, -3, -3, -4,
-4, -4, -5, -5, -6, -6, -6, -6, -6, -6, -7, -7, -8, -8, -8, -8, -9, -9, -10,
-10, -10, -10, -11, -12, -11, -11, -11, -12, -12, -13, -13, -13, -13, -13, -14,
-14, -14, -14, -14, -15, -15, -15, -15, -15, -16, -16, -16, -16, -16, -17, -17,
-17, -17, -17, -17, -17, -17, -18, -17, -18, -18, -18, -18, -18, -18, -18, -19,
-18, -18, -18, -18, -19, -19, -18, -18, -18, -18, -19, -18, -18, -19, -19, -18,
-18, -18, -19, -18, -18, -17, -17, -17, -17, -16, -16, -16, -17, -16, -16, -15,
-16, -16, -15, -14, -15, -14, -14, -14, -13, -13, -13, -13, -12, -12, -11, -11,
-11, -11, -11, -10, -11, -10, -10, -8, -9, -9, -8, -8, -6, -7, -8, -6, -7, -5,
-6, -5, -5, -4, -4, -3, -3, -3, -3, -3, -2, -2, -1, -1, -1, 0, 0, -1, 0, 0, 1,
1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 4, 5, 5, 5, 6, 6, 6, 6, 7, 8, 7, 8, 8, 9, 9, 9,
10, 10, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13,
12, 13, 13, 14, 13, 13, 13, 13, 14, 14, 13, 14, 14, 14, 15, 14, 15, 15, 15, 15,
15, 15, 14, 15, 15, 15, 14, 15, 15, 16, 15, 15, 15, 15, 15, 15, 15, 14, 15, 15,
15, 15, 15, 14, 14, 14, 14, 14, 14, 14, 13, 14, 13, 14, 13, 14, 12, 12, 12, 12,
12, 13, 12, 12, 12, 11, 12, 12, 11, 11, 11, 10, 10, 10, 10, 10, 10, 9, 9, 8, 8,
9, 9, 9, 8, 8, 7, 7, 7, 6, 7, 6, 6, 6, 6, 6, 5, 5, 5, 5, 4, 5, 4, 3, 3, 3, 3, 2,
2, 2, 2, 1, 1, 2, 1, 1, 0, -1, -1, -1, 0, -1, -2, -2, -3, -3, -2, -2, -2, -3,
-3, -4, -3, -4, -4, -5, -5, -5, -6, -6, -5, -6, -6, -6, -8, -8, -7, -7, -8, -7,
-9, -8, -8, -9, -8, -9, -9, -9, -9, -10, -9, -10, -10, -10, -10, -10, -11, -10,
-10, -10, -11, -11, -12, -12, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12,
-13, -13, -12, -13, -13, -12, -13, -13, -13, -13, -13, -13, -13, -14, -13, -14,
-13, -13, -13, -12, -14, -13, -13, -13, -14, -13, -14, -13, -13, -13, -13, -13,
-13, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -12, -11, -11, -11, -10,
-10, -10, -10, -10, -10, -9, -9, -10, -9, -9, -9, -9, -8, -8, -8, -7, -7, -7,
-7, -6, -7, -7, -6, -5, -5, -5, -5, -5, -5, -5, -4, -4, -3, -3, -3, -3, -2, -3,
-2, -1, -2, -1, -1, -1, 0, 0, -1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 2, 2, 2, 3, 4,
3, 4, 3, 4, 5, 4, 4, 5, 5, 5, 5, 6, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 7, 7,
8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 11,
10, 10, 10, 11, 10, 10, 11, 10, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 10, 11,
10, 11, 10, 11, 11, 11, 10, 11, 10, 11, 11, 10, 11, 10, 10, 10, 10, 10, 9, 10,
9, 10, 10, 10, 10, 9, 9, 10, 9, 9, 8, 8, 9, 8, 8, 7, 8, 8, 8, 8, 7, 7, 7, 7, 8,
7, 7, 7, 6, 6, 5, 6, 6, 5, 6, 5, 5, 4, 4, 4, 4, 4, 5, 4, 4, 3, 3, 3, 2, 3, 2, 2,
2, 2, 1, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, -1, 0, 0, -1, -1, -1, -2, -1, -2, -2, -3,
-3, -2, -2, -2, -3, -3, -3, -4, -3, -5, -4, -4, -4, -5, -4, -5, -5, -6, -4, -6,
-5, -5, -6, -6, -6, -7, -6, -7, -6, -6, -7, -7, -7, -7, -7, -6, -8, -7, -7, -7,
-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -9, -9, -9, -9, -8, -9, -9, -8, -8, -9,
-9, -9, -9, -9, -9, -10, -9, -10, -8, -9, -9, -9, -10, -9, -9, -9, -8, -9, -10,
-9, -9, -9, -9, -9, -9, -8, -10, -9, -8, -8, -8, -8, -8, -9, -8, -8, -8, -8, -8,
-8, -8, -7, -7, -8, -7, -7, -7, -7, -7, -7, -7, -6, -7, -6, -6, -6, -6, -5, -5,
-5, -5, -5, -4, -4, -4, -4, -4, -4, -4, -3, -3, -4, -3, -3, -3, -3, -2, -2, -3,
-2, -2, -2, -1, -1, -1, -1, -1, -1, 0, -1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
2, 2, 1, 1, 1, 1, 2, 3, 3, 2, 3, 4, 3, 3, 3, 4, 3, 4, 4, 5, 4, 4, 4, 5, 4, 5, 5,
4, 6, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 7,
6, 7, 7, 8, 7, 7, 8, 7, 7, 7, 7, 8, 7, 8, 8, 7, 7, 7, 8, 8, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 6, 6, 6, 6, 6, 5, 6, 6,
6, 6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 4, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3,
2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
-1, 0, -1, 0, -1, -1, -2, -1, -1, -2, -2, -2, -2, -3, -2, -2, -3, -2, -2, -3,
-2, -2, -3, -2, -3, -3, -3, -3, -4, -4, -3, -4, -4, -5, -4, -4, -4, -4, -4, -4,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -6, -6, -6, -6,
-6, -5, -6, -6, -6, -6, -5, -5, -6, -6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -7,
-6, -6, -7, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -7, -6, -6, -6,
-5, -6, -5, -5, -5, -5, -5, -5, -5, -5, -5, -4, -5, -5, -4, -5, -5, -4, -4, -4,
-4, -5, -4, -4, -4, -4, -5, -3, -3, -3, -3, -4, -4, -3, -3, -3, -3, -3, -2, -2,
-3, -2, -2, -3, -2, -2, -2, -2, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, 0, -1,
-1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 2, 1, 2, 2, 1, 2, 2, 2, 2, 3,
2, 3, 3, 3, 2, 3, 3, 3, 3, 3, 2, 3, 4, 3, 4, 3, 4, 4, 4, 3, 3, 4, 4, 4, 3, 4, 4,
3, 4, 3, 4, 4, 4, 4, 5, 5, 5, 4, 4, 4, 5, 4, 5, 5, 5, 4, 4, 5, 5, 5, 5, 5, 5, 5,
4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 5, 5, 4, 5, 5, 4, 5, 4, 5, 4, 5, 5, 4,
4, 4, 4, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 3, 4, 3, 3, 3, 4, 4, 3, 3, 4, 3, 3,
3, 3, 2, 3, 3, 3, 2, 2, 3, 2, 3, 1, 3, 2, 2, 2, 2, 2, 2, 1, 1, 2, 0, 1, 0, 1, 1,
1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -2, -1, -1, -2, -2, -1, -1, -2, -2, -2, -1, -3, -1, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -4, -3, -3, -3, -3, -4, -4, -4, -3, -4,
-4, -4, -4, -3, -3, -4, -4, -4, -3, -3, -4, -4, -4, -3, -3, -3, -4, -4, -3, -4,
-4, -4, -3, -4, -4, -4, -4, -4, -4, -4, -4, -3, -4, -4, -4, -3, -4, -4, -4, -4,
-4, -3, -4, -4, -3, -4, -4, -4, -4, -3, -3, -3, -4, -3, -3, -3, -4, -3, -2, -2,
-3, -2, -3, -3, -3, -3, -3, -3, -2, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2,
-3, -2, -1, -1, -2, -1, -1, -2, -1, -1, -2, -1, -1, -2, -1, -2, 0, -1, -1, -1,
-1, -1, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
0, 1, 1, 1, 0, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 3, 3, 2, 2, 3, 2, 3, 3, 2, 3, 2, 2,
2, 2, 2, 3, 2, 3, 3, 3, 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3,
2, 3, 3, 3, 3, 2, 3, 3, 3, 2, 3, 3, 2, 3, 1, 3, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 2, 1, 2, 0, 2, 1, 1, 1, 1, 1, 2, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0,
-1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, -1, -1, -1, 0,
-1, 0, -1, -2, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -2, -1, -2, -2, -2,
-1, -3, -2, -2, -2, -1, -2, -2, -1, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1,
-2, -2, -3, -2, -2, -2, -1, -2, -2, -2, -2, -1, -2, -2, -2, -2, -1, -1, -2, -2,
-2, -2, -2, -1, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2, -2, -2, -1, -1, -2,
-2, -2, -2, -2, -1, -2, -2, -1, -2, -1, -1, -1, -1, -1, -2, -2, -1, -2, -1, -1,
0, -1, -1, -1, -1, -1, -2, 0, -1, -1, -2, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1,
-1, -1, 0, -1, -1, 0, -1, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 1,
1, 0, -1, 0, 0, -1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0,
1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1,
1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
2, 1, 1, 0, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 2, 1,
1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0,
0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
0, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, -1, -1, 0, -1, 0, -1, -1,
0, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, 0, 0, -1, -1, 0, 0, 0, -1, -1, -1,
-1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, 0,
-1, -1, 0, -1, 0, -1, 0, -1, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, -1, 0,
-2, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, -1, -1, 0, -1,
-1, -1, -1, 0, 0, 0, 0, -1, -1, 0, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, 0, -1,
-1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
1, 1, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1,
0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0,
0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0,
1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, -1,
0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0,
0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 1, 0, 0, 0,
0, 0, -1, -1, 1, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0,
0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, -1, 0, 1, -1, -1, -1, 0, 0, 0, 0, -1, 1,
0, 0, -1, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1, -1, 0, -1,
0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0,
-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -1, 0, 0, 0, 1, 0, 0, 0, 0, -1,
-1, -1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, -1, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0,
1, 1, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0,
-1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, -1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, -1, 0,
0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0,
-1, 0, 1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 1, 0, 0, 0,
1, -1, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 1, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 1, -1, 0, 0, 0, 0, 0, -1, 0,
-1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, -1, 0, 0, 0,
1, 0, 0, 0, -1, -1, 0, 0, 1, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
0, 0, -1, 1, 1, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1, -1, -1, 0, 0, 0,
0, 0, 0, 0, -1, -1, 0, 0, 0, 1, -1, 1, -1, 0, 0, 0, -1, 0, 0, 1, 1, 0, 1, 0, 0,
0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 1, 0, 0,
0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, -1,
0, 1, -1, 0, -1, -1, 0, 0, 1, -1, -1, 0, 0, -1, 1, 1, 0, 0, 1, 0, 0, 0, 0, -1,
0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, -1, 0, 1, 0, 0, 0, -1, 0, 1, 0, -1, 0, 0, 0,
-1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, -1, 0, -1, 1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, -1, 0,
0, 0, 0, 1, 0, 0, 1, 0, 0, 0, -1, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0,
0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,
0, 1, -1, 0, -1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1,
0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 1, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
1, -1, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, -1, -1, 0, 1, 0, 0, -1, 1, 0, -1, 0,
-1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 1, 0,
-1, 1, 0, 1, 0, 1, 1, 0, 0, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 1, 0, 1, 1, 0, 0, 0, -1, 0, 0, 0, -1,
0, -1, 0, -1, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, -1, 0, 1, 0, 1, 0, 0,
-1, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, -1,
-1, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0,
0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
0, 1, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, 1, -1, 0, 0,
0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, -1,
0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 1, 0, 0, 0,
0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, -1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
0, 1, 1, -1, 1, 0, -1, 1, 1, -1, 0, 1, 0, 0, 1, 0, };

#endif /* kick_H_ */
