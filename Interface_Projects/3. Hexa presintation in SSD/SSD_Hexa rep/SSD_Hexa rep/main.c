/*
 * LED_GRAPH.c
 *
 * Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{
	DDRA = 0xff;
	PORTA = 0x00;
	DDRD = 0xff;
	PORTD = 0x00;	
	DDRB = 0x00;
	PORTB = 0xff;
    while(1)
    {
		PORTA = ~PINB;
		PORTD = ~PINB;
		_delay_ms(500);
	}
}