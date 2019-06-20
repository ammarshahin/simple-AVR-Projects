/*
 * keypad.h
 *
 * Created: 4/4/2019 1:33:55 PM
 *  Author: ammarPC
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>
#include "BasicTypes.h"
#include "macros.h"


#define NO_PRESSED_KEY			100
#define KEYPAD_PORT				PORTA
#define KEYPAD_ROWS				PINA
#define CLR_BIT(reg,index)		(reg &= (~(1<<index)))
#define SET_BIT(reg,index)		(reg |= (1<<index))
#define GET_LOWER_NIBBLE(reg)	(reg & 0x0f)

void keypad_init();
int KeyPad_getpressedkey(void);


#endif /* KEYPAD_H_ */