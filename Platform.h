/*
 * Platform.h
 *
 *  Created on: Jan 26, 2017
 *      Author: cosmo
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "MassFlowRate.h"

class Platform {
public:
	Platform();
	void MoveTo(double x, double y);
	void MoveToInch(double x, double y);
	void HomeAll();
	void Update();
	void PrintEndstopStatus();

private:
	Actuator *x;
	Endstops *xEndstops;
	//Actuator *y;
	//Endstops *yEndstops;
};

#endif /* PLATFORM_H_ */
