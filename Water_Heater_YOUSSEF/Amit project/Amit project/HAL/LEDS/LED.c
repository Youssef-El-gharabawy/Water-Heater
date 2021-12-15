/*
 * LED.c
 *
 * Created: 12/15/2021 12:17:30 PM
 *  Author: youss
 */ 
#include "LED.h"


// init. led by making it an output pin.


void led_init(void)
{
	
	// PIN 0 in the port ------> output pin
	// the LED pin is off at the start
	
	set_bit(LED_PORT_DIR,LED_PIN);
	clr_bit(LED_PORT,LED_PIN);

}


// to turn on LED.


void led_on(void)
{
	set_bit(LED_PORT,LED_PIN);
}

// to turn off LED.

void led_off(void)
{
	clr_bit(LED_PORT,LED_PIN);
}
