/*
 * TIMER.c
 *
 * Created: 12/10/2021 9:10:19 PM
 *  Author: youss
 */ 
#include "Timer.h"






void timer1_init()
{

	
	set_bit(TCCR1B,WGM12);      // CTC Mode
	
	
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	
	// Clock Prescaler (1024)
	set_bit(TCCR1B,CS10);
	clr_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
	
	
	sei();                     // Enable Global Interrupt bit

}





void timer0_init()
{
	
	// choose mode
	set_bit(TCCR0,WGM01);
	
	// Load Value in OCR0
	OCR0 = 250;
	
	// Choose Prescaler
	set_bit(TCCR0,CS00);
	set_bit(TCCR0,CS02);
	
	// Enable Timer INT
	sei();
	set_bit(TIMSK,OCIE0);
	
}


// stopping timer1 from triggering INTERRUPTS.


void timer1_disable()
{
	
	
	clr_bit(TIMSK,OCIE1A);  // when Comparing with values A and B Disable the timer Interrupts 
	
}





void timer1_enable()               // to start timer(1) 
{
	
	
	set_bit(TIMSK,OCIE1A); // when Comparing with values A and B enable the timer Interrupts 
	
}