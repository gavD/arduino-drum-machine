#ifndef clap_H_
#define clap_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"

#define CLAP_NUM_CELLS 2048
#define CLAP_SAMPLERATE 16384

CONSTTABLE_STORAGE(int8_t) CLAP_DATA [] = {2, 5, 8, 7, 2, -1, -1, 0, -3, -5, -4,
-2, -2, -3, 0, 6, 8, 4, 6, 23, 43, 43, 14, -25, -49, -47, -26, 0, 17, 15, -3,
-26, -47, -59, -61, -51, -28, 1, 29, 49, 60, 62, 51, 26, -10, -45, -63, -53,
-22, 5, 12, 8, 12, 29, 41, 36, 21, 11, 8, 7, 9, 19, 31, 30, 8, -21, -40, -39,
-26, -13, -11, -21, -33, -36, -24, -4, 17, 36, 47, 39, 16, -3, 1, 16, 13, -16,
-49, -62, -55, -48, -46, -41, -26, -6, 9, 23, 38, 46, 36, 9, -18, -25, -5, 31,
59, 62, 40, 6, -23, -40, -42, -32, -16, -5, -3, -2, 6, 21, 30, 27, 16, 8, 3, -2,
-6, -3, 7, 12, 6, -10, -24, -26, -14, 1, -1, -24, -50, -57, -36, -7, 12, 19, 26,
36, 41, 35, 21, 7, -5, -14, -17, -13, -6, -3, -5, -6, -2, 2, 0, -7, -14, -15,
-6, 6, 13, 10, -1, -12, -19, -19, -15, -7, 7, 23, 34, 36, 28, 12, -3, -8, -2, 3,
0, -8, -13, -15, -24, -39, -46, -38, -25, -20, -21, -12, 12, 38, 50, 48, 42, 34,
21, 1, -15, -14, 4, 21, 23, 8, -7, -10, -3, 2, -3, -15, -30, -49, -74, -95, -93,
-62, -10, 42, 78, 94, 96, 94, 87, 67, 27, -20, -55, -72, -86, -106, -108, -65,
14, 77, 86, 56, 39, 54, 70, 49, -6, -50, -52, -22, 10, 27, 34, 36, 23, -16, -66,
-94, -79, -33, 12, 32, 32, 22, 4, -25, -54, -61, -35, 10, 43, 49, 31, 5, -17,
-25, -15, 12, 44, 61, 47, 5, -43, -75, -79, -58, -24, 9, 30, 33, 17, -5, -18,
-13, 6, 30, 45, 40, 16, -13, -32, -36, -34, -29, -15, 19, 61, 85, 74, 39, 8, -8,
-17, -34, -55, -64, -56, -38, -21, -3, 21, 48, 64, 58, 34, 5, -15, -28, -35,
-34, -21, 0, 16, 16, 3, -10, -12, -3, 8, 14, 13, 8, 2, -1, -1, 1, 6, 10, 9, 0,
-16, -30, -36, -29, -13, 5, 13, 7, -8, -23, -27, -20, -8, 4, 15, 25, 29, 24, 13,
4, 2, 6, 10, 10, 1, -13, -25, -28, -20, -7, 3, 7, 4, -3, -10, -15, -11, -1, 11,
17, 14, 6, 1, 2, 6, 6, 1, -8, -16, -19, -14, -2, 11, 17, 13, 4, -2, -4, -2, 1,
5, 10, 11, 8, 3, 3, 7, 9, 7, 2, 0, -3, -9, -16, -17, -10, -2, -1, -4, -6, -6,
-5, -4, 1, 14, 27, 33, 25, 7, -9, -16, -14, -8, -5, -5, -2, 4, 7, 5, 1, 2, 8, 9,
3, -6, -10, -11, -11, -11, -6, 2, 10, 13, 12, 8, 7, 9, 15, 19, 17, 9, -3, -10,
-12, -11, -13, -21, -27, -25, -14, 0, 8, 9, 6, -1, -7, -4, 9, 22, 25, 22, 29,
46, 54, 34, -7, -47, -78, -107, -126, -108, -42, 35, 71, 55, 27, 27, 54, 79, 81,
65, 42, 16, -10, -31, -40, -42, -48, -54, -49, -29, -3, 15, 21, 24, 30, 37, 38,
30, 19, 12, 11, 10, 4, -7, -23, -37, -45, -41, -29, -18, -14, -15, -16, -12, -6,
2, 11, 16, 14, 8, 2, -1, -4, -9, -6, 11, 32, 33, 5, -29, -45, -38, -34, -47,
-63, -53, -15, 23, 34, 21, 5, 4, 13, 23, 28, 29, 28, 24, 18, 13, 11, 11, 12, 12,
10, 4, -4, -8, -8, -5, -4, -8, -16, -24, -28, -24, -12, 3, 16, 24, 24, 14, -5,
-23, -27, -16, -3, -3, -18, -33, -34, -21, -5, 6, 13, 21, 29, 33, 30, 24, 19,
17, 14, 8, -2, -8, -7, -3, -1, -1, -2, -2, -4, -10, -16, -18, -14, -7, 1, 10,
17, 19, 14, 5, -4, -11, -11, -5, 3, 6, 1, -10, -19, -22, -21, -19, -18, -16,
-13, -10, -4, 7, 19, 27, 27, 24, 20, 18, 12, 5, -1, -1, 2, 1, -3, -7, -8, -7,
-5, -7, -10, -11, -7, 2, 10, 13, 8, 1, -4, -7, -9, -12, -13, -13, -12, -12, -13,
-13, -9, 0, 16, 38, 54, 53, 33, 7, -7, -9, -9, -19, -33, -43, -43, -39, -36,
-30, -17, -6, -2, -4, -1, 13, 33, 47, 49, 40, 24, 6, -7, -12, -11, -8, -2, 8,
20, 25, 19, 8, 2, 4, 4, -2, -7, -3, 6, 9, 1, -12, -20, -19, -15, -13, -16, -20,
-19, -11, 0, 7, 7, 8, 14, 22, 26, 25, 19, 8, -8, -22, -24, -17, -12, -18, -28,
-31, -21, -5, 8, 13, 17, 23, 30, 34, 31, 18, -3, -21, -28, -25, -17, -11, -5, 2,
10, 15, 15, 13, 13, 14, 13, 9, 3, -2, -7, -13, -18, -19, -18, -16, -17, -19,
-16, -8, 1, 6, 5, 3, 3, 7, 13, 17, 14, 3, -11, -18, -15, -7, -1, 3, 6, 8, 7, 5,
5, 8, 10, 8, 4, 0, -1, 1, 1, 0, -4, -10, -15, -16, -13, -10, -8, -6, -4, 0, 5,
10, 13, 12, 8, 3, 0, -2, -7, -12, -16, -16, -14, -11, -5, 2, 9, 11, 10, 10, 14,
18, 18, 14, 8, 3, 0, -2, -2, -3, -6, -12, -16, -16, -13, -10, -10, -8, -3, 5,
10, 12, 12, 13, 13, 9, 1, -10, -16, -15, -8, -3, -2, -5, -5, -1, 2, 1, -1, 0, 6,
10, 11, 8, 3, -2, -7, -6, 1, 11, 15, 11, 3, -2, -5, -4, -2, 1, -1, -11, -20,
-21, -12, -4, -4, -6, -3, 4, 8, 6, 1, 0, 3, 9, 15, 19, 21, 17, 8, -1, -6, -8,
-9, -9, -7, -6, -6, -7, -6, -3, 1, 3, 2, 1, 0, 0, -1, -3, -4, -2, -1, -3, -8,
-12, -11, -8, -4, -2, 0, 3, 8, 12, 14, 14, 10, 5, 1, -1, 0, 0, -2, -3, -2, 2, 5,
5, 1, -3, -5, -5, -6, -8, -11, -12, -10, -5, 1, 7, 10, 10, 7, 2, -1, -2, -3, -4,
-5, -6, -6, -7, -6, -2, 3, 8, 10, 10, 10, 10, 9, 4, -5, -13, -18, -17, -13, -9,
-5, 0, 7, 11, 11, 7, 3, 3, 3, 1, -3, -5, -3, 1, 3, 1, -2, -3, -1, 2, 4, 4, 1,
-3, -6, -6, -5, -6, -7, -5, -2, 0, 0, -1, 1, 3, 4, 2, 1, 1, 1, 0, -2, -4, -4,
-4, -4, -3, 0, 4, 8, 9, 5, -1, -4, -1, 6, 8, 5, 0, -3, -4, -5, -6, -7, -8, -9,
-8, -5, -3, -2, 1, 8, 13, 10, 5, 8, 17, 18, 3, -8, 2, 25, 28, -1, -40, -62, -63,
-60, -53, -31, 7, 38, 48, 47, 52, 60, 49, 11, -35, -58, -46, -12, 20, 31, 17,
-17, -50, -61, -38, 6, 47, 62, 47, 16, -8, -12, 0, 14, 13, -4, -25, -34, -23, 1,
20, 20, 3, -15, -18, -4, 12, 13, -4, -20, -15, 8, 26, 18, -7, -25, -21, -5, 4,
-6, -26, -41, -37, -13, 16, 29, 20, 6, 6, 21, 32, 21, -7, -33, -41, -28, -5, 14,
18, 10, 0, -1, 6, 13, 13, 11, 11, 12, 8, -4, -16, -19, -10, 5, 14, 10, -5, -18,
-20, -9, 4, 9, 5, -2, -5, -5, -4, -2, 4, 8, 6, -3, -12, -11, 1, 13, 14, 2, -11,
-15, -7, 5, 13, 12, 1, -13, -21, -16, -1, 11, 13, 4, -5, -5, 4, 15, 18, 10, -2,
-11, -13, -11, -8, -3, 3, 10, 12, 8, -1, -10, -14, -12, -7, -2, 1, 2, 4, 6, 7,
6, 2, -4, -7, -7, -4, 1, 6, 8, 6, 1, -4, -6, -5, -2, 0, 0, -2, -3, -2, 1, 4, 5,
3, 0, -3, -4, -4, -1, 1, 2, 1, -1, -2, -3, -2, 0, 2, 3, 3, 1, 0, 1, 2, 2, 0, -3,
-4, -4, -2, -1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, 0, 0, -1, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, -1, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0,
0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#endif /* clap_H_ */
