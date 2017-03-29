/*
 * Platform.h
 *
 *  Created on: Jan 26, 2017
 *      Author: Caroline
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "Actuator.h"
#include "Configuration.h"

class Platform {
public:
	Platform();
	void MoveXInch(double pos);
	void MoveYInch(double pos);
	void MoveX(double pos);
	void MoveY(double pos);
	//void MoveTo(double x, double y);
	//void MoveToInch(double x, double y);
	void HomeAll();
	void Update();
	void PrintEndstopStatus();
	void PrintPositions();
	void WriteConfig();
	void ReadConfig();

	//inline bool Moving() { return x->Moving() || y->Moving(); }
	inline MoveState GetState() { return state; }

private:
	elapsedMillis timer;
	MoveState state;
	Actuator *x;
	Actuator *y;

	bool homed;
};

#endif /* PLATFORM_H_ */
