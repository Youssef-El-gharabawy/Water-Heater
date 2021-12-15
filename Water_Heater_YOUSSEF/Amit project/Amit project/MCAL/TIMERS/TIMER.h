/*
 * TIMER.h
 *
 * Created: 12/10/2021 9:10:33 PM
 *  Author: youss
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_MACROS.h"

void timer1_init();
void timer0_init();
void timer1_disable();
void timer1_enable();



#endif /* TIMER_H_ */