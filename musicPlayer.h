#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <math.h>

#define W 500	// initial tempo
#define H W/2
#define Q H/2
#define E Q/2
#define S E/2
#define T S/2

#define C1 -45
#define Cs1 -44
#define D1 -43
#define Ds1 -42
#define E1 -41
#define F1 -40
#define Fs1 -39
#define G1 -38
#define Gs1 -37
#define A1 -36
#define As1 -35
#define B1 -34

#define C2 -33
#define Cs2 -32
#define D2 -31
#define Ds2 -30
#define E2 -29
#define F2 -28
#define Fs2 -27
#define G2 -26
#define Gs2 -25
#define A2 -24
#define As2 -23
#define B2 -22

#define C3 -21
#define Cs3 -20
#define D3 -19
#define Ds3 -18
#define E3 -17
#define F3 -16
#define Fs3 -15
#define G3 -14
#define Gs3 -13
#define A3 -12
#define As3 -11
#define B3 -10

#define C4 -9
#define Cs4 -8
#define D4 -7
#define Ds4 -6
#define E4 -5
#define F4 -4
#define Fs4 -3
#define G4 -2
#define Gs4 -1
#define A4 0
#define As4 1
#define B4 2

#define C5 3
#define Cs5 4
#define D5 5
#define Ds5 6
#define E5 7
#define F5 8
#define Fs5 9
#define G5 10
#define Gs5 11
#define A5 12
#define As5 13
#define B5 14

#define C6 15
#define Cs6 16
#define D6 17
#define Ds6 18
#define E6 19
#define F6 20
#define Fs6 21
#define G6 22
#define Gs6 23
#define A6 24
#define As6 25
#define B6 26

#define C7 27
#define Cs7 28
#define D7 29
#define Ds7 30
#define E7 31
#define F7 32
#define Fs7 33
#define G7 34
#define Gs7 35
#define A7 36
#define As7 37
#define B7 38

#define C8 39
#define Cs8 40
#define D8 41
#define Ds8 42
#define E8 43
#define F8 44
#define Fs8 45
#define G8 46
#define Gs8 47
#define A8 48
#define As8 49
#define B8 50

struct note
{
	volatile int freq;
	volatile int duration;
};

void playNote(volatile int freq, volatile int duration);
void playSong(const struct note NOTES[], volatile int n);
int set_note(int freq);

#endif /* MUSICPLAYER_H */