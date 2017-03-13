/*
 * Sensor.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: Caroline
 */

#include "Sensor.h"

Sensor::Sensor(float slope, float offset, uint8_t pin) {
	index = 0;
	data = new float[SAMPLES];
	sampleTimer = new elapsedMillis();

	this->pin = pin;
	this->slope = slope;
	this->offset = offset;
	enabled = true;
}

void Sensor::Update() {
	if (*sampleTimer >= SAMPLE_PERIOD) {
		*sampleTimer -= SAMPLE_PERIOD;

		if (enabled) {
			AddData();
		}
	}
}

float Sensor::AverageData() {
	float average = 0;

	for (int i = 0; i < SAMPLES; i++) {
		average += data[i];
	}

	return average/SAMPLES;
}

float Sensor::ReadData() {
	float raw = analogRead(pin);
	raw *= slope;
	raw += offset;
	return raw;
	//return ((float)analogRead(pin))*slope + offset;
}

void Sensor::AddData() {
	data[index] = ReadData();
	index = (index+1)%SAMPLES;
}

void Sensor::Enable(bool en) {
	enabled = en;
}

