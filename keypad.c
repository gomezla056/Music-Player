#include "avr.h"

unsigned int is_pressed(int r, int c)
{
	// Set all rows and columns to N/C
	DDRC = 0;
	PORTC = 0;

	r += 4;

	// Set c to strong "0"
	SET_BIT(DDRC, c);
	CLR_BIT(PORTC, c);
	//avr_wait(5);

	// Set r to weak "1"
	CLR_BIT(DDRC, r);
	SET_BIT(PORTC, r);
	avr_wait(1);

	if(GET_BIT(PINC, r))
	{
		return 0;
	}
	return 1;
}

int get_key(void)
{
	int r, c;
	for(r = 0; r < 4; r++)
	{
		for(c = 0; c < 4; c++)
		{
			if(is_pressed(r, c))
			{
				return 1 + (c * 4) + r;
			}
		}
	}
	return 0;
}