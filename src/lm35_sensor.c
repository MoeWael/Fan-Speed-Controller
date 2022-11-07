 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "lm35_sensor.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */


uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	uint16 adcResult = 0;
	/* Read ADC channel where the temperature sensor is connected */
	adcResult = ADC_read(SENSOR_CHANNEL_ID) * 2;

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adcResult*SENSOR_MAX_TEMPERATURE*ADC_MAXIMUM_VOLTAGE_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

