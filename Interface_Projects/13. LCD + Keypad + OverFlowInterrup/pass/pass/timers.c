/*
 * timers.c
 *
 * Created: 4/16/2019 11:45:21 AM
 *  Author: ammarPC
 */ 

#include "timers.h"

void Timer0_init()
{
	SET_BIT(SREG,7);       // Enable the Global Interrupt
	SET_BIT(TIMSK,TOIE0); // Enable the Overflow Interrupt

	/* set the mode to be normal mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	/* set the value of the prescaler to = 1024 */
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	
}
