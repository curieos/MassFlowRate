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

//Stepper settings
#define MICROSTEPPING 32
#define MOTOR_STEPS_PER_REV 200
#define DRIVE_PITCH 8 //mm/rev
#define STEPS_PER_MM MICROSTEPPING*MOTOR_STEPS_PER_REV/DRIVE_PITCH
#define SPEED 20 //mm per sec
#define ACCEL 100 //mm per sec^2

//Machine limits
#define AXIS_MAX_LENGTH 50
#define HOMING_FEEDRATE 2

//Endstop settings
#define X_MAX_PIN 22
#define X_MIN_PIN 21
#define Y_MAX_PIN 19
#define Y_MIN_PIN 18

//Stepper drive settings
#define X_STEP_PIN 0
#define X_DIR_PIN 1
#define Y_STEP_PIN 2
#define Y_DIR_PIN 3
#define X_CS_PIN 10
#define Y_CS_PIN 9
#define MOTOR_CURRENT 1200

//Conversions
#define INCH_TO_MM 25.4
#define MM_TO_INCH 1/25.4

//General Sensor settings
#define ADC_RESOLUTION 12
#define SAMPLES 10
#define SAMPLE_RATE 25 //hertz
#define SAMPLE_PERIOD 100/SAMPLE_RATE

//Absolute Pressure
#define ABSOLUTE_PIN 0

//Differential Pressure
#define DIFFERENTIAL_1_PIN 2
#define DIFFERENTIAL_2_PIN 3

//Thermocouple
#define THERMOCOUPLE_CS_PIN 15
#define DEFAULT_MISO 12
#define DEFAULT_CLK 13

#endif /* CONFIGURATION_H_ */
