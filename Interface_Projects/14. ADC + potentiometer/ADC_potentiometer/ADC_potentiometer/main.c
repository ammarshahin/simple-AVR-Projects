/*
 * ADC_potentiometer.c
 *
 * Created: 4/16/2019 1:08:14 PM
 *  Author: ammar
 */ 

#include "main.h"

int main(void)
{
	TU16 x = 0;
	
	ADC_init();
	LCD_init();
	
    while(1)
    {
		x = ADC_read(0);
		LCD_Display_Number(x);
		_delay_ms(300);
		LCD_Clear();
    }
}