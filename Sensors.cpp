/*
 * Sensors.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: cosmo
 */

#include "Sensors.h"

Sensors::Sensors() {
	sensorA = new PressureSensor(0.00733*.951, 1.052, ABSOLUTE_PIN);
	sensorB = new PressureSensor(0.06077, 0, DIFFERENTIAL_1_PIN);
	//sensorC = new ThermocoupleSensorSPI(THERMOCOUPLE_CS_PIN);

	timer = new elapsedMillis();
}

void Sensors::Update () {
	sensorA->Update();
	sensorB->Update();
	//sensorC->Update();

	if (*timer >= 1000) {
		*timer -= 1000;

		Serial.print("\nAbsolute Pressure: ");
		Serial.println(sensorA->AverageData());
		Serial.print("Differential Pressure: ");
		Serial.println(sensorB->AverageData());
		//Serial.print("Temperature: ");
		//Serial.println(sensorC->AverageData());
	}
}

