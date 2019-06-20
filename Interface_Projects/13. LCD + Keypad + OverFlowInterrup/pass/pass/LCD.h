/*
 * LCD.h
 *
 * Created: 9/4/2019 07:53:52 م
 *  Author: Ammar Shahin
 */ 

#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "BitMasking_Macros.h"
#include "BasicTypes.h" 

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE


#ifdef EIGHT_BIT_MODE

	#define RS PB2
	#define RW PB1
	#define EN PB0
	#define control_dir DDRB
	#define control_port PORTB
	#define data_dir DDRA
	#define data_port PORTA
	#define data_port_init_8bit 0xff

#endif //EIGHT_BIT_MODE


#ifdef FOUR_BIT_MODE

	#define RS PB2
	#define RW PB1
	#define EN PB0
	#define control_dir DDRB
	#define control_port PORTB
	#define data_dir DDRA
	#define data_port PORTA
	#define data_port_init_4bit 0xf0

#endif //FOUR_BIT_MODE


                                             /*LCD_MODES*/
#define SET_MODE_8bit         0x38
#define SET_MODE_8bit_1_LINE  0x30
#define SET_MODE_4bit         0x28
#define SET_MODE_4bit_1_LINE  0x20

                                             /*LCD Commands*/
#define cursor_off                          0x0c //display on also
#define clear_lcd                           0x01
#define return_home                         0x02
#define shift_cursor_left                   0x04
#define shift_display_Right_password        0x05
#define shift_cursor_Right_password         0x06
#define shift_display_left                  0x07
#define lcd_off                             0x08 //cursor off also
#define lcd_on                              0x0f //cursor on also
#define cursor_blinking                     0x0E
#define force_cursor_begin_first_line       0x80
#define force_cursor_begin_second_line      0xc0
#define jump_second_line_position_1         0xc1
#define jump_second_line_position_2         0xc2



void LCD_init();
void LCD_send_comand(TU08);
void LCD_Display(char);
void LCD_Display_String(char arr[]);
void LCD_Display_Number(TU16);
void LCD_Clear();
void LCD_Display_RealNumnber(double);
void LCD_Goto_XY(TU08,TU08);



#endif /* LCD_H_ */

