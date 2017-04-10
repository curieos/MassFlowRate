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

const uint8_t NUMSENSORS = 4;

/**
 *
 */
class Sensors {
public:
	Sensors();
	/**
	 *
	 */
	void Update();
	/**
	 *
	 */
	void Enable();
	/**
	 *
	 */
	void Disable();


	/**
	 *
	 * @return
	 */
	inline bool Enabled() { return enabled; }

private:
	Sensor *sensors[NUMSENSORS];
	//Sensor *sensorA;
	//Sensor *sensorB;
	elapsedMillis *timer;

	bool enabled;
};

#endif /* SENSORS_H_ */
