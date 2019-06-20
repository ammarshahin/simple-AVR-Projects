/*
 * 	SSD.h
 *
 * 	Created: 9-Apr-19
 *  Author:  Ammar Shahin
 */ 

#ifndef _SSD_H_
#define _SSD_H_

#include <avr/io.h>
#include "BasicTypes.h"
#include "BitMasking_Macros.h"


#define SSD_DIR   DDRB
#define SSD_PORT  PORTB
#define SSD_COMMAN_CATHODE
//#define SSD_COMMAN_ANODE

typedef enum{
	A = 10 ,
	B      ,
	C      ,
	D      ,
	E      ,
	F      ,
}symbole;

void SSD_Init();
void SSD_Display(TU08 number);


#endif // _SSD_H_ INCLUDED