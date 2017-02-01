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
	Actuator(uint8_t stepPin, uint8_t dirPin);
	void Initialize(uint8_t chipSelect);
	void MoveTo(double postion);
	inline int GetPosition() { return position; }
	inline float GetPositionMM() { return (float) position / (STEPS_PER_MM); }
	inline float GetPositionIn() { return GetPositionMM() * MM_TO_INCH; }
	inline bool Moving() { return !motor->distanceToGo() == 0; }
	void SetPosition(int pos);
	bool Run();

private:
	AMIS30543 *driver;
	AccelStepper *motor;

	int position;
};

#endif /* ACTUATOR_H_ */
