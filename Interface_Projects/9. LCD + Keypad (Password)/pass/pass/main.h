/*
 * main.h
 *
 * Created: 3/30/2019 1:55:58 AM
 *  Author: ammarPC
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define PASSWORD  1234
#define NO_OF_DIGITS 3  

#include "macros.h"
#include "BasicTypes.h"
#include "SSD.h"
#include "LCD.h"
#include "keypad.h"

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

TU08 passwordCheck(TU08);
void SSD_init(void);

#endif /* MAIN_H_ */