/*
 * Interupt_1.c
 *
 * Created: 4/3/2019 10:40:15 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{
	DDRA = 0xff;
	DDRD = 0x00;
	PORTA = 0x00;
	PORTD = 0xff;
	
	MCUCR |= (1<<ISC01);
//	MCUCR |= (1<<ISC11);
	GICR  |= (1<<INT0);
	sei();
    while(1)
    {
        TOG_BIT(PORTA,0);
		_delay_ms(500);
    }
}

ISR(INT0_vect)
{
	if(GET_BIT(PIND,2) == 0)
	{
		CLR_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		cli();
	}
}