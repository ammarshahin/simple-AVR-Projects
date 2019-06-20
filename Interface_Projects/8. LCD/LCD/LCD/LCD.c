/*
 * LCD.c
 *
 * Created: 4/4/2019 3:39:41 PM
 *  Author: ammarPC
 */ 

#include "LCD.h"

void LCD_Init(void)
{
	// Set Data Port to be O/P
	DDRA = 0xFF;
	PORTA = 0x00;

	// Set Control Port to be O/P
	DDRB = 0x07;
	PORTB = 0x01;

	// Init LCD
	LCD_Send_Command(0x38); // 8 bit mode
	
	// LCD_on
	LCD_Send_Command(0x0C); // turn on LCD
}

void LCD_SendData(TU08 data)
{
	// Put Data on Port
	PORTA = data;
	
	// Set R/W to W
	PORTB = PORTB & 0xFD; // ~(1<<RS_LOC)
	
	// Set RS to Data
	PORTB = PORTB | 0x04;

	// E to be 0
	PORTB = PORTB & 0xFE;
	
	// Delay
	_delay_ms(1);
	
	// E to be 1
	PORTB = PORTB | 0x01;
	
	// Delay to let LCD Display Data
	_delay_ms(100);
}

void LCD_Send_Command(TU08 cmd)
{
	// Put Cmd on Port
	PORTA = cmd;
	
	// Set R/W to W
	PORTB &= 0xFD;
	
	// Set RS to Command
	PORTB = PORTB & 0xFB;

	// E to be 0
	PORTB = PORTB & 0xFE;
	
	_delay_ms(1); // Delay
	
	// E to be 1
	PORTB = PORTB | 0x01; 
	
	
	_delay_ms(100); // Delay to let LCD Execute Command
}

void LCD_Clear(void)
{
	// Send Clr command to LCD
	LCD_Send_Command(0x01);
}

void LCD_GotoXY(TU08 x, TU08 y)
{
	if(y == 0)
	{
		LCD_Send_Command(0x80 + x);
	}
	else
	{
		LCD_Send_Command(0x80 + 0x40 + x);
	}
}

void LCD_SendString(char *str)
{
	while(*str != '\0')
	{
		LCD_SendData(*str);
		str++;
	}
}

void LCD_SendString_XY(char *str, TU08 x, TU08 y)
{
	LCD_GotoXY(x, y);
	LCD_SendString(str); 
}

char* convertData(TU32 var)
{
	static char data[17];
	char* arr = &data[16];

	*arr = '\0';

	while(var != 0)
	{
		arr--;
		*arr = (var%10) + '0';
		var = var / 10;
	}
	return arr;
}