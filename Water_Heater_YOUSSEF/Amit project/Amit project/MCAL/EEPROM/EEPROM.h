/*
 * EEPROM.h
 *
 * Created: 12/10/2021 6:31:58 PM
 *  Author: youss
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "STD_MACROS.h"

void EEPROM_write(const unsigned short addr, unsigned char data);
unsigned char EEPROM_read(const unsigned short addr);




#endif /* EEPROM_H_ */