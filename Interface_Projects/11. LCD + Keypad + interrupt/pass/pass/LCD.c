/*
 * 	LCD.c
 *
 * 	Created: 9/4/2019
 *  Author: Ammar Shahin
 */ 

#include "LCD.h"

TU08 counter=0;
TU08 flag_4bit=1;


void LCD_init()
{
	#ifdef EIGHT_BIT_MODE
		data_dir |= data_port_init_8bit;
		control_dir |= (1<<RS)|(1<<RW)|(1<<EN);
		LCD_send_comand(SET_MODE_8bit);
		LCD_send_comand(clear_lcd);
		LCD_send_comand(cursor_off);
	#endif
	
	#ifdef FOUR_BIT_MODE
		data_dir|=data_port_init_4bit;
		control_dir|= (1<<RS)|(1<<RW)|(1<<EN);
		LCD_send_comand(SET_MODE_4bit);
		LCD_send_comand(clear_lcd);
		LCD_send_comand(cursor_off);
	#endif
}


void LCD_send_comand(TU08 command)
{
	#ifdef EIGHT_BIT_MODE
		CLR_BIT(control_port,RS);        // RS
		CLR_BIT(control_port,RW);		// RW
		_delay_ms(1);				   // Delay
		SET_BIT(control_port,EN);	  // Enable
		_delay_ms(1);                // Delay
		data_port=command;
		_delay_ms(1);
		CLR_BIT(control_port,EN);		 // Disable
		_delay_ms(1);					// Delay
	#endif
	
	#ifdef FOUR_BIT_MODE
	if ( 1 == flag_4bit)
	{
		flag_4bit=0;
		CLR_BIT(control_port,RS);     // RS
		CLR_BIT(control_port,RW);		// RW
		_delay_ms(1);					// Delay
		SET_BIT(control_port,EN);		// Enable
		_delay_ms(1);                   // Delay
		data_port=(data_port & 0x0f)|(command & 0xf0);
		_delay_ms(1);
		CLR_BIT(control_port,EN);		// Disable
		_delay_ms(1);					// Delay
	}
	else if ( 0 == flag_4bit)
	{
		 data_port= (data_port & 0x0f) | (command & 0xf0); //MSB of command on P0-P3
		 CLR_BIT(control_port,RS);
		 CLR_BIT(control_port,RW);
		 SET_BIT(control_port,EN);
		 _delay_ms(2);
		 CLR_BIT(control_port,EN);
		 _delay_ms(2);
		 data_port=(data_port & 0x0f) | (command<<4); //LSB of command on P0-P3
		 CLR_BIT(control_port,RS);
		 CLR_BIT(control_port,RW);
		SET_BIT(control_port,EN);
		_delay_ms(2);
		CLR_BIT(control_port,EN);
		_delay_ms(2);
	}
	#endif
}


void LCD_Display(char Data)
{
	#ifdef EIGHT_BIT_MODE
		counter++;
		if(counter == 17)
			LCD_send_comand(force_cursor_begin_second_line);
		if(counter==33)
		{
			counter=0;
			LCD_send_comand(force_cursor_begin_first_line);
		}
		SET_BIT(control_port,RS);			
		CLR_BIT(control_port,RW);			
		_delay_ms(1);						
		SET_BIT(control_port,EN);			
		_delay_ms(1);						
		data_port=Data;				        
		_delay_ms(1);						
		CLR_BIT(control_port,EN);			
		_delay_ms(1);
	#endif
	
	#ifdef FOUR_BIT_MODE
		counter++;
		if(counter==17)
			LCD_send_comand(force_cursor_begin_second_line);
		if(counter==33)
		{
			counter=0;
			LCD_send_comand(force_cursor_begin_first_line);
		}
		data_port=(data_port & 0x0f)|(Data & 0xf0);
		SET_BIT(control_port,RS);
		CLR_BIT(control_port,RW);
		SET_BIT(control_port,EN);	
		_delay_ms(2);
		CLR_BIT(control_port,EN);
		_delay_ms(2);

		data_port=(data_port & 0x0f)|(Data<<4);
		SET_BIT(control_port,RS);
		CLR_BIT(control_port,RW);
		SET_BIT(control_port,EN);
		_delay_ms(2);
		CLR_BIT(control_port,EN);
		_delay_ms(2);
	#endif				
}

void LCD_Goto_XY(TU08 line,TU08 position)
{
	if(position>=0 && position<=16)
	{
	 if (0==line)
	 {
		LCD_send_comand( force_cursor_begin_first_line + position);
		counter = position;
	 }
	 else if (1==line)
	 {
		LCD_send_comand( force_cursor_begin_second_line + position);
		counter = 16 + position;
	 }
	}
}

void LCD_Display_String(char arr[])
{
	TU08 a = 0;
	while (arr[a]!='\0')
	{
		LCD_Display(arr[a]);
		a ++;
	}
}


void LCD_Display_Number(TU16 number)
{
	char array[7];
	itoa(number , array,10);
	LCD_Display_String(array);
}


void LCD_Display_RealNumnber(double number)
{
	char str[16];
	char* sign=(number>0) ? "" : "-";
	float val= (number>0) ? number : -number;
	int num = val;
	float fraction = val-num;
	int frac = fraction * 10000;
	sprintf(str, "%s%d.%d",sign, num, frac);
	LCD_Display_String(str);
}

void LCD_Clear()
{
	LCD_send_comand(clear_lcd);
	counter=0;
}