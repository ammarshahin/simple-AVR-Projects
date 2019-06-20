/*
 * Switch.c
 *
 * Created: 4/14/2019 6:37:05 PM
 *  Author: ammarPC
 */ 

#include "PinConfig.h"

void Switch_init(PORTS Port , TU08 pin)
{
	switch(Port)
	{
		case pA : 
			CLR_BIT(DDRA,pin);
			SET_BIT(PORTA,pin);
			break;
		case pB :
			CLR_BIT(DDRB,pin);
			SET_BIT(PORTB,pin);
			break;
		case pC :
			CLR_BIT(DDRC,pin);
			SET_BIT(PORTC,pin);
			break;
		case pD :
			CLR_BIT(DDRD,pin);
			SET_BIT(PORTD,pin);
			break;
		default: 
			break;
	}	
}

void Output_init(PORTS Port , TU08 pin)
{
	switch(Port)
	{
		case pA :
			SET_BIT(DDRA,pin);
			CLR_BIT(PORTA,pin);
			break;
		case pB :
			SET_BIT(DDRB,pin);
			CLR_BIT(PORTB,pin);
			break;
		case pC :
			SET_BIT(DDRC,pin);
			CLR_BIT(PORTC,pin);
			break;
		case pD :
			SET_BIT(DDRD,pin);
			CLR_BIT(PORTD,pin);
			break;
		default:
			break;
	}
}