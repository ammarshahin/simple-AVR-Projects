/*
 * 	SSD.h
 *
 * 	Created: 9-Apr-19
 *  Author:  Ammar Shahin
 */ 

#ifndef _SSD_H_
#define _SSD_H_

#include <avr/io.h>
#include <util/delay.h>
#include "BasicTypes.h"
#include "BitMasking_Macros.h"


#define SSD_DIR   DDRD
#define SSD_PORT  PORTD
//#define SSD_COMMAN_CATHODE
//#define SSD_COMMAN_ANODE

typedef enum{
	A = 10 ,
	B      ,
	C      ,
	D      ,
	E      ,
	F      ,
}symbole;

void SSD_init();
void SSD_Display_8Bit(TU08);
void SSD_Display_BCD(TU08);


#endif // _SSD_H_ INCLUDED