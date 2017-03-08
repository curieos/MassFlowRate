/*
 * PressureSensor.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: cosmo
 */

#include "PressureSensor.h"

PressureSensor::PressureSensor(float slope, float offset, uint8_t pin) :
		Sensor(slope, offset, pin) {

}

void PressureSensor::Update() {
	Sensor::Update();
}

float PressureSensor::AverageData() {
	return Sensor::AverageData();
}

float PressureSensor::ReadData() {
	return Sensor::ReadData();
}

void PressureSensor::AddData() {
	Sensor::AddData();
}
