/*
 * main.c
 *
 * Created: 4/2/2019 9:12:19 PM
 *  Author: ammar
 */ 

#include "main.h"

int main()
{
	TU08 flag = 1;
	DDRA = 0xff;
	DDRB = 0x00;
	PORTA = 0x00;
	PORTB = 0xff;

	while(1)
	{
	
		if((GET_BIT(PINB,1) == 0) && (GET_BIT(PINB,0) == 0))
		{
			CLR_BIT(PORTA,0);
			CLR_BIT(PORTA,1);
			flag =0;
		}
		else if(flag  && (GET_BIT(PINB,0) == 0))
		{
			CLR_BIT(PORTA,1);
			SET_BIT(PORTA,0);
			flag = 0;
			_delay_ms(1000);
		}
		else if(flag  && (GET_BIT(PINB,1) == 0) )
		{
			CLR_BIT(PORTA,0);
			SET_BIT(PORTA,1);
			flag = 0;
			_delay_ms(1000);
		}
		else if((GET_BIT(PINB,1) == 1) && (GET_BIT(PINB,0) == 1))
		{
			CLR_BIT(PORTA,0);
			CLR_BIT(PORTA,1);
			flag = 1;
		}
		else
		{
			// Do nothing
		}
	}	
	return 0;
}
