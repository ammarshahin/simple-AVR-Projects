/*
 * main.h
 *
 * Created: 3/30/2019 1:55:58 AM
 *  Author: ammar
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define PASSWORD      1234
#define NO_OF_DIGITS   3  

#include "BitMasking_Macros.h"
#include "BasicTypes.h"
#include "SSD.h"
#include "LCD.h"
#include "keypad.h"

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>

TU08 passwordCheck(TU08);

#endif /* MAIN_H_ */