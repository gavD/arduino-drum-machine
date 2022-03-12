#ifndef snare_H_
#define snare_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"

#define SNARE_NUM_CELLS 2044
#define SNARE_SAMPLERATE 16384

CONSTTABLE_STORAGE(int8_t) SNARE_DATA [] = {7, 36, 67, 77, 64, 42, 27, 23, 27,
29, 19, -9, -43, -55, -38, -22, -39, -75, -80, -33, 19, 13, -47, -97, -91, -50,
-24, -30, -44, -44, -33, -24, -21, -19, -18, -15, -8, -3, -8, -16, -7, 24, 49,
38, 8, 4, 41, 83, 88, 65, 51, 65, 85, 88, 75, 65, 65, 62, 50, 41, 51, 75, 84,
58, 11, -13, 5, 37, 38, -1, -41, -48, -29, -8, 3, 12, 17, 7, -16, -37, -50, -64,
-81, -90, -82, -72, -79, -100, -116, -116, -108, -102, -101, -101, -97, -91,
-84, -79, -78, -75, -62, -40, -24, -25, -35, -32, -13, 10, 19, 18, 17, 24, 36,
44, 47, 50, 58, 67, 74, 73, 71, 75, 86, 93, 92, 85, 83, 87, 90, 87, 81, 79, 82,
80, 69, 53, 47, 55, 66, 65, 47, 25, 17, 25, 34, 33, 25, 22, 23, 19, 5, -7, -5,
5, 8, -5, -24, -34, -34, -35, -45, -59, -66, -66, -67, -72, -80, -86, -90, -97,
-103, -104, -99, -94, -94, -98, -101, -98, -91, -86, -86, -87, -85, -82, -79,
-78, -77, -72, -62, -49, -37, -27, -18, -7, 6, 17, 26, 34, 43, 51, 57, 64, 75,
89, 99, 99, 89, 77, 70, 69, 72, 74, 70, 63, 59, 64, 75, 79, 69, 48, 29, 22, 30,
49, 70, 76, 65, 46, 34, 35, 44, 54, 64, 66, 54, 29, 7, 2, 10, 14, 6, -9, -20,
-21, -11, 1, 0, -25, -66, -92, -79, -40, -13, -20, -49, -69, -69, -63, -66, -74,
-75, -67, -60, -66, -80, -87, -78, -62, -56, -64, -73, -71, -55, -40, -36, -40,
-41, -34, -23, -12, -4, 0, 1, -1, -4, -5, -2, 8, 21, 26, 16, -2, -11, -1, 22,
38, 36, 22, 9, 6, 13, 25, 35, 40, 38, 33, 30, 34, 42, 50, 51, 46, 39, 36, 37,
40, 43, 43, 42, 43, 48, 56, 60, 59, 56, 52, 45, 37, 36, 52, 76, 85, 64, 27, 4,
9, 29, 41, 35, 16, -8, -29, -41, -39, -28, -23, -36, -60, -79, -79, -62, -46,
-47, -69, -96, -105, -91, -66, -53, -57, -69, -74, -67, -56, -50, -54, -62, -62,
-46, -25, -17, -25, -35, -32, -22, -20, -24, -18, 4, 23, 18, -4, -16, -4, 14,
16, 8, 10, 32, 52, 46, 22, 13, 32, 57, 56, 28, 4, 11, 37, 55, 54, 47, 47, 50,
48, 45, 50, 62, 68, 61, 45, 33, 32, 42, 58, 69, 60, 34, 8, 1, 14, 27, 24, 10, 3,
5, 10, 9, 5, 2, 0, -7, -18, -26, -26, -23, -22, -25, -33, -40, -44, -44, -41,
-42, -46, -51, -52, -52, -55, -59, -53, -38, -30, -39, -55, -57, -39, -22, -22,
-38, -51, -49, -37, -25, -20, -20, -20, -16, -9, -5, -9, -15, -16, -10, -2, 0,
1, 7, 14, 15, 11, 10, 17, 23, 21, 15, 16, 26, 36, 35, 28, 27, 37, 49, 50, 42,
36, 42, 55, 62, 56, 46, 44, 49, 51, 47, 42, 42, 41, 31, 19, 16, 27, 39, 39, 28,
16, 13, 18, 22, 19, 7, -8, -19, -19, -13, -10, -18, -31, -39, -33, -22, -19,
-30, -47, -55, -47, -33, -28, -36, -47, -53, -51, -46, -40, -35, -31, -32, -37,
-41, -41, -38, -34, -29, -23, -20, -19, -18, -15, -14, -19, -22, -12, 4, 9, -6,
-24, -25, -7, 10, 13, 3, -8, -12, -8, 5, 19, 24, 17, 6, 2, 9, 21, 34, 44, 44,
34, 25, 27, 38, 46, 46, 42, 40, 39, 33, 25, 24, 29, 36, 43, 48, 47, 37, 27, 27,
37, 40, 30, 16, 13, 18, 20, 13, 7, 9, 11, 3, -13, -21, -15, -3, -2, -14, -26,
-27, -18, -15, -25, -37, -37, -29, -28, -37, -42, -35, -27, -31, -45, -51, -45,
-34, -30, -30, -31, -33, -36, -35, -30, -27, -32, -37, -29, -11, -3, -16, -35,
-39, -24, -8, -5, -11, -17, -15, -9, -3, 0, 4, 10, 12, 7, -1, 4, 25, 45, 43, 23,
8, 13, 29, 42, 49, 53, 52, 40, 24, 21, 34, 46, 44, 36, 35, 41, 39, 29, 24, 32,
40, 31, 12, 4, 19, 37, 36, 15, -4, -5, 9, 18, 14, 3, -3, -1, 1, -2, -8, -11,
-11, -10, -10, -12, -18, -24, -29, -29, -27, -27, -29, -29, -25, -23, -27, -36,
-42, -44, -42, -38, -33, -28, -27, -31, -33, -28, -21, -17, -21, -29, -35, -31,
-18, -4, -3, -18, -30, -23, -3, 9, 3, -9, -10, -2, 5, 3, 1, 2, 6, 11, 14, 15,
11, 10, 17, 29, 32, 23, 14, 16, 23, 25, 25, 36, 55, 60, 40, 14, 10, 26, 39, 35,
23, 20, 23, 23, 18, 17, 24, 32, 31, 20, 8, 5, 12, 21, 21, 11, 0, 2, 14, 22, 12,
-6, -17, -13, -5, -9, -23, -35, -34, -26, -22, -23, -21, -19, -23, -37, -47,
-43, -28, -18, -23, -31, -33, -28, -25, -26, -26, -22, -18, -17, -20, -24, -25,
-23, -16, -8, -7, -15, -23, -21, -11, -4, -2, -3, -1, 1, 0, -3, -1, 4, 10, 11,
9, 7, 6, 5, 5, 6, 9, 15, 20, 21, 18, 17, 18, 21, 20, 20, 24, 32, 35, 31, 23, 20,
24, 28, 30, 28, 26, 24, 24, 24, 23, 20, 17, 16, 18, 19, 15, 8, 5, 8, 10, 8, 4,
3, 3, -1, -8, -10, -5, -1, -5, -17, -24, -22, -13, -9, -15, -26, -31, -27, -20,
-19, -26, -31, -27, -22, -27, -38, -40, -28, -13, -12, -25, -35, -32, -22, -16,
-19, -25, -26, -21, -15, -13, -15, -16, -10, -1, 3, -2, -11, -14, -8, 3, 10, 10,
5, 5, 12, 19, 18, 9, 5, 13, 25, 25, 16, 15, 25, 32, 26, 14, 14, 25, 30, 22, 15,
18, 27, 29, 21, 12, 11, 16, 22, 24, 21, 14, 8, 8, 12, 14, 11, 7, 9, 15, 18, 12,
2, -5, -2, 6, 9, 2, -9, -12, -8, -5, -8, -16, -18, -17, -15, -16, -15, -12, -13,
-18, -23, -23, -20, -21, -23, -23, -17, -12, -12, -18, -22, -20, -17, -17, -21,
-24, -20, -12, -7, -9, -14, -15, -14, -13, -13, -11, -5, -1, -2, -6, -7, -4, -2,
-1, 1, 3, 4, 2, 1, 3, 6, 8, 7, 6, 7, 9, 10, 11, 13, 15, 15, 14, 13, 13, 13, 15,
16, 16, 14, 13, 13, 14, 13, 13, 14, 14, 12, 9, 7, 7, 7, 6, 5, 5, 6, 5, 1, -2,
-2, 0, 1, -2, -5, -6, -4, 0, 0, -4, -8, -8, -6, -4, -4, -5, -6, -6, -6, -5, -4,
-4, -5, -7, -7, -5, -4, -4, -5, -4, -4, -4, -5, -5, -4, -3, -3, -3, -3, -2, -2,
-2, -2, -3, -3, -2, 0, 0, -1, -2, -2, -2, -1, 0, 1, 1, 0, -1, -1, -1, 0, 0, 0,
0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1,
-1, -1, -1, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0,
-1, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1, -1, 0, 0, };

#endif /* snare_H_ */
