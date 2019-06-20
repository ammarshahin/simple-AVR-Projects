/*
 * ADC.c
 *
 * Created: 4/16/2019 1:10:24 PM
 *  Author: ammarPC
 */ 

#include "ADC.h"

void ADC_init()
{
/* Enable the ADC peripheral */
	SET_BIT(ADCSRA,ADEN);    
	
/* Set the prescaler value to 128 */
	SET_BIT(ADCSRA,ADPS2);    
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
	
	SET_BIT(ADCSRA,ADIE);	// Enable the ADC Interrupt
	SET_BIT(SREG,7);       // Enable the Global Interrupt
	 
	//SET_BIT(ADMUX,ADLAR);   // select left justified 
	//SET_BIT(ADMUX,REFS0);   // Set V(ref) to be == V(cc)

}


TU16 ADC_read(TU08 ch)
{
	ch &= 0b00000111; // channel must be b/w 0 to 7
	ADMUX = (ADMUX & 0xF0) | ch; // selecting channel
	
	SET_BIT(ADCSRA,ADSC);  // start conversion
	
	while( GET_BIT(ADCSRA,ADIF) == 0); // waiting for ADIF, conversion complete
	
	SET_BIT(ADCSRA,ADIF); // clearing of ADIF, it is done by writing 1 to it
	
	return ADC;
}
