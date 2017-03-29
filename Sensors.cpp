/*
 * Sensors.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Caroline
 */

#include "Sensors.h"

Sensors::Sensors() {
	sensorA = new PressureSensor(EEPROMRW::GetFloatValue(ABS_SLOPE_REG), EEPROMRW::GetFloatValue(ABS_OFFSET_REG), ABSOLUTE_PIN);
	sensorB = new PressureSensor(EEPROMRW::GetFloatValue(DIFF_1_SLOPE_REG), EEPROMRW::GetFloatValue(DIFF_1_OFFSET_REG), DIFFERENTIAL_1_PIN);
	//sensorC = new ThermocoupleSensorSPI(THERMOCOUPLE_CS_PIN);

	timer = new elapsedMillis();

	Enable();
}

void Sensors::Update () {
	if (enabled) {
		sensorA->Update();
		sensorB->Update();
	}
	//sensorC->Update();

	if (*timer >= 250) {
		*timer -= 250;

		if (!enabled) return;

		Serial.print("P1S");
		Serial.println(sensorA->AverageData(), SERIAL_FP_DIGITS);
		Serial.print("D1S");
		Serial.println(sensorB->AverageData(), SERIAL_FP_DIGITS);
		//Serial.print("Temperature: ");
		//Serial.println(sensorC->AverageData());
	}
}

