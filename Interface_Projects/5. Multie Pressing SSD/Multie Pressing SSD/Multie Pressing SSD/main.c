/*  Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{
	TU08 i=0;
	DDRA = 0x00;
	PORTA = 0xff;
	DDRC = 0xff;
	PORTC =  0xc0;
    while(1)
    {
		if( (GET_BIT(PINA,0) == 0) && i < 10)
		{
		display(i);
		i++;
		_delay_ms(500);			
		}
		else if(i>9)
		{
			i=0;
		}
		else
		{
			// Do Nothing
		}
	}
}


void display(TU08 i)
{
	switch(i)
	{
		case 0 : 
			PORTC = 0xc0;
			break;
		case 1 :
			PORTC = 0xf9;
			break;
		case 2 :
			PORTC = 0xa4;
			break;
		case 3 :
			PORTC = 0xb0;
			break;
		case 4 :
			PORTC = 0x99;
			break;
		case 5 :
			PORTC = 0x92;
			break;
		case 6 :
			PORTC = 0x82;
			break;
		case 7 :
			PORTC = 0xf8;
			break;
		case 8 :
			PORTC = 0x80;
			break;
		case 9 :
			PORTC = 0x90;
			break;
		default:
			break;
	}
}