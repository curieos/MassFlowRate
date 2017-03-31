/*
 * Actuator.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: Caroline
 */

#include "Actuator.h"

Actuator::Actuator(uint8_t stepPin, uint8_t dirPin, uint8_t minPin, uint8_t maxPin, int midReg, int maxReg) {
	maxPosition = EEPROMRW::GetIntValue(maxReg);
	midPosition = EEPROMRW::GetIntValue(midReg);
	midRegister = midReg;
	maxRegister = maxReg;

	driver = new AMIS30543();
	motor = new AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);

	motor->setMaxSpeed(SPEED * STEPS_PER_MM);
	motor->setAcceleration(ACCEL * STEPS_PER_MM);

	endstops = new Endstops(maxPin, minPin);

	state = Ready;
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

void Actuator::WriteConfig() {
	EEPROMRW::SetIntValue(maxRegister, maxPosition);
	EEPROMRW::SetIntValue(midRegister, midPosition);
}

void Actuator::ReadConfig() {
	maxPosition = EEPROMRW::GetIntValue(maxRegister);
	midPosition = EEPROMRW::GetIntValue(midRegister);
}

void Actuator::MoveTo(double pos) {
	int position = (int) pos * STEPS_PER_MM;
	position += midPosition;

	motor->setMaxSpeed(SPEED * STEPS_PER_MM);

	if (position < 0)
		position = 0;
	else if (position > maxPosition)
		position = maxPosition;

	Serial.println("MOVING");
	motor->moveTo(position);
	state = MoveState::Moving;
}

bool Actuator::Run() {
	switch (state) {
	case MoveState::Homing:
		if (endstops->CheckMin()) {
			SetPosition(0);
			state = Ready;
			MoveTo(-2.9 * INCH_TO_MM);
		} else if (endstops->CheckMax()) {
			SetPosition(0);
			//TODO CAUSE AN ERROR THIS SHOULDNT HAPPEN
		}
		break;
	case MoveState::Moving:
		if (!Moving()) {
			state = Ready;
		}
		break;
	case MoveState::Calibrating:
	case MoveState::Ready:
		break;
	}

	return motor->run();
}

void Actuator::SetPosition(int pos) {
	motor->setCurrentPosition(pos);
}

void Actuator::Home() {
	motor->setMaxSpeed(HOME_SPEED * STEPS_PER_MM);
	motor->moveTo(-maxPosition * 2);
	state = Homing;
}

