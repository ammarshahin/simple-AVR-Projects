/*  Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{   
	
	LCD_Init();
	
	
	LCD_SendString("karim");
	_delay_ms(2000);
	LCD_Clear(); // clear lcd
	
	LCD_SendString(" abdrahman");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_SendString_XY(" ISLAM Haggag",0,1);
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_SendString_XY("Embedded Systems Track",0,0);
	_delay_ms(2000);
	LCD_Clear();
	
	
	while(1)
	{	
		LCD_SendString_XY("Welcome Board", 0, 1);// print welcome board at X,Y
		_delay_ms(2000);
		LCD_Clear();
	}		
}


