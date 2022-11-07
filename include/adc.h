 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the ADC AVR driver
 *
 * Author: Mohammad Wael
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#include "std_types.h"

#define ADC_MAXIMUM_VALUE 1023
#define ADC_MAXIMUM_VOLTAGE_VALUE 2.56

typedef enum{
	AREF,AVCC,RES,INTERNAL
}ADC_ReferenceVoltage;

typedef enum{
	FCPU_2,FCPU_2_2,FCPU_4,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_Init(const ADC_ConfigType* Config_Ptr);
uint16 ADC_read(uint8 channel);



#endif /* ADC_H_ */
