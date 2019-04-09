#include "musicPlayer.h"
#include "avr.h"
#include "keypad.h"

int set_note(int freq)
{
	double new_freq =  (double) freq/12;
	double power = pow(2.0, new_freq);
	return power * 440;
}
void playNote(volatile int freq, volatile int duration)
{
	volatile int i;
	double tH, tL;
	tH = tL = 100000/freq;
	double cycles = 340.29/tH;
	for(i = 0; i < (duration * cycles); i++)
	{
		SET_BIT(PORTA, 1);
		avr_nano(tH/2);
		CLR_BIT(PORTA, 1);
		avr_nano(tL/2);
	}
}

void playSong(const struct note NOTES[], volatile int n)
{
	volatile int i;
	for(i = 0; i < n; i++)
	{
		playNote(NOTES[i].freq, NOTES[i].duration);
	}
}