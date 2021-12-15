/*
 * ADC.h
 *
 * Created: 12/10/2021 3:45:47 PM
 *  Author: youss
 */  


#ifndef ADC_H_
#define ADC_H_


#include <avr/io.h>
#include "STD_MACROS.h"

void ADC_init(void);
uint16_t ADC_read(void);



#endif /* ADC_H_ */