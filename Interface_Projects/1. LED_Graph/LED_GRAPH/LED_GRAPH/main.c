/*
 * LED_GRAPH.c
 *
 * Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{
	DDRA = 0x0f;
	PORTA = 0xf0;
    while(1)
    {
		if( GET_BIT(PINA,7) == 0)
		{
			SET_BIT(PORTA,0);
			_delay_ms(500);
			SET_BIT(PORTA,1);
			_delay_ms(500);
			SET_BIT(PORTA,2);
			_delay_ms(500);
			SET_BIT(PORTA,3);
			_delay_ms(500);
			CLR_LOWER_NIBBLE(PORTA);
			SET_BIT(PORTA,0);
			SET_BIT(PORTA,1);
			_delay_ms(500);
			SET_BIT(PORTA,2);
			_delay_ms(500);
			SET_BIT(PORTA,3);
			_delay_ms(500);
			CLR_LOWER_NIBBLE(PORTA);
			SET_BIT(PORTA,0);
			SET_BIT(PORTA,1);
			SET_BIT(PORTA,2);
			_delay_ms(500);
			SET_BIT(PORTA,3);
			_delay_ms(500);
			CLR_LOWER_NIBBLE(PORTA);
		}else
		{
			CLR_LOWER_NIBBLE(PORTA);
	//		_delay_ms(500);
		}	
	}
}