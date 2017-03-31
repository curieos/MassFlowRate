/*
 * Sensors.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Caroline
 */

#include "Sensors.h"

Sensors::Sensors() {
	sensors[0] = new PressureSensor(EEPROMRW::GetFloatValue(ABS_SLOPE_REG),
			EEPROMRW::GetFloatValue(ABS_OFFSET_REG), ABSOLUTE_PIN);
	sensors[1] = new PressureSensor(EEPROMRW::GetFloatValue(DIFF_1_SLOPE_REG),
			EEPROMRW::GetFloatValue(DIFF_1_OFFSET_REG), DIFFERENTIAL_1_PIN);
	sensors[2] = new PressureSensor(EEPROMRW::GetFloatValue(DIFF_2_SLOPE_REG),
			EEPROMRW::GetFloatValue(DIFF_2_OFFSET_REG), DIFFERENTIAL_2_PIN);
	//sensorC = new ThermocoupleSensorSPI(THERMOCOUPLE_CS_PIN);

	timer = new elapsedMillis();

	Enable();
}

void Sensors::Disable() {
	enabled = false;
	for (int i = 0; i < NUMSENSORS; i++) {
		sensors[i]->Enable(false);
	}
}

void Sensors::Enable() {
	enabled = true;
	for (int i = 0; i < NUMSENSORS; i++) {
		sensors[i]->Enable(true);
	}
}

void Sensors::Update() {
	for (int i = 0; i < NUMSENSORS; i++) {
		sensors[i]->Update();
	}
	//sensorC->Update();

	if (*timer >= 250) {
		*timer -= 250;

		if (!enabled)
			return;

		Serial.print("P1S");
		Serial.println(sensors[0]->AverageData(), SERIAL_FP_DIGITS);
		Serial.print("D1S");
		Serial.println(sensors[1]->AverageData(), SERIAL_FP_DIGITS);
		Serial.print("D2S");
		Serial.println(sensors[2]->AverageData(), SERIAL_FP_DIGITS);
		//Serial.print("Temperature: ");
		//Serial.println(sensorC->AverageData());
	}
}

