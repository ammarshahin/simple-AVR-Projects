///*
 //* main.c
 //*
 //* Created: 4/11/2019 11:43:38 PM
 //*  Author: ammarPC
 //*/ 
//
#include "main.h"

TS08 counter = 0;

int main(void)
{
	Output_init(A,0);
	Output_init(A,1);
	
	SET_BIT(SREG,7);       // Enable the Global Interrupt
	SET_BIT(TIMSK,TOIE0); // Enable the Overflow Interrupt

/* set the mode to be normal mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
/* set the value of the prescaler to = 1024 */	
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);

    while(1)
    {
		TOG_BIT(PORTA,1);
		//_delay_ms(100);
		if( counter >= 30)
		{
			TOG_BIT(PORTA,0);
			counter = 0;
		}
    }
}

ISR(TIMER0_OVF_vect)
{
	counter++;
}