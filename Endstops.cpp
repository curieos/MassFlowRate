/*
 * Endstops.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: Caroline
 */

#include "Endstops.h"

Endstops::Endstops(uint8_t maxPin, uint8_t minPin) {
	pinMode(maxPin, INPUT_PULLUP);
	pinMode(minPin, INPUT_PULLUP);
	maxEndstop = new Endstop(maxPin);
	minEndstop = new Endstop(minPin);
}

