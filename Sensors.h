/*
 * Sensors.h
 *
 *  Created on: Feb 23, 2017
 *      Author: cosmo
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include "EEPROMRW.h"
#include "MassFlowRate.h"

class Sensors {
public:
	Sensors();
	void Update();

private:
	Sensor *sensorA;
	Sensor *sensorB;
	//Sensor *sensorC;

	elapsedMillis *timer;
};

#endif /* SENSORS_H_ */
