/*
 * Endstops.h
 *
 *  Created on: Jan 26, 2017
 *      Author: Caroline
 */

#ifndef ENDSTOPS_H_
#define ENDSTOPS_H_

#include "MassFlowRate.h"

class Endstop {
public:
	inline Endstop(uint8_t _pin) { pin = _pin; }
	inline bool CheckEndstop() { return digitalReadFast(pin) ? true : false ; } //Binary operator to return if the switch is triggered

private:
	uint8_t pin;
};

class Endstops {
public:
	Endstops(uint8_t maxPin, uint8_t minPin);
	inline bool CheckMin() { return minEndstop->CheckEndstop(); }
	inline bool CheckMax() { return maxEndstop->CheckEndstop(); }

private:
	Endstop *maxEndstop;
	Endstop *minEndstop;
};

#endif /* ENDSTOPS_H_ */
