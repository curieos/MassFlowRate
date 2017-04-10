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
#include "EEPROMRW.h"

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
	Sensor(int slopeReg, int offsetReg, uint8_t pin);

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

	/**
	 *
	 */
	virtual void ReadConfig();

	/**
	 *
	 */
	virtual void WriteConfig();

	/**
	 *
	 * @param slope
	 */
	inline virtual void SetSlope(float slope) { this->slope = slope; }

	/**
	 *
	 * @return
	 */
	inline virtual float GetSlope() { return slope; }

	/**
	 *
	 * @param slope
	 */
	inline virtual void SetOffset(float slope) { this->offset = offset; }

	/**
	 *
	 * @return
	 */
	inline virtual float GetOffset() { return offset; }

protected:
	elapsedMillis *sampleTimer;

	int slopeReg;
	int offsetReg;
	uint8_t pin;
	uint8_t index;
	float *data;
	float slope;
	float offset;
	bool enabled;
};

#endif /* SENSOR_H_ */
