/*
 * ADC.c
 *
 * Created: 8/16/2019 12:26:48 AM
 *  Author: Mina
 */ 

#include "ADC.h"
#include <avr/io.h>

void ADC_vInit(void)
{
	ADMUX = (1<<REFS0) | (1<<MUX0);							//select vref as vcc
	ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);		//ADC enable & prescalar
		

#if 0
	ADCSRA = (1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
	ADCSRA |= (1<<ADPS0);
		
	ADMUX = (1<<REFS0) ;
	ADMUX |= (1<<MUX0);
	/*The ADC generates a 10-bit result which is presented in the ADC Data Registers, ADCH and ADCL.*/
	/*The ADC is enabled by setting the ADC Enable bit, ADEN in ADCSRA*/
	ADCSRA |= (1<<ADEN);
#endif
}

unsigned short ADC_u16Read(void)
{
	volatile short x = 0 ;
	
	/*ADC Start Conversion*/
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADIF) ) == 0); /* wait for conversion to complete ADIF becomes '1' */
	
	x = ADCL;
	x |= (ADCH <<8);

	return ADC;
}
