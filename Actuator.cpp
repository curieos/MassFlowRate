/*
 * Actuator.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: cosmo
 */

#include "Actuator.h"

Actuator::Actuator(uint8_t stepPin, uint8_t dirPin, uint8_t maxPin, uint8_t minPin) {
	position = 0;

	driver = new AMIS30543();
	motor = new AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);

	motor->setMaxSpeed(SPEED * STEPS_PER_MM);
	motor->setAcceleration(ACCEL * STEPS_PER_MM);

	endstops = new Endstops(Y_MAX_PIN, Y_MIN_PIN);
}

void Actuator::Initialize(uint8_t chipSelect) {
	driver->init(chipSelect);
	delay(10);

	driver->resetSettings();
	driver->setCurrentMilliamps(MOTOR_CURRENT);
	driver->setStepMode(MICROSTEPPING);
	driver->enableDriver();

	motor->setMaxSpeed(SPEED * STEPS_PER_MM);
	motor->setAcceleration(ACCEL * STEPS_PER_MM);
}

void Actuator::MoveTo(double pos) {
	position = (int)pos*STEPS_PER_MM;

	/*if (this->position < 0) todo  THIS IS FOR 0-MAX, NEED TO CHANGE TO MIN TO MAX AS DEFINED BY EEPROM
		this->position = 0;
	else if (this->position > AXIS_MAX_LENGTH * STEPS_PER_MM)
		this->position = AXIS_MAX_LENGTH * STEPS_PER_MM;*/
	Serial.println("MOVING");
	motor->moveTo(this->position);
}

bool Actuator::Run() {
	return motor->run();
}

void Actuator::SetPosition(int pos) {
	position = pos;
	motor->setCurrentPosition(position);
}

