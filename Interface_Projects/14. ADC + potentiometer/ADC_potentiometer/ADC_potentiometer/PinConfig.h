/*
 * Switch.h
 *
 * Created: 4/14/2019 6:38:15 PM
 *  Author: ammarPC
 */ 


#ifndef _PINCONFIG_H_
#define _PINCONFIG_H_

#include <avr/io.h>
#include "BitMasking_Macros.h"
#include "BasicTypes.h"

typedef enum{pA,pB,pC,pD}PORTS;
	
void Switch_init(PORTS,TU08);
void Output_init(PORTS,TU08);
	
#endif /* _PINCONFIG_H_ */