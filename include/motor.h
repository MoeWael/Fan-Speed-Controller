/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for the DC Motor driver
 *
 * Author: Mohammad Wael
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_EN_PORT_ID     PORTB_ID
#define MOTOR_EN_PIN_ID      PIN3_ID

#define MOTOR_PIN1_PORT_ID   PORTB_ID
#define MOTOR_PIN1_PIN_ID    PIN0_ID

#define MOTOR_PIN2_PORT_ID   PORTB_ID
#define MOTOR_PIN2_PIN_ID    PIN1_ID

typedef enum{
	MOTOR_OFF,MOTOR_CLOCKWISE,MOTOR_ANTICLOCKWISE
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init();
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
