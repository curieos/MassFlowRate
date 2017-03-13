/*
 * Configuration.h
 *
 *  Created on: Jan 25, 2017
 *      Author: Caroline
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#define VERSION "0"

//Serial settings
#define BAUDRATE 115200
#define SERIAL_TIMEOUT 20
#define BUFFER_LENGTH 16
#define MAX_COMMAND_LENGTH 100
#define SERIAL_FP_DIGITS 4
#define SERIAL_UPDATE_FREQUENCY 4
#define SERIAL_UPDATE_PERIOD 100/SERIAL_UPDATE_FREQUENCY

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

/**EEPROM config registers
 * bytes 0-3: X min position
 * bytes 4-7: X max position
 * bytes 8-11: Y min position
 * bytes 12-15: Y max position
 * bytes 16-19: Absolute pressure slope
 * bytes 20-23: Absolute pressure offset
 * bytes 24-27: Differential 1 slope
 * bytes 28-31: Differential 1 offset
 * bytes 32-35: Differential 2 slope
 * bytes 36-39: Differential 2 offset
 */
#define X_MIN_REG 0
#define X_MAX_REG 4
#define Y_MIN_REG 8
#define Y_MAX_REG 12
#define ABS_SLOPE_REG 16
#define ABS_OFFSET_REG 20
#define DIFF_1_SLOPE_REG 24
#define DIFF_1_OFFSET_REG 28
#define DIFF_2_SLOPE_REG 32
#define DIFF_2_OFFSET_REG 36

//Starter values for config
#define ACTUATOR_MAX_DEFAULT 2.9
#define ACTUATOR_MIN_DEFAULT -2.9
#define ABS_SLOPE_DEFAULT 0.00697
#define ABS_OFFSET_DEFAULT 1.052
#define DIFF_SLOPE_DEFAULT 0.06077
#define DIFF_OFFSET_DEFAULT 0

#endif /* CONFIGURATION_H_ */
