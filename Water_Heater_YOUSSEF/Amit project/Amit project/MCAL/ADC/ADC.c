/*
 * ADC.c
 *
 * Created: 12/10/2021 3:45:23 PM
 *  Author: youss
 */ 
#include "ADC.h"


// to initialize the ADC 


void ADC_init()
{
	
	// selecting Vref
	set_bit(ADMUX,REFS0);
	
	// selecting channel 0
	clr_bit(ADMUX,MUX0);
	clr_bit(ADMUX,MUX1);
	clr_bit(ADMUX,MUX2);
	clr_bit(ADMUX,MUX3);
	clr_bit(ADMUX,MUX4);
	
	// leaving the data saving adjustment as default (right adjusted)
	clr_bit(ADMUX,ADLAR);
	
	// selecting the prescaller division number for ADC
	
	set_bit(ADCSRA,ADPS0);
	clr_bit(ADCSRA,ADPS1);
	clr_bit(ADCSRA,ADPS2);
	
	
	set_bit(ADCSRA,ADEN); // ADC enabling
	
}




uint16_t ADC_read()                     // data reading function of the analog sensor 
{
	
	uint16_t data;
	
	
	set_bit(ADCSRA,ADSC); // Start Conversion
	
	while(is_bit_clr(ADCSRA,ADIF));
	
	
	
	data = ADCL;           // Read Data from the ADC Data Register
	data |= (ADCH<<8);     // Read the Low register first
	
	
	set_bit(ADCSRA,ADIF); // Clear Flag 
	
	return data;
}