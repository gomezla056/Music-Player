#include "avr.h"
#include "musicPlayer.h"
#include "keypad.h"
#include "lcd.h"

void set_lcd(char* s)
{
	char buf[25];
	sprintf(buf,"%s",s);
	lcd_pos(0,0);
	lcd_puts2(buf);
}

int main(void)
{
	avr_init();
	
    const struct note NOTES[] = {
		{set_note(0), H},	// A4
		{set_note(1), H},	// A#4/Bb4
		{set_note(2), H},	// B4/Cb4
		{set_note(3), H},	// B#4/C4
		{set_note(4), H},	// C#4/Db4
		{set_note(5), H},	// D4
		{set_note(6), H},	// D#4/Eb4
		{set_note(7), H},	// E4/Fb4
		{set_note(8), H},	// F4
		{set_note(9), H},	// F#4/Gb4
		{set_note(10), H},	// G4
		{set_note(11), H}	// G#4/Ab4
	};
	
	const struct note KingOfTheKill[] = {
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(Gs3), S},
		{set_note(G3), S},
		{set_note(D3), S},
		{set_note(G3), S},
		{set_note(F3), S},
		{set_note(D3), S},
		{set_note(D3), S},
			
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D3), S},
		{set_note(C4), E},
		{set_note(D4), E},
		{set_note(D4), E},
			
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(Gs3), S},
		{set_note(G3), S},
		{set_note(D3), S},
		{set_note(G3), S},
		{set_note(F3), S},
		{set_note(D3), S},
		{set_note(D3), S},
		
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D4), S},
		{set_note(C4), S},
		{set_note(D3), S},
		{set_note(D3), S},
		{set_note(C4), E},
		{set_note(D4), E},
		{set_note(D4), E}
		};
	
	const struct note Bliss[] = {
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(Ds5), E},
		{set_note(E5), E},
		{set_note(Ds5), E},
		{set_note(E5), E},
			
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(Ds5), E},
		{set_note(E5), E},
		{set_note(Ds5), E},
		{set_note(E4), E},
		
		{set_note(Fs4), E},
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(Fs4), E},
		{set_note(Fs4), E},
			
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(E4), E},
			
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(Ds5), E},
		{set_note(E5), E},
		{set_note(Ds5), E},
		{set_note(E5), E},
		
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(Ds5), E},
		{set_note(E5), E},
		{set_note(Ds5), E},
		{set_note(E4), E},
		
		{set_note(Fs4), E},
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(Fs4), E},
		{set_note(Fs4), E},
		
		{set_note(A4), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(E5), E},
		{set_note(B4), E},
		{set_note(A4), E},
		{set_note(E4), W}
		};
	
	volatile int n = sizeof(NOTES)/sizeof(NOTES[0]);
	volatile int n2 = sizeof(KingOfTheKill)/sizeof(KingOfTheKill[0]);
	volatile int n3 = sizeof(Bliss)/sizeof(Bliss[0]);
	SET_BIT(DDRA, 1);
	SET_BIT(PORTA, 1);
	lcd_init();
    while (1) 
    {
		int key = get_key();
		avr_wait(100);
		if(1 == key)
		{
			lcd_clr();
			char*song ="Chromatic Scale";
			set_lcd(song);
			playSong(NOTES, n);
		}
		else if(2 == key)
		{
			lcd_clr();
			char*song ="King Of The Kill";
			set_lcd(song);
			playSong(KingOfTheKill, n2);
		}
		else if(3 == key)
		{
			lcd_clr();
			char * song ="Bliss";
			set_lcd(song);
			playSong(Bliss, n3);
		}
    }
}

