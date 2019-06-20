/*
 * LCD_UART_RECIEVE.c
 *
 * Created: 13-Apr-19 7:36:44 AM
 * Author : Ammar Shahin
 */ 

#include "main.h"

int main(void)
{
	sei();
	UART_Init();
	SSD_Init();
    TU08 ch;
    while (1) 
    {
		ch = UART_Recieve();
		if (ch != '\0')
		{
			SSD_Display_BCD(ch);   
		}	
    }
}

