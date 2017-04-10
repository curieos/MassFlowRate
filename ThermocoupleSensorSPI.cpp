/*
 * ThermocoupleSensorSPI.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: Caroline
 */

#include "ThermocoupleSensorSPI.h"

#define THERMSAMPLES 6
#define THERM_PERIOD 70

ThermocoupleSensorSPI::ThermocoupleSensorSPI(uint8_t pin) : Sensor(0, 0, pin) {
	sensor = new Adafruit_MAX31855(DEFAULT_CLK, pin, DEFAULT_MISO);
	delete(data);
	data = new float[THERMSAMPLES];
}

void ThermocoupleSensorSPI::Update() {
	if (*sampleTimer >= THERM_PERIOD) {
		*sampleTimer -= THERM_PERIOD;

		if (enabled) {
			this->AddData();
		}
	}
}

float ThermocoupleSensorSPI::AverageData() {
	float average = 0;

	for (int i = 0; i < THERMSAMPLES; i++) {
		average += data[i];
	}

	return average / THERMSAMPLES;
}

float ThermocoupleSensorSPI::ReadData() {
	return sensor->readCelsius();
}

void ThermocoupleSensorSPI::AddData() {
	data[index] = ReadData();
	index = (index + 1) % THERMSAMPLES;
}

void ThermocoupleSensorSPI::Enable(bool en) {
	Sensor::Enable(en);
}
