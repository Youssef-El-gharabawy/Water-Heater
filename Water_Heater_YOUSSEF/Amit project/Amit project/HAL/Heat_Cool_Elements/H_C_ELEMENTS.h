/*
 * H_C_ELEMENTS.h
 *
 * Created: 12/15/2021 12:17:02 PM
 *  Author: youss
 */ 


#ifndef H_C_ELEMENTS_H_
#define H_C_ELEMENTS_H_


#include <avr/io.h>

#define HEATER_PORT_DIR DDRB
#define HEATER_PORT PORTB
#define HEATER_PIN 4

#define COOLER_PORT_DIR DDRB
#define COOLER_PORT PORTB
#define COOLER_PIN 5

void heater_init(void);
void heater_on(void);
void heater_off(void);

void cooler_init(void);
void cooler_on(void);
void cooler_off(void);


#endif /* H_C_ELEMENTS_H_ */