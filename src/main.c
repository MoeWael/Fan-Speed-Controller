 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: main.c
 *
 * Description: Source file for the prokect application
 *
 * Author: Mohammad Wael
 *
 *******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "common_macros.h"
#include "std_types.h"

#include "lcd.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "motor.h"

ADC_ConfigType Config = {INTERNAL, FCPU_8};

void main(void){

	uint8 Temperature;
	ADC_Init(&Config);
	LCD_init();
	DcMotor_Init();

	while(1){
		Temperature = LM35_getTemperature();
		LCD_moveCursor(0,4);
		LCD_displayString("Temp = ");
		LCD_intgerToString(Temperature);

		if(Temperature < 30){
			DcMotor_Rotate(MOTOR_OFF,Temperature);
		}
		else if(Temperature >= 30 && Temperature < 60){
			DcMotor_Rotate(MOTOR_CLOCKWISE,25);
		}
		else if(Temperature >= 60 && Temperature < 90){
			DcMotor_Rotate(MOTOR_CLOCKWISE,50);
		}
		else if(Temperature >= 90 && Temperature < 120){
			DcMotor_Rotate(MOTOR_CLOCKWISE,75);
		}
		else {
			DcMotor_Rotate(MOTOR_CLOCKWISE,100);
		}
	}
}
