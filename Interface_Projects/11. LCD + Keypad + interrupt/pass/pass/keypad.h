/*
 * keypad.h
 *
 * Created: 4/4/2019 1:33:55 PM
 *  Author: ammar
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>
#include "BasicTypes.h"
#include "BitMasking_Macros.h"


#define NO_PRESSED_KEY			100
#define KEYPAD_DIR				DDRC
#define KEYPAD_PORT				PORTC
#define KEYPAD_ROWS				PINC


void keypad_init();
int  KeyPad_getpressedkey(void);


#endif /* KEYPAD_H_ */