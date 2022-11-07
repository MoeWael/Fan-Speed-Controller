 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the ADC AVR driver
 *
 * Author: Mohammad Wael
 *
 *******************************************************************************/

#include "adc.h"
#include <avr/io.h>

void ADC_Init(const ADC_ConfigType* Config_Ptr){
	/* Set VRef to Config_Ptr->ref_volt */
	ADMUX |= Config_Ptr->ref_volt;

	/* Turn ADC on (ADEN)
	 * Set Prescaler to Config_Ptr->prescaler */
	ADCSRA |= (1<<ADEN) | (Config_Ptr->prescaler);
}

uint16 ADC_read(uint8 channel){

	/* Clear ADC Channel */
	ADMUX &= ~(0x1F);

	/* Choose a channel */
	ADMUX |= channel;

	/* Start a new conversion */
	ADCSRA |= (1<<ADSC);

	/* Wait for the conversion to be done and return value */
	while(ADCSRA & (1<<ADSC));
	return ADC;
}
