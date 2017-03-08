/*
 * PressureSensor.h
 *
 *  Created on: Feb 21, 2017
 *      Author: cosmo
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "Sensor.h"

class PressureSensor: public Sensor {
public:
	PressureSensor(float slope, float offset, uint8_t pin);
	virtual void Update() override;
	virtual float AverageData() override;
	virtual float ReadData() override;
	virtual void AddData() override;
};

#endif /* PRESSURESENSOR_H_ */
