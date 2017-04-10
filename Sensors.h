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
	inline bool Enabled() {
		return enabled;
	}

	/**
	 *
	 */
	void WriteConfig();

	/**
	 *
	 */
	void ReadConfig();

	/**
	 *
	 * @param slope
	 * @param sensor
	 */
	inline void SetSlope(float slope, uint8_t sensor) {
		if (sensor >= NUMSENSORS) return;
		sensors[sensor]->SetSlope(slope);
	}

	/**
	 *
	 * @param sensor
	 * @return
	 */
	inline float GetSlope(uint8_t sensor) {
		if (sensor >= NUMSENSORS) return 0;
		return sensors[sensor]->GetSlope();
	}

	/**
	 *
	 * @param offset
	 * @param sensor
	 */
	inline void SetOffset(float offset, uint8_t sensor) {
		if (sensor >= NUMSENSORS) return;
		sensors[sensor]->SetOffset(offset);
	}

	/**
	 *
	 * @param sensor
	 * @return
	 */
	inline float GetOffset(uint8_t sensor) {
		if (sensor >= NUMSENSORS) return 0;
		return sensors[sensor]->GetOffset();
	}

	/**
	 *
	 */
	void PrintValues();

private:
	Sensor *sensors[NUMSENSORS];
	elapsedMillis *timer;

	bool enabled;
};

#endif /* SENSORS_H_ */
