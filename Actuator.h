/*
 * Actuator.h
 *
 *  Created on: Jan 25, 2017
 *      Author: Caroline
 */

#ifndef ACTUATOR_H_
#define ACTUATOR_H_

#include <AMIS30543.h>
#include <SPI.h>
#include <AccelStepper.h>
#include "Endstops.h"
#include "Configuration.h"
#include "EEPROMRW.h"

enum MoveState {
	Ready,
	Homing,
	Moving,
	Calibrating
};

class Actuator {
public:
	Actuator(uint8_t stepPin, uint8_t dirPin, uint8_t minPin, uint8_t maxPin, int midReg, int maxReg);
	void Initialize(uint8_t chipSelect);
	void MoveTo(double postion);
	void SetPosition(int pos);
	void WriteConfig();
	void ReadConfig();
	void Home();
	bool Run();

	inline long GetPosition() { return motor->currentPosition()-midPosition; }
	inline float GetPositionMM() { return ((float) GetPosition()) / STEPS_PER_MM; }
	inline float GetPositionInch() { return GetPositionMM() / INCH_TO_MM; }
	inline long GetSetPositionSteps() { return motor->targetPosition()-midPosition; }
	inline float GetSetPositionMM() { return (float) GetSetPositionSteps() / STEPS_PER_MM; }
	inline float GetSetPositionInch() { return GetSetPositionMM() / INCH_TO_MM; }
	inline bool Moving() { return !motor->distanceToGo() == 0; }
	inline long GetMaxPosition() { return maxPosition; }
	inline long GetMidPosition() { return midPosition; }
	inline void SetMaxPosition(int val) { maxPosition = val; }
	inline void SetMidPosition(int val) { midPosition = val; }
	inline MoveState GetState() { return state; }

private:
	MoveState state;
	AMIS30543 *driver;
	AccelStepper *motor;
	Endstops *endstops;

	int midRegister;
	int maxRegister;
	long maxPosition;
	long midPosition;
};

#endif /* ACTUATOR_H_ */
