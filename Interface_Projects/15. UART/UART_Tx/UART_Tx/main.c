/*
 * BOTTON_UART_TRANSMIT.c
 *
 * Created: 13-Apr-19 7:34:28 AM
 * Author : Ammar Shahin
 */
 
#include "main.h"

int main(void)
{
	sei(); // Enable Global Interrupt
    Switch_init(pA,0);
	UART_Init();
	TU08 ch_count = 0;
    while (1)
    {
		//if ( GET_BIT(PINA,0) == 0)
		//{
		  
		  UART_Transmit(ch_count);
		  ch_count++;
		  if ( ch_count >= 10)
		  {
			  ch_count = 0;
		  }
		  _delay_ms(300);
		//}
    }
}

