/*
 * Sensor.h
 *
 *  Created on: Feb 16, 2017
 *      Author: Caroline
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "Arduino.h"
#include "Configuration.h"

class Sensor {
public:
	Sensor(float slope, float offset, uint8_t pin);
	virtual void Update();
	virtual float AverageData();
	virtual float ReadData();
	virtual void AddData();
	virtual void Enable(bool en);

protected:
	elapsedMillis *sampleTimer;

	uint8_t pin;
	uint8_t index;
	float *data;
	float slope;
	float offset;
	bool enabled;
};

#endif /* SENSOR_H_ */
