/*
 * Actuator.h
 *
 *  Created on: Jan 25, 2017
 *      Author: cosmo
 */

#ifndef ACTUATOR_H_
#define ACTUATOR_H_

#include "MassFlowRate.h"

class Actuator {
public:
	Actuator(uint8_t stepPin, uint8_t dirPin, uint8_t maxPin, uint8_t minPin);
	void Initialize(uint8_t chipSelect);
	void MoveTo(double postion);
	inline float GetPosition() { return (float) motor->currentPosition() / STEPS_PER_MM; }
	inline float GetPositionIn() { return GetPosition() * MM_TO_INCH; }
	inline int GetSetPositionSteps() { return position; }
	inline float GetSetPositionMM() { return (float) position / (STEPS_PER_MM); }
	inline float GetSetPositionIn() { return GetSetPositionMM() * MM_TO_INCH; }
	inline bool Moving() { return !motor->distanceToGo() == 0; }
	void SetPosition(int pos);
	bool Run();

private:
	AMIS30543 *driver;
	AccelStepper *motor;
	Endstops *endstops;

	int position;
};

#endif /* ACTUATOR_H_ */
