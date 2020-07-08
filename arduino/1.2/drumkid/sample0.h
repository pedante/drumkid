#ifndef sample0_H_
#define sample0_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "src/MozziDK/src/mozzi_pgmspace.h"
 
#define sample0_NUM_CELLS 7581
#define sample0_SAMPLERATE 16384
 
CONSTTABLE_STORAGE(int8_t) sample0_DATA [] = {0, 2, 18, 33, 44, 53, 62, 69, 75,
81, 85, 89, 93, 97, 98, 100, 101, 102, 97, 94, 88, 84, 78, 72, 65, 58, 51, 44,
36, 29, 22, 13, 7, 0, -8, -15, -23, -30, -37, -44, -51, -58, -65, -71, -77, -82,
-88, -94, -98, -104, -107, -113, -117, -119, -123, -126, -128, -128, -127, -128,
-127, -127, -126, -125, -125, -124, -123, -122, -121, -119, -116, -114, -111,
-108, -105, -101, -97, -93, -88, -84, -80, -74, -69, -64, -58, -52, -46, -41,
-34, -28, -21, -15, -10, -4, 1, 5, 10, 14, 17, 21, 25, 26, 30, 32, 34, 38, 40,
41, 43, 45, 47, 49, 51, 52, 54, 55, 57, 58, 59, 59, 61, 62, 63, 64, 65, 65, 67,
67, 68, 69, 69, 70, 70, 71, 71, 71, 73, 72, 73, 74, 73, 74, 74, 74, 73, 73, 74,
74, 73, 73, 73, 73, 73, 72, 72, 72, 72, 72, 71, 70, 70, 69, 69, 67, 67, 67, 67,
65, 65, 64, 64, 63, 62, 61, 59, 59, 58, 57, 56, 55, 55, 53, 51, 51, 50, 49, 48,
47, 45, 43, 43, 42, 41, 38, 39, 36, 35, 34, 33, 31, 30, 29, 27, 26, 25, 23, 22,
20, 19, 18, 15, 14, 13, 11, 9, 8, 6, 5, 3, 1, 0, -1, -4, -5, -7, -9, -12, -13,
-16, -17, -20, -21, -23, -26, -28, -29, -32, -33, -36, -39, -40, -43, -44, -46,
-50, -52, -54, -56, -58, -61, -63, -65, -67, -69, -72, -73, -76, -78, -80, -82,
-84, -86, -89, -90, -92, -95, -96, -98, -99, -101, -103, -105, -106, -107, -109,
-110, -112, -113, -114, -115, -115, -116, -117, -119, -118, -120, -120, -121,
-121, -122, -121, -122, -121, -122, -122, -122, -122, -121, -121, -119, -120,
-119, -118, -117, -116, -114, -113, -112, -109, -109, -106, -105, -102, -101,
-99, -97, -95, -92, -90, -87, -85, -82, -80, -77, -75, -72, -69, -67, -64, -60,
-58, -55, -53, -50, -47, -45, -41, -40, -36, -34, -31, -28, -25, -22, -20, -17,
-14, -12, -9, -6, -4, -1, 1, 4, 7, 10, 11, 14, 16, 18, 21, 23, 26, 28, 31, 33,
35, 37, 40, 41, 44, 46, 47, 50, 52, 54, 55, 57, 59, 62, 64, 65, 67, 68, 70, 72,
73, 75, 77, 78, 79, 82, 82, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 96, 97,
98, 98, 99, 100, 101, 102, 102, 103, 103, 104, 104, 105, 105, 106, 105, 106,
106, 107, 106, 107, 107, 107, 107, 106, 107, 106, 106, 106, 107, 105, 105, 105,
105, 104, 103, 103, 103, 102, 100, 100, 100, 99, 98, 98, 96, 96, 95, 94, 93, 92,
91, 90, 89, 87, 87, 86, 84, 83, 81, 80, 79, 77, 77, 75, 73, 71, 70, 68, 67, 65,
64, 62, 60, 60, 57, 56, 54, 52, 51, 49, 48, 46, 43, 41, 39, 38, 36, 35, 32, 30,
29, 26, 25, 23, 21, 19, 17, 14, 13, 11, 9, 7, 5, 3, 2, -1, -2, -4, -6, -9, -12,
-13, -15, -18, -20, -22, -24, -27, -29, -31, -32, -35, -37, -40, -42, -44, -47,
-49, -51, -54, -56, -58, -60, -62, -64, -67, -69, -71, -73, -76, -77, -79, -81,
-83, -85, -88, -90, -91, -94, -95, -96, -98, -100, -102, -103, -105, -106, -108,
-108, -110, -111, -113, -114, -115, -115, -117, -117, -117, -118, -119, -120,
-120, -120, -121, -121, -120, -121, -121, -120, -121, -120, -120, -120, -120,
-119, -119, -118, -118, -117, -116, -115, -114, -113, -112, -111, -109, -107,
-106, -105, -103, -101, -100, -99, -96, -95, -93, -91, -89, -87, -85, -82, -81,
-78, -76, -73, -71, -69, -67, -64, -62, -59, -57, -54, -52, -49, -47, -45, -42,
-39, -38, -35, -33, -30, -28, -25, -23, -20, -18, -16, -13, -11, -9, -7, -4, -2,
1, 3, 5, 7, 9, 12, 14, 16, 18, 20, 23, 24, 26, 29, 30, 33, 35, 36, 38, 40, 41,
44, 46, 47, 49, 50, 53, 55, 57, 57, 59, 60, 62, 64, 66, 67, 68, 69, 71, 72, 74,
75, 76, 77, 78, 79, 80, 82, 82, 83, 85, 85, 86, 88, 88, 88, 90, 91, 91, 92, 91,
93, 93, 94, 95, 95, 96, 96, 96, 97, 98, 97, 98, 98, 99, 99, 98, 99, 99, 98, 99,
98, 98, 98, 99, 97, 98, 97, 97, 98, 97, 97, 96, 94, 95, 94, 94, 94, 92, 92, 91,
90, 90, 88, 87, 87, 85, 85, 85, 83, 81, 81, 79, 78, 77, 76, 75, 74, 72, 70, 69,
68, 67, 65, 65, 62, 61, 59, 59, 57, 55, 53, 52, 51, 49, 46, 44, 43, 41, 39, 37,
36, 34, 32, 30, 29, 26, 24, 22, 20, 18, 16, 15, 13, 10, 9, 6, 4, 2, 1, -2, -3,
-5, -7, -9, -11, -13, -15, -17, -19, -21, -23, -25, -28, -29, -32, -34, -36,
-38, -40, -42, -45, -46, -49, -50, -53, -56, -57, -59, -62, -64, -66, -69, -71,
-72, -74, -76, -78, -80, -82, -85, -86, -88, -89, -91, -94, -95, -97, -99, -100,
-101, -103, -105, -106, -107, -108, -110, -110, -112, -113, -114, -115, -116,
-117, -117, -117, -119, -120, -120, -120, -120, -121, -121, -122, -121, -121,
-121, -121, -121, -120, -120, -121, -119, -119, -118, -117, -116, -116, -114,
-113, -112, -112, -110, -109, -107, -106, -105, -103, -102, -101, -97, -97, -95,
-93, -90, -90, -87, -85, -83, -81, -79, -77, -74, -72, -69, -68, -66, -64, -61,
-59, -57, -54, -52, -49, -47, -44, -41, -40, -37, -35, -33, -30, -28, -26, -22,
-20, -18, -16, -14, -12, -9, -7, -5, -3, -1, 1, 3, 6, 9, 10, 13, 14, 17, 19, 21,
22, 25, 27, 29, 31, 33, 35, 36, 39, 40, 42, 44, 46, 47, 48, 50, 53, 54, 56, 57,
59, 60, 62, 63, 65, 66, 67, 69, 71, 72, 72, 74, 75, 77, 78, 78, 80, 81, 81, 83,
84, 85, 86, 86, 88, 88, 89, 89, 90, 91, 91, 92, 92, 93, 93, 94, 93, 94, 95, 95,
94, 95, 96, 96, 96, 96, 97, 97, 97, 96, 95, 96, 95, 95, 95, 94, 94, 94, 94, 93,
92, 92, 92, 91, 90, 90, 89, 88, 88, 88, 86, 86, 85, 84, 83, 82, 82, 80, 79, 78,
77, 76, 75, 74, 72, 71, 70, 69, 68, 66, 65, 64, 63, 62, 59, 58, 57, 55, 54, 53,
51, 49, 48, 46, 45, 44, 42, 40, 39, 37, 35, 33, 31, 30, 29, 27, 25, 23, 21, 21,
18, 17, 15, 13, 12, 10, 8, 6, 5, 2, 1, -1, -2, -4, -6, -8, -9, -10, -13, -14,
-17, -18, -20, -22, -23, -26, -28, -29, -30, -32, -35, -36, -38, -41, -42, -44,
-46, -48, -49, -52, -53, -55, -57, -59, -61, -63, -64, -67, -68, -71, -72, -73,
-76, -77, -79, -81, -82, -84, -85, -87, -89, -90, -92, -93, -94, -95, -97, -98,
-99, -101, -102, -102, -104, -105, -106, -108, -108, -109, -109, -110, -110,
-112, -111, -112, -113, -112, -113, -113, -113, -113, -113, -113, -113, -113,
-112, -112, -111, -111, -109, -109, -109, -107, -107, -105, -105, -103, -103,
-101, -99, -99, -97, -96, -93, -92, -90, -89, -87, -86, -84, -81, -80, -78, -76,
-75, -72, -70, -68, -66, -64, -63, -60, -58, -56, -53, -52, -49, -47, -45, -44,
-40, -39, -36, -34, -32, -30, -28, -26, -23, -22, -19, -18, -15, -14, -11, -9,
-6, -5, -3, -1, 2, 3, 5, 7, 9, 12, 14, 15, 18, 19, 21, 23, 25, 26, 29, 30, 32,
34, 35, 37, 39, 41, 43, 44, 45, 48, 48, 50, 52, 53, 55, 56, 58, 59, 60, 62, 63,
64, 66, 67, 68, 69, 71, 72, 72, 74, 74, 76, 77, 78, 79, 80, 80, 81, 82, 83, 84,
84, 85, 86, 86, 86, 88, 88, 87, 88, 89, 90, 90, 90, 90, 90, 90, 90, 91, 91, 91,
91, 90, 91, 91, 91, 91, 90, 90, 90, 89, 90, 89, 88, 89, 88, 87, 87, 86, 86, 86,
84, 84, 83, 82, 82, 81, 81, 79, 79, 77, 77, 76, 76, 73, 73, 72, 71, 70, 68, 67,
67, 65, 64, 64, 62, 60, 59, 57, 56, 56, 55, 53, 52, 50, 48, 47, 46, 44, 43, 42,
40, 39, 36, 35, 34, 32, 30, 29, 27, 26, 24, 23, 21, 20, 18, 16, 14, 12, 11, 9,
7, 7, 5, 3, 1, 0, -2, -3, -5, -7, -8, -10, -12, -13, -14, -17, -19, -20, -21,
-23, -24, -26, -27, -29, -31, -33, -34, -36, -38, -40, -41, -42, -44, -46, -48,
-49, -51, -52, -54, -55, -57, -59, -60, -62, -64, -65, -67, -68, -69, -70, -72,
-74, -75, -75, -78, -79, -79, -81, -82, -84, -85, -86, -87, -88, -90, -91, -91,
-92, -92, -93, -94, -94, -95, -95, -96, -97, -97, -97, -97, -97, -98, -98, -98,
-98, -98, -98, -98, -98, -98, -98, -97, -96, -95, -95, -95, -94, -94, -93, -93,
-91, -90, -89, -88, -87, -87, -85, -84, -82, -81, -79, -79, -77, -76, -74, -73,
-71, -69, -67, -66, -64, -63, -61, -59, -58, -56, -54, -52, -51, -49, -47, -45,
-43, -41, -39, -38, -36, -34, -32, -30, -28, -28, -25, -23, -21, -19, -18, -16,
-14, -12, -10, -8, -6, -5, -3, -2, 0, 2, 4, 6, 7, 9, 11, 13, 14, 16, 17, 18, 20,
22, 23, 25, 26, 28, 29, 31, 33, 35, 37, 38, 38, 40, 41, 43, 44, 45, 46, 47, 49,
51, 52, 53, 55, 56, 58, 58, 59, 61, 62, 63, 64, 66, 66, 67, 69, 69, 69, 72, 72,
73, 74, 75, 75, 76, 77, 78, 79, 80, 80, 81, 81, 81, 83, 83, 84, 84, 83, 84, 85,
86, 85, 85, 85, 87, 86, 87, 87, 86, 86, 87, 86, 86, 87, 86, 86, 86, 86, 86, 85,
85, 84, 85, 84, 83, 83, 83, 82, 81, 81, 80, 80, 79, 78, 77, 76, 76, 75, 75, 73,
72, 72, 71, 69, 68, 67, 67, 65, 64, 63, 62, 60, 58, 57, 56, 55, 54, 52, 51, 49,
49, 46, 44, 44, 42, 40, 39, 37, 36, 34, 33, 31, 30, 28, 27, 25, 24, 22, 20, 19,
17, 15, 13, 13, 10, 9, 7, 5, 4, 2, 1, -1, -3, -4, -6, -8, -9, -11, -13, -14,
-15, -18, -19, -20, -22, -24, -25, -28, -28, -30, -31, -33, -35, -36, -38, -40,
-41, -43, -44, -47, -47, -49, -51, -52, -53, -55, -57, -58, -61, -61, -63, -64,
-66, -67, -68, -71, -72, -73, -74, -75, -77, -78, -79, -81, -81, -82, -84, -85,
-86, -87, -88, -89, -90, -91, -91, -92, -92, -93, -93, -94, -96, -96, -96, -97,
-96, -97, -97, -98, -98, -97, -98, -97, -97, -97, -97, -96, -96, -96, -95, -96,
-94, -94, -94, -93, -92, -90, -89, -89, -89, -87, -86, -85, -84, -82, -81, -80,
-79, -77, -76, -75, -73, -71, -70, -68, -66, -65, -63, -62, -61, -59, -57, -55,
-53, -52, -49, -48, -46, -45, -43, -41, -39, -38, -36, -34, -32, -30, -28, -27,
-25, -23, -21, -19, -18, -16, -15, -13, -11, -9, -8, -5, -3, -2, 0, 2, 2, 4, 7,
8, 9, 12, 13, 15, 16, 18, 19, 21, 23, 25, 26, 27, 29, 30, 32, 33, 35, 37, 38,
40, 40, 42, 43, 45, 46, 46, 48, 50, 50, 51, 53, 55, 56, 57, 57, 59, 59, 61, 61,
63, 63, 65, 66, 66, 67, 68, 69, 70, 71, 71, 72, 73, 73, 73, 74, 75, 75, 76, 76,
76, 77, 78, 77, 78, 78, 78, 79, 79, 79, 79, 79, 79, 80, 80, 79, 80, 79, 80, 80,
79, 79, 78, 78, 78, 78, 76, 77, 76, 76, 76, 75, 75, 74, 75, 73, 72, 72, 71, 71,
70, 69, 69, 69, 68, 67, 66, 65, 64, 64, 62, 61, 61, 59, 59, 58, 56, 55, 54, 53,
52, 50, 50, 49, 47, 46, 45, 44, 43, 42, 40, 39, 38, 37, 34, 34, 33, 32, 31, 29,
27, 26, 24, 24, 22, 20, 19, 17, 17, 15, 13, 12, 10, 9, 8, 6, 4, 4, 1, 0, -1, -3,
-4, -6, -6, -7, -10, -11, -13, -14, -15, -17, -18, -20, -20, -21, -24, -24, -26,
-28, -28, -30, -32, -33, -34, -37, -38, -39, -40, -41, -43, -45, -46, -47, -49,
-50, -51, -52, -54, -55, -57, -58, -59, -60, -61, -64, -65, -65, -67, -68, -69,
-70, -72, -72, -74, -75, -75, -77, -78, -79, -80, -81, -81, -82, -83, -83, -84,
-84, -85, -86, -86, -87, -88, -87, -88, -88, -88, -89, -89, -90, -89, -89, -89,
-89, -88, -88, -88, -87, -88, -87, -86, -86, -86, -85, -85, -83, -83, -82, -81,
-79, -80, -78, -77, -75, -75, -74, -72, -71, -70, -69, -67, -66, -65, -63, -61,
-60, -58, -57, -56, -55, -53, -51, -50, -49, -46, -45, -43, -42, -40, -39, -37,
-36, -34, -32, -31, -29, -27, -26, -25, -23, -21, -20, -17, -15, -14, -13, -11,
-9, -8, -6, -5, -3, -1, 0, 2, 3, 5, 7, 8, 9, 11, 12, 14, 16, 17, 18, 19, 21, 23,
24, 25, 27, 28, 30, 31, 32, 34, 35, 37, 37, 39, 40, 41, 42, 43, 44, 45, 47, 48,
49, 50, 52, 52, 53, 54, 55, 56, 58, 57, 59, 60, 60, 62, 61, 63, 63, 64, 64, 65,
66, 67, 67, 67, 69, 69, 70, 70, 70, 71, 71, 71, 71, 71, 72, 72, 72, 72, 72, 72,
73, 73, 73, 73, 73, 73, 72, 74, 72, 73, 73, 72, 72, 72, 72, 71, 71, 70, 71, 71,
70, 69, 69, 68, 68, 66, 67, 66, 65, 65, 65, 64, 63, 62, 61, 61, 60, 59, 58, 57,
56, 56, 55, 54, 53, 53, 51, 51, 49, 48, 47, 47, 46, 45, 43, 43, 40, 39, 38, 38,
36, 35, 34, 33, 31, 31, 29, 28, 27, 25, 23, 23, 22, 20, 19, 17, 17, 15, 14, 13,
11, 10, 8, 7, 6, 5, 4, 2, 1, -1, -2, -3, -5, -6, -7, -8, -9, -11, -12, -14, -14,
-16, -17, -19, -19, -21, -23, -24, -25, -26, -27, -28, -30, -31, -32, -33, -35,
-36, -37, -38, -39, -41, -41, -42, -44, -45, -47, -48, -48, -49, -50, -51, -53,
-54, -55, -55, -57, -58, -59, -60, -60, -62, -62, -63, -65, -66, -67, -67, -68,
-68, -69, -70, -70, -72, -71, -72, -73, -73, -74, -73, -74, -74, -75, -75, -75,
-75, -76, -76, -76, -76, -76, -76, -76, -76, -75, -75, -76, -74, -74, -73, -74,
-73, -72, -73, -71, -70, -70, -69, -69, -69, -67, -66, -65, -64, -64, -63, -62,
-61, -59, -59, -57, -56, -54, -54, -53, -52, -50, -49, -48, -47, -46, -45, -43,
-42, -40, -39, -38, -36, -35, -33, -32, -31, -29, -28, -27, -26, -25, -23, -21,
-20, -19, -17, -16, -14, -14, -12, -11, -9, -8, -6, -5, -4, -2, -1, 0, 2, 3, 5,
5, 8, 8, 10, 11, 13, 13, 14, 16, 17, 18, 19, 21, 23, 23, 24, 25, 26, 27, 29, 29,
32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 48, 49, 50, 51,
53, 52, 53, 55, 55, 56, 56, 57, 58, 59, 60, 60, 61, 62, 62, 63, 63, 64, 65, 65,
65, 65, 65, 66, 66, 68, 68, 69, 68, 69, 68, 69, 69, 69, 70, 69, 69, 69, 69, 70,
70, 69, 70, 70, 70, 69, 69, 68, 68, 69, 68, 68, 68, 67, 67, 67, 65, 65, 65, 64,
63, 63, 62, 63, 61, 61, 60, 59, 58, 57, 57, 56, 55, 54, 54, 52, 51, 51, 49, 48,
48, 46, 46, 45, 43, 42, 41, 40, 39, 37, 38, 35, 35, 34, 33, 31, 30, 28, 28, 26,
26, 24, 23, 21, 20, 18, 17, 16, 15, 14, 13, 12, 10, 9, 7, 6, 5, 4, 2, 1, 1, -1,
-3, -4, -6, -7, -8, -9, -11, -11, -12, -15, -15, -17, -17, -19, -20, -21, -22,
-24, -25, -27, -27, -28, -30, -31, -32, -33, -34, -35, -36, -37, -38, -40, -41,
-42, -43, -44, -45, -47, -47, -48, -49, -51, -52, -53, -53, -54, -55, -56, -57,
-58, -60, -60, -61, -61, -63, -63, -64, -65, -66, -67, -67, -68, -68, -69, -69,
-70, -70, -70, -71, -71, -71, -72, -72, -73, -73, -73, -73, -73, -73, -73, -74,
-73, -73, -73, -72, -72, -73, -71, -72, -72, -71, -71, -70, -70, -68, -68, -67,
-67, -66, -65, -65, -64, -63, -62, -62, -61, -60, -60, -58, -56, -56, -55, -54,
-52, -52, -51, -49, -48, -46, -45, -44, -44, -42, -41, -40, -39, -37, -36, -35,
-33, -31, -30, -29, -29, -27, -26, -24, -22, -22, -20, -19, -18, -17, -14, -14,
-13, -11, -9, -9, -8, -6, -5, -3, -2, -1, 1, 2, 3, 4, 6, 7, 9, 10, 11, 11, 14,
15, 15, 16, 18, 19, 20, 22, 22, 24, 25, 26, 27, 27, 29, 31, 31, 32, 33, 34, 35,
36, 37, 39, 38, 40, 41, 42, 42, 43, 43, 44, 46, 46, 47, 48, 49, 49, 49, 50, 51,
52, 53, 53, 53, 54, 54, 55, 56, 56, 56, 56, 57, 58, 58, 59, 59, 59, 60, 60, 60,
60, 60, 60, 60, 60, 61, 60, 61, 60, 62, 60, 62, 60, 61, 61, 60, 60, 60, 60, 60,
60, 59, 58, 58, 58, 58, 57, 57, 56, 56, 56, 56, 55, 55, 53, 54, 53, 52, 52, 51,
50, 50, 49, 49, 48, 48, 47, 46, 46, 44, 44, 42, 42, 42, 40, 40, 38, 38, 38, 36,
35, 34, 33, 32, 31, 30, 30, 28, 28, 26, 26, 24, 23, 23, 21, 21, 20, 18, 17, 17,
15, 14, 13, 12, 11, 10, 10, 8, 6, 5, 5, 4, 2, 1, 0, 0, -1, -3, -5, -5, -6, -8,
-9, -9, -11, -12, -13, -14, -14, -16, -17, -18, -20, -21, -22, -22, -23, -25,
-25, -26, -28, -28, -30, -31, -32, -32, -33, -34, -36, -36, -37, -38, -38, -39,
-40, -42, -42, -43, -44, -46, -46, -47, -48, -50, -50, -50, -51, -53, -53, -53,
-54, -55, -56, -57, -57, -57, -58, -59, -60, -61, -60, -61, -61, -62, -62, -63,
-63, -64, -64, -64, -65, -64, -65, -65, -66, -65, -66, -65, -66, -65, -66, -66,
-65, -65, -64, -64, -64, -64, -63, -62, -62, -62, -62, -61, -60, -60, -60, -58,
-57, -56, -56, -56, -55, -53, -53, -52, -50, -50, -50, -47, -47, -46, -45, -45,
-43, -42, -40, -39, -39, -38, -37, -35, -34, -33, -32, -31, -29, -29, -28, -26,
-26, -24, -23, -21, -21, -19, -19, -18, -15, -15, -14, -13, -12, -10, -10, -9,
-7, -6, -5, -3, -3, -1, 0, 1, 2, 3, 5, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 17,
17, 18, 19, 20, 21, 21, 23, 23, 25, 26, 26, 28, 28, 29, 30, 31, 31, 33, 33, 34,
35, 36, 36, 37, 38, 38, 40, 40, 41, 42, 42, 42, 44, 44, 44, 45, 45, 46, 46, 47,
48, 48, 48, 48, 49, 49, 50, 50, 50, 50, 50, 51, 52, 51, 52, 52, 52, 52, 52, 52,
53, 53, 53, 53, 53, 52, 53, 53, 54, 53, 53, 52, 53, 52, 51, 52, 51, 52, 51, 51,
51, 50, 51, 50, 50, 49, 48, 48, 48, 47, 47, 46, 45, 45, 45, 44, 44, 44, 43, 41,
42, 41, 40, 40, 39, 38, 37, 37, 36, 36, 35, 34, 34, 33, 32, 31, 30, 29, 28, 27,
27, 26, 25, 25, 24, 23, 22, 21, 21, 20, 19, 18, 18, 16, 14, 14, 14, 13, 12, 10,
9, 8, 7, 7, 6, 4, 4, 3, 2, 1, 1, 0, -2, -2, -4, -4, -5, -6, -7, -8, -9, -9, -10,
-12, -12, -13, -14, -15, -15, -17, -18, -17, -19, -20, -21, -22, -22, -23, -23,
-25, -25, -26, -27, -27, -28, -29, -31, -30, -31, -32, -33, -33, -34, -35, -36,
-37, -37, -37, -38, -40, -39, -40, -41, -41, -42, -42, -43, -44, -44, -44, -45,
-45, -46, -47, -46, -47, -47, -48, -48, -49, -49, -49, -49, -49, -49, -50, -50,
-50, -49, -50, -50, -50, -50, -50, -50, -50, -49, -50, -50, -49, -50, -49, -49,
-49, -49, -48, -48, -47, -47, -46, -46, -46, -45, -44, -44, -44, -43, -42, -42,
-42, -40, -41, -39, -39, -38, -38, -37, -36, -35, -35, -34, -34, -33, -32, -31,
-30, -29, -28, -28, -27, -26, -24, -24, -23, -23, -22, -21, -20, -19, -18, -17,
-17, -16, -14, -13, -13, -12, -11, -10, -10, -9, -7, -7, -6, -5, -4, -4, -2, -2,
-1, 1, 1, 2, 3, 4, 5, 5, 7, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17,
18, 19, 20, 20, 20, 21, 22, 22, 23, 24, 25, 26, 26, 26, 28, 28, 28, 29, 29, 30,
30, 31, 32, 32, 32, 33, 33, 34, 34, 35, 34, 35, 37, 36, 37, 36, 37, 37, 37, 37,
38, 38, 38, 38, 39, 40, 39, 40, 39, 41, 40, 40, 41, 41, 40, 40, 40, 41, 41, 41,
40, 41, 41, 41, 41, 41, 40, 40, 40, 39, 40, 40, 39, 39, 39, 39, 39, 38, 38, 38,
37, 37, 36, 36, 36, 36, 35, 35, 34, 35, 34, 33, 33, 34, 32, 32, 30, 31, 30, 30,
29, 28, 28, 28, 27, 26, 26, 25, 25, 24, 24, 23, 22, 21, 21, 20, 20, 19, 19, 18,
17, 17, 15, 15, 15, 13, 13, 12, 12, 10, 10, 9, 9, 9, 7, 7, 6, 6, 5, 4, 4, 3, 1,
1, 0, -1, -1, -2, -2, -4, -4, -5, -5, -6, -7, -8, -9, -9, -10, -10, -11, -11,
-12, -13, -14, -14, -15, -15, -15, -16, -17, -18, -18, -18, -19, -20, -21, -21,
-22, -22, -23, -24, -24, -25, -25, -26, -26, -27, -28, -28, -28, -29, -29, -30,
-30, -31, -31, -32, -31, -33, -33, -33, -34, -34, -34, -34, -35, -35, -36, -36,
-36, -36, -38, -37, -37, -37, -38, -39, -38, -38, -38, -39, -38, -39, -39, -38,
-38, -38, -39, -38, -38, -39, -38, -39, -38, -37, -38, -37, -37, -37, -37, -36,
-37, -36, -36, -35, -35, -34, -34, -35, -33, -33, -32, -32, -32, -32, -31, -31,
-30, -29, -29, -28, -27, -26, -26, -26, -25, -25, -25, -24, -23, -23, -22, -21,
-21, -20, -19, -18, -19, -17, -16, -16, -15, -15, -14, -13, -14, -11, -12, -12,
-11, -9, -9, -7, -8, -7, -7, -6, -4, -4, -3, -3, -2, -2, 0, -1, 0, 1, 2, 2, 2,
4, 5, 5, 6, 6, 6, 8, 8, 8, 9, 10, 10, 11, 11, 13, 12, 14, 14, 15, 15, 16, 17,
17, 17, 17, 18, 18, 19, 20, 20, 20, 21, 21, 22, 23, 23, 23, 23, 24, 25, 26, 25,
25, 27, 26, 27, 28, 27, 27, 28, 28, 28, 29, 29, 30, 30, 30, 30, 30, 30, 30, 31,
31, 31, 31, 31, 32, 31, 32, 31, 31, 31, 32, 32, 32, 31, 31, 32, 31, 32, 32, 32,
32, 32, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30, 30, 30, 29, 29, 29, 29, 28, 29,
27, 28, 28, 27, 27, 26, 26, 25, 25, 25, 24, 23, 23, 23, 23, 23, 22, 22, 21, 20,
20, 20, 19, 18, 19, 18, 17, 17, 17, 15, 16, 16, 15, 14, 13, 13, 13, 12, 11, 11,
11, 10, 10, 9, 8, 8, 7, 6, 6, 5, 5, 5, 4, 3, 2, 2, 2, 1, 0, 0, 0, -1, -1, -2,
-3, -3, -4, -4, -5, -5, -7, -6, -7, -8, -8, -8, -9, -10, -9, -11, -11, -11, -11,
-12, -12, -13, -14, -14, -15, -15, -15, -16, -17, -17, -17, -18, -18, -18, -19,
-19, -20, -20, -21, -21, -21, -22, -22, -22, -23, -24, -23, -24, -24, -25, -24,
-25, -25, -25, -26, -27, -27, -27, -26, -27, -28, -27, -28, -27, -28, -28, -28,
-28, -28, -29, -29, -28, -29, -29, -29, -29, -28, -29, -29, -29, -29, -29, -29,
-29, -30, -28, -28, -29, -28, -28, -28, -27, -28, -27, -27, -27, -26, -26, -27,
-26, -26, -25, -25, -25, -25, -25, -24, -23, -23, -23, -22, -22, -22, -22, -21,
-21, -21, -20, -19, -18, -19, -17, -17, -17, -16, -16, -16, -15, -14, -14, -14,
-13, -12, -13, -12, -11, -11, -11, -10, -9, -9, -9, -8, -7, -7, -7, -6, -6, -4,
-4, -4, -4, -3, -2, -1, -1, -1, 0, 0, 0, 1, 2, 2, 3, 4, 4, 4, 4, 5, 6, 6, 7, 7,
7, 8, 8, 9, 8, 9, 11, 10, 11, 12, 12, 12, 12, 13, 13, 13, 14, 14, 14, 14, 15,
15, 16, 17, 17, 17, 17, 17, 18, 18, 19, 19, 19, 19, 20, 20, 20, 21, 20, 21, 21,
21, 21, 22, 22, 22, 22, 22, 22, 22, 23, 23, 24, 22, 23, 23, 23, 24, 24, 24, 23,
24, 24, 24, 24, 24, 23, 24, 24, 24, 24, 23, 23, 23, 23, 24, 23, 23, 23, 23, 23,
23, 23, 23, 21, 22, 22, 22, 21, 21, 22, 22, 20, 21, 20, 20, 20, 19, 19, 20, 19,
19, 18, 18, 18, 17, 17, 17, 16, 17, 16, 15, 15, 14, 15, 15, 14, 14, 13, 13, 12,
12, 12, 11, 10, 10, 10, 10, 9, 9, 9, 8, 7, 8, 7, 6, 6, 7, 6, 5, 4, 5, 4, 3, 4,
2, 2, 2, 2, 1, 1, 0, 0, 0, -1, -1, -2, -2, -3, -3, -2, -3, -3, -4, -5, -6, -6,
-6, -7, -7, -8, -7, -8, -9, -9, -10, -10, -9, -10, -9, -10, -10, -11, -11, -12,
-12, -13, -13, -14, -13, -14, -15, -14, -15, -15, -15, -16, -15, -15, -17, -16,
-17, -17, -18, -17, -17, -18, -18, -18, -18, -19, -19, -19, -19, -19, -19, -20,
-20, -20, -20, -20, -21, -21, -20, -21, -21, -21, -21, -21, -22, -21, -20, -20,
-22, -20, -21, -21, -21, -21, -21, -21, -21, -21, -21, -21, -21, -20, -21, -20,
-20, -20, -20, -19, -20, -19, -19, -19, -19, -19, -18, -18, -17, -18, -18, -18,
-17, -16, -16, -16, -15, -15, -15, -15, -14, -14, -15, -13, -13, -13, -13, -12,
-12, -13, -12, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -8, -7, -7, -6, -7,
-6, -6, -5, -5, -4, -5, -4, -4, -3, -3, -3, -2, -1, -2, -1, 0, 0, 0, 1, 1, 1, 2,
2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 7, 7, 7, 8, 8, 9, 8, 8, 9, 9, 9, 10, 11,
9, 11, 11, 11, 11, 11, 11, 13, 12, 12, 12, 13, 13, 13, 13, 13, 14, 14, 14, 14,
15, 15, 15, 15, 15, 16, 16, 15, 16, 16, 16, 16, 16, 17, 16, 16, 17, 17, 17, 16,
17, 17, 17, 16, 17, 17, 17, 17, 17, 17, 17, 17, 16, 17, 16, 17, 16, 17, 17, 17,
17, 17, 17, 16, 16, 16, 16, 16, 15, 16, 15, 16, 15, 15, 15, 15, 15, 14, 14, 14,
13, 14, 13, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10,
10, 10, 9, 9, 9, 9, 8, 7, 8, 8, 8, 8, 7, 7, 7, 6, 6, 5, 5, 4, 5, 5, 4, 4, 3, 3,
3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, -1, -2, -1, -1, -2, -2, -2, -3, -2, -3, -4,
-4, -4, -5, -5, -5, -4, -5, -6, -5, -6, -6, -6, -7, -7, -7, -7, -8, -8, -8, -8,
-9, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12,
-12, -11, -13, -12, -13, -13, -13, -12, -13, -13, -12, -13, -13, -14, -13, -14,
-14, -13, -14, -15, -15, -15, -14, -15, -14, -14, -15, -14, -14, -14, -14, -15,
-15, -15, -14, -14, -15, -15, -14, -14, -14, -15, -14, -15, -14, -14, -14, -14,
-13, -14, -14, -14, -14, -13, -13, -12, -13, -12, -13, -13, -11, -12, -12, -12,
-11, -11, -11, -11, -10, -10, -10, -10, -10, -11, -10, -10, -9, -8, -9, -9, -9,
-8, -7, -8, -8, -7, -7, -7, -7, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -3, -3,
-4, -3, -4, -3, -3, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 1, 0, 1, 1, 2, 1, 2, 3,
3, 2, 3, 3, 4, 3, 4, 4, 5, 4, 4, 5, 5, 5, 4, 5, 5, 6, 6, 6, 6, 7, 6, 6, 7, 8, 7,
8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 9, 9, 10, 10, 9, 10, 10, 10, 10, 10, 11, 10,
11, 10, 11, 11, 10, 11, 11, 11, 12, 10, 11, 11, 11, 11, 11, 11, 12, 12, 11, 12,
12, 11, 11, 12, 11, 12, 12, 11, 12, 12, 11, 11, 12, 11, 11, 12, 11, 11, 12, 11,
11, 11, 10, 11, 10, 10, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9,
8, 8, 9, 7, 8, 7, 8, 8, 8, 8, 6, 7, 7, 6, 7, 6, 6, 6, 5, 6, 6, 5, 5, 5, 5, 5, 4,
3, 4, 4, 3, 4, 3, 3, 3, 2, 2, 2, 1, 2, 2, 1, 1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -2, -2, -2, -2, -2, -3, -2, -3, -3, -3, -4, -4, -4, -4, -4, -4, -5,
-4, -5, -4, -4, -5, -5, -6, -5, -6, -6, -6, -6, -6, -6, -6, -6, -7, -7, -7, -7,
-8, -8, -7, -7, -8, -7, -8, -8, -8, -9, -9, -8, -8, -8, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -10, -9, -9, -10, -10, -10, -10, -10, -10, -10, -9, -10, -9,
-10, -10, -10, -10, -9, -10, -10, -9, -9, -10, -9, -9, -9, -10, -9, -8, -10, -9,
-9, -9, -8, -8, -8, -8, -8, -8, -8, -8, -9, -8, -7, -8, -7, -7, -8, -7, -6, -8,
-8, -7, -6, -6, -6, -7, -6, -6, -7, -6, -6, -6, -6, -5, -5, -5, -4, -5, -5, -4,
-5, -3, -4, -4, -3, -4, -3, -3, -3, -3, -2, -3, -2, -1, -2, -1, -2, -1, -2, 0,
-1, 0, -1, -1, -1, 0, -1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 2, 2, 1, 2, 2, 1, 3, 2, 4,
3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 4, 5, 4, 5, 6, 5, 4, 5, 6, 5, 6, 6, 6,
6, 6, 6, 6, 6, 7, 7, 6, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 7, 7, 7, 8, 7, 8, 7,
7, 7, 8, 7, 8, 8, 8, 7, 8, 7, 8, 7, 8, 8, 8, 8, 8, 8, 7, 7, 8, 7, 7, 6, 7, 8, 8,
8, 8, 7, 7, 7, 8, 7, 6, 6, 6, 7, 6, 7, 7, 6, 6, 6, 6, 5, 6, 5, 5, 5, 5, 5, 6, 5,
5, 4, 5, 4, 4, 4, 5, 5, 4, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 3, 2, 2, 2, 2, 2,
3, 1, 2, 2, 2, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, -1, -1, 0, -1, -1, -1, -1, -1, 0,
-1, -2, -2, -2, -1, -2, -2, -2, -2, -2, -3, -2, -3, -3, -2, -3, -3, -3, -3, -4,
-4, -4, -4, -4, -4, -3, -4, -4, -5, -4, -4, -5, -4, -5, -5, -5, -5, -5, -4, -5,
-5, -4, -5, -5, -5, -5, -5, -5, -5, -5, -5, -6, -6, -5, -6, -6, -7, -6, -6, -6,
-6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -5, -6, -6, -6, -7, -6, -6, -6, -6, -5,
-6, -6, -6, -6, -6, -6, -5, -6, -5, -6, -6, -5, -6, -5, -5, -5, -6, -6, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -4, -4, -5, -5, -5, -4, -5, -4, -4, -4, -3, -3, -4,
-3, -4, -3, -3, -3, -3, -3, -3, -3, -3, -2, -3, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -1, -2, -2, -1, -1, -1, -1, -1, -2, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
3, 4, 3, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 4, 4, 3, 4, 3, 4, 3, 3, 4, 4, 3, 4, 4, 4,
4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 5, 5, 5, 5, 4, 3, 5, 5, 4, 4, 4, 5, 4, 4, 4, 5, 4,
4, 4, 5, 5, 4, 4, 5, 4, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 3, 3, 4, 4, 3, 3,
3, 3, 3, 3, 3, 4, 3, 4, 2, 3, 3, 3, 3, 2, 3, 2, 2, 2, 3, 2, 2, 2, 2, 2, 1, 2, 2,
2, 1, 2, 1, 2, 1, 2, 1, 1, 0, 2, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0,
-1, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -2, -2, -1, -1,
-2, -2, -2, -1, -2, -1, -2, -1, -2, -2, -3, -2, -3, -2, -2, -2, -2, -2, -2, -2,
-2, -3, -3, -3, -2, -2, -3, -2, -2, -2, -3, -2, -2, -2, -2, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -4, -2, -3, -3, -2, -3, -4, -4,
-3, -3, -3, -3, -3, -3, -4, -3, -2, -3, -3, -3, -4, -2, -3, -3, -3, -2, -3, -3,
-2, -3, -3, -3, -2, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -3, -2, -2, -2, -2,
-1, -2, -2, -2, -2, -2, -1, -2, -2, -1, -2, -2, -1, -1, -2, -2, -2, -2, -2, -2,
-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, 1, -1, 0, 0,
0, -1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1,
0, 1, 1, 1, 0, 0, 1, 2, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2,
2, 2, 1, 1, 2, 3, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 2, 1, 1,
1, 1, 2, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2,
1, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, -1, -1, 0, -1, 0, 0, -1, 0, 0,
-1, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, 0, -1, -1, -1,
-1, -1, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -1, -1, 0, -1, -1, -1,
-1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, -1, -1, -1, -2, -1, -1, -2, -1, -1, -1, -2, -2, -2, -1, -1,
-1, -1, -1, -1, 0, -2, -1, 0, -1, -1, -1, -2, -1, -1, -1, -1, -1, -2, 0, 0, -1,
-1, 0, -1, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1,
0, -1, -1, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, 1, 0,
0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, -1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0,
0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, -1, 1, 0, 1, 0, 0, -1, 0, 0, 1, 1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -1, 1, 0, 0, 0, -1, 0, 0, -1,
0, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, 0,
-1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -1, 0,
-1, -1, -1, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, -1,
-1, -1, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, -1, 0,
0, -1, 0, 0, -1, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, -1, 0, -1,
0, -1, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 1, -1, -1, 1, 0, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 1, 0, 0, 1, 0, -1, 0, 0, 0,
0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0,
1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1,
-1, 1, 0, 1, 1, 0, 1, -1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
0, 1, 0, 0, 0, 1, 0, 0, 0, 0, -1, 1, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0,
0, 1, 0, 0, 0, 0, 1, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 1, 0, -1,
0, 0, -1, -1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0,
0, -1, -1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, -1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
-1, 0, 1, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0,
-1, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
1, 0, 0, -1, 0, 0, 0, 1, 0, -1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 1, 0, -1, 0, 0, -1, -1, 0, 1, 0, 1, 0, -1, 1,
0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0,
0, -1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, -1, 0, 0, 0, -1, 1, 0, 0, 0,
0, -1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0,
0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, 0, 0, 0, 0,
0, -1, -1, 0, 0, 0, -1, 0, 0, 0, 1, 0, -1, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0,
-1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 1, 0, -1, 1, 0, 1, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 1, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, 1, 0,
-1, 0, 0, 0, 0, 1, 0, 1, 1, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0,
0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 1, -1, 0, 0, 1, 0, -1, 0, 0, 1, 0, 0, -1, 0, 0,
0, 0, 0, 0, -1, 0, 0, -1, 0, -1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 1, 0, -1, -1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
0, 1, 0, 0, -1, -1, 0, -1, 0, -1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 1, 1, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, 1, 0, 0, 1, 1, 0,
1, 0, 0, 0, 0, 1, -1, 0, 0, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, 1, 0, 0, -1,
0, -1, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 0, 1, -1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0,
-1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 1, 0, 0, 0, -1, 0, 0, };

#endif /* sample0_H_ */
