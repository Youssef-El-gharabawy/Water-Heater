/*
 * EEPROM.c
 *
 * Created: 12/10/2021 6:31:13 PM
 *  Author: youss
 */ 
#include "EEPROM.h"





unsigned char EEPROM_read(const unsigned short addr)  // reading the data from the EEPROM given by the Address.
{
	
	EEARL = (char)addr;                 // setting the Address of the Register
	EEARH = (char)(addr>>8);
	
	
	set_bit(EECR,EERE);                 // Reading the data
	
	
	return EEDR;                        // Return Data
}





void EEPROM_write(const unsigned short addr, unsigned char data)    // reading the data from the EEPROM given by the Address.
{
	unsigned char INT_EN=0;
	
	
	EEARL = (char)addr;         // Setting the Address of Register
	EEARH = (char)(addr>>8);
	
	
	EEDR = data;                 // sending the data to the Data Register
	
	
	if(((SREG&(1<<7))>>7)==1)      // Disabling the Interrupts for better performance
	{
		INT_EN = 1;
		clr_bit(SREG,7);
	}
	
	// Start Writing
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	
	if (INT_EN==1)
	{
		set_bit(SREG,7);
	}
	
}