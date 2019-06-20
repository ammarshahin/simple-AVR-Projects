/*  Created: 3/30/2019 1:54:35 AM
 *  Author: ammarPC
 */ 


#include "main.h"

int main(void)
{   
	TU08 i = 0,key,k;
	
	LCD_Init();
	keypad_init();
	SSD_init();

	LCD_SendString_XY("enter your",0,0);
	LCD_SendString_XY("password: ",0,1);
	
	while(1)
	{	
		
		k = KeyPad_getpressedkey();
		display_BCD(k);
		key = passwordCheck(k);
		
	//	key = 1;
		if(key == 1)
		{
			LCD_Clear();
			LCD_SendString("correct ^_^");
			LCD_SendString_XY("Press The Switch",0,1);

			do
			{
				if(GET_BIT(PINC,4) == 0)
				{
					LCD_Clear();
					LCD_SendString("Loading...");
					
					for(i=0; i < 10 ; i++)
					{
						display_BCD(i);
						_delay_ms(500);
					}				
					LCD_Clear();
					LCD_SendString("Done!");
					_delay_ms(1000);
				}
				if( i > 9 ){
					break;
				}
			}while(1);
			
			LCD_Clear();
			SSD_init();
			LCD_SendString_XY("enter your",0,0);
			LCD_SendString_XY("password: ",0,1);
		}
	}		
}

TU08 passwordCheck(TU08 key)
{
	static TS08 count = NO_OF_DIGITS;
	static TS16 pass = 1;
	
	if(key != 0)
	{
		if( count >= 0 )
		{
			pass +=  key * pow(10,count);
			count--;
		}
		else
		{
			LCD_Clear();
			SSD_init();
			LCD_SendString_XY("Invalid",0,0);
			LCD_SendString_XY("password!!!",0,1);
			_delay_ms(500);
			count = NO_OF_DIGITS;
			pass = 1;
			LCD_Clear();
			LCD_SendString_XY("enter your",0,0);
			LCD_SendString_XY("password: ",0,1);
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

void SSD_init(void)
{
	DDRC = 0x0f;
	PORTC = 0xf0;
	display_BCD(0);
}