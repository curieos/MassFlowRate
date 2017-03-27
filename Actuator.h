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
	Actuator(uint8_t stepPin, uint8_t dirPin, int midReg, int maxReg);
	void Initialize(uint8_t chipSelect);
	void MoveTo(double postion);
	void SetPosition(int pos);
	void Home();
	bool Run();

	inline float GetPosition() { return (float) (motor->currentPosition()-midPosition) / STEPS_PER_MM; }
	inline float GetPositionInch() { return GetPosition() * MM_TO_INCH; }
	inline int GetSetPositionSteps() { return motor->targetPosition()-midPosition; }
	inline float GetSetPositionMM() { return (float) GetSetPositionSteps() / STEPS_PER_MM; }
	inline float GetSetPositionInch() { return GetSetPositionMM() * MM_TO_INCH; }
	inline bool Moving() { return !motor->distanceToGo() == 0; }
	inline int GetMaxPosition() { return maxPosition; }
	inline int GetMidPosition() { return midPosition; }
	inline void SetMaxPosition(int val) { maxPosition = val; }
	inline void SetMidPosition(int val) { midPosition = val; }
	inline MoveState GetState() { return state; }

private:
	MoveState state;
	AMIS30543 *driver;
	AccelStepper *motor;
	Endstops *endstops;

	int maxPosition;
	int midPosition;
};

#endif /* ACTUATOR_H_ */
