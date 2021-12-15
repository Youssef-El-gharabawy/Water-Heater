/*
 * BUTTONS.c
 *
 * Created: 12/15/2021 12:15:20 PM
 *  Author: youss
 */ 
#include "BUTTONS.h"



void Buttons_init(void)
{
	// to Set the pins as INPUT
	clr_bit(B_PORT_DIR,ON_OFF_PIN);
	clr_bit(B_PORT_DIR,UP_BUTTON_PIN);
	clr_bit(B_PORT_DIR,DOWN_BUTTON_PIN);
	
	// to enable Pull-Up Resistor
	
	set_bit(B_PORT,ON_OFF_PIN);
	set_bit(B_PORT,UP_BUTTON_PIN);
	set_bit(B_PORT,DOWN_BUTTON_PIN);
	
	
	// enable Global Interrupt
	sei();
	
	// Rising Edge
	set_bit(MCUCSR,ISC2);
	
	// Enable (INT2)
	set_bit(GICR,INT2);
}



// To Check if UP button is pressed or not and return the result.


unsigned char UP_BUTTON(void)
{
	// To Check if the button is pressed for the first time
	if(!(read_bit(PINB,UP_BUTTON_PIN))){
		// wait for 100 ms to make sure it's pressed 
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(read_bit(PINB,UP_BUTTON_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}


// Checks if DOWN button is pressed or not and return the result.


unsigned char DOWN_BUTTON(void)
{
	// Check if the button is pressed for the first time 
	if(!(read_bit(PINB,DOWN_BUTTON_PIN))){
		// wait for 100 ms to make sure it's pressed
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(read_bit(PINB,DOWN_BUTTON_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
