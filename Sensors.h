/*
 * Sensors.h
 *
 *  Created on: Feb 23, 2017
 *      Author: Caroline
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include "EEPROMRW.h"
#include "PressureSensor.h"
#include "ThermocoupleSensorSPI.h"
#include "Configuration.h"

class Sensors {
public:
	Sensors();
	void Update();
	inline bool Enabled() { return enabled; }
	inline void Enable() { enabled = true; }
	inline void Disable() { enabled = false; }

private:
	Sensor *sensorA;
	Sensor *sensorB;
	//Sensor *sensorC;
	elapsedMillis *timer;

	bool enabled;
};

#endif /* SENSORS_H_ */
