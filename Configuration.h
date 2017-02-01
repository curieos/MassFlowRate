/*
 * Configuration.h
 *
 *  Created on: Jan 25, 2017
 *      Author: cosmo
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#define VERSION "0"

//Serial settings
#define BAUDRATE 115200
#define SERIAL_TIMEOUT 20
#define BUFFER_LENGTH 16
#define MAX_COMMAND_LENGTH 100

#define MICROSTEPPING 32
#define MOTOR_STEPS_PER_REV 200
#define DRIVE_PITCH 8 //mm/rev
#define STEPS_PER_MM MICROSTEPPING*MOTOR_STEPS_PER_REV/DRIVE_PITCH
#define SPEED 10 //mm per sec
#define ACCEL 50 //mm per sec^2

//Machine limits
#define AXIS_MAX_LENGTH 50
#define HOMING_FEEDRATE 2

//Endstop settings
#define X_MAX_PIN 22
#define X_MIN_PIN 21
#define Y_MAX_PIN 17
#define Y_MIN_PIN 19

//Stepper drive settings
#define X_STEP_PIN 3
#define X_DIR_PIN 2
#define Y_STEP_PIN 5
#define Y_DIR_PIN 4
#define X_CS_PIN 10
#define Y_CS_PIN 9
#define MOTOR_CURRENT 1000

//Conversions
#define INCH_TO_MM 25.4
#define MM_TO_INCH 1/25.4

#endif /* CONFIGURATION_H_ */
