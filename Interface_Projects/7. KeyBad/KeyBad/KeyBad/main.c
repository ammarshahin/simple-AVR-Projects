/*  Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{
	int key;
	DDRC=0xff;
	PORTA=0x00;
	
	keypad_init();

	while(1)
	{
		key = KeyPad_getpressedkey();
	//	display_BCD(key);
	 
	if (key != NO_PRESSED_KEY)
		PORTC = key;
	}
}

