/*
 * LED_TOG.c
 *
 * Created: 3/30/2019 1:54:35 AM
 *  Author: ammar Shahin 
 */ 


#include "main.h"

int main(void)
{
	DDRA = 0x01;
	PORTA = 0xfe; //	PORTA = 0bxxxxxx10;
	
	TU08 flag = 1;
    
	while(1)
    {
		if((GET_BIT(PINA,1) == 0) && (flag))
		{
			TOG_BIT(PORTA,0);
			_delay_ms(500);
			flag = 0;
		}else if((GET_BIT(PINA,1) == 1))
		{
			flag = 1;
		}else
		{
			// Do nothing
		}
	}
}