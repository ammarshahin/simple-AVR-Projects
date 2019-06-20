/*
 * LCD.h
 *
 * Created: 4/4/2019 3:39:49 PM
 *  Author: ammarPC
 */ 


#ifndef LCD_H_
#define LCD_H_


#define LCD_DATA_PORT PORTA
#define RS_LOC  2



#include "macros.h"
#include "BasicTypes.h"
#include "SSD.h"


#include <avr/io.h>
#include <util/delay.h>

void LCD_Init(void);
void LCD_SendData(TU08 data);
void LCD_Send_Command(TU08 cmd);
void LCD_Clear(void);
void LCD_GotoXY(TU08 x, TU08 y);
void LCD_SendString(char *str);
void LCD_SendString_XY(char *str, TU08 x, TU08 y);
char* convertData(unsigned int var);


#endif /* LCD_H_ */