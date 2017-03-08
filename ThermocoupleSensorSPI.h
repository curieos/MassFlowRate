/*
 * ThermocoupleSensorSPI.h
 *
 *  Created on: Feb 21, 2017
 *      Author: cosmo
 */

#ifndef THERMOCOUPLESENSORSPI_H_
#define THERMOCOUPLESENSORSPI_H_

#include "Sensor.h"
#include <SPI.h>
#include <Adafruit_MAX31855.h>

class ThermocoupleSensorSPI: public Sensor {
public:
	ThermocoupleSensorSPI(uint8_t pin);
	virtual void Update() override;
	virtual float AverageData() override;
	virtual float ReadData() override;
	virtual void AddData() override;

private:
	Adafruit_MAX31855 *sensor;
};

#endif /* THERMOCOUPLESENSORSPI_H_ */
