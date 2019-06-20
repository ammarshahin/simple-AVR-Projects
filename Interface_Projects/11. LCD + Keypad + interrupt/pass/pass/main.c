/*  Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

TU08 flag = 0;

int main(void)
{   
	TU08 i = 0,key = 0,k = 0;
	
	LCD_init();
	keypad_init();
	SSD_init();
		
	LCD_Display_String("enter your password");
	
	MCUCR |= (1<<ISC01);
	GICR  |= (1<<INT0);
	sei();
	
	//cli();   // turn off all global interrupts 
	while(1)
	{	
		while( (flag = 1) && GET_BIT(PIND,2) == 0)
		{
			LCD_Clear();
			LCD_Display_String("interrupt is coming!!");
			_delay_ms(500);
			if(GET_BIT(PIND,2) == 1)
			{
				flag = 0;
				LCD_Clear();
				LCD_Display_String("enter your password");
			}
				
		}
		
		k = KeyPad_getpressedkey();
		if(k != 100)
			SSD_Display_BCD(k);
		key = passwordCheck(k);
		
	//	key = 1;
		if(key == 1)
		{
			LCD_Clear();
			LCD_Display_String("correct ^_^");
			_delay_ms(200);
			LCD_Clear();
			LCD_Display_String("Press The Switch");

			do
			{
				i=0;
				if(GET_BIT(PIND,0) == 0)
				{
					LCD_Clear();
					LCD_Display_String("Loading...");
					
					for(i=0; i < 10 ; i++)
					{
						SSD_Display_BCD(i);
						_delay_ms(200);
					}				
					LCD_Clear();
					LCD_Display_String("Done!");
					_delay_ms(1000);
				}
				if( i > 9 ){
					break;
				}
			}while(1);
			
			LCD_Clear();
			LCD_Display_String("enter your password");
			SSD_Display_BCD(0);
		}
	}		
}

TU08 passwordCheck(TU08 key)
{
	static TS08 count = NO_OF_DIGITS;
	static TS16 pass = 1;
	
	if(key != 100)
	{
		if( count >= 0 )
		{
			pass +=  key * pow(10,count);
			count--;
		}
		else
		{
			LCD_Clear();
			SSD_Display_BCD(0);
			LCD_Display_String("Invalid password!!!");
			_delay_ms(300);
			count = NO_OF_DIGITS;
			pass = 1;
			LCD_Clear();
			LCD_Display_String("enter your password");
		}
	}
/* An attempt to show the Password on the screen */
/*	LCD_Clear();
	char *ptr = convertData(pass);
	LCD_SendString(ptr);  */

	if (pass == PASSWORD)
	{
		count = NO_OF_DIGITS;
		pass = 1;
		return 1;
	}
	else
	{
		return 0;	
	}
}


ISR(INT0_vect)
{
	if(GET_BIT(PIND,2) == 0)
	{
		flag = 1;
	}
}