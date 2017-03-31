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

/**
 *
 */
class Sensor {
public:
	/**
	 *
	 * @param slope
	 * @param offset
	 * @param pin
	 */
	Sensor(float slope, float offset, uint8_t pin);

	/**
	 *
	 */
	virtual void Update();

	/**
	 *
	 * @return
	 */
	virtual float AverageData();

	/**
	 *
	 * @return
	 */
	virtual float ReadData();

	/**
	 *
	 */
	virtual void AddData();

	/**
	 *
	 * @param en
	 */
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
