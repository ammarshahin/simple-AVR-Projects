/*
 * ADC.h
 *
 * Created: 4/16/2019 1:10:42 PM
 *  Author: ammarPC
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "BitMasking_Macros.h"
#include "BasicTypes.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void ADC_init();
TU16 ADC_read(TU08 ch);

#endif /* ADC_H_ */