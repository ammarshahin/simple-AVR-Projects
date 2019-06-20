/*  Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

volatile TU08 counter1 = 0 ,flag = 0;

int main(void)
{   
	TU08 i = 0,key = 0,k = 0;
	
	LCD_init();
	keypad_init();
	SSD_init();
	Output_init(pB,3);
	Timer0_init();
		
	LCD_Display_String("enter your password");
	
	while(1)
	{
		k = KeyPad_getpressedkey();
		if(k != 100)
			SSD_Display_BCD(k);
		key = passwordCheck(k);
		
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
		
		if(flag == 1)
		{
			TOG_BIT(PORTB,3);
			LCD_Clear();
			LCD_Display_String("OverFlow");
			LCD_Goto_XY(1,0);
			LCD_Display_String("Interrupt!!");
			_delay_ms(500);
			
			LCD_Clear();
			LCD_Display_String("enter your password");
			flag = 0; 
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


ISR(TIMER0_OVF_vect)
{
	if( ++counter1 > 12)
	{
		flag = 1;
		counter1 = 0;
	}
}