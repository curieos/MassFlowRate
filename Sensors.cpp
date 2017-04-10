/*
 * Sensors.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Caroline
 */

#include "Sensors.h"

Sensors::Sensors() {
	sensors[0] = new PressureSensor(ABS_SLOPE_REG, ABS_OFFSET_REG, ABSOLUTE_PIN);
	sensors[1] = new PressureSensor(DIFF_1_SLOPE_REG, DIFF_1_OFFSET_REG, DIFFERENTIAL_1_PIN);
	sensors[2] = new PressureSensor(DIFF_2_SLOPE_REG, DIFF_2_OFFSET_REG, DIFFERENTIAL_2_PIN);
	sensors[3] = new ThermocoupleSensorSPI(THERMOCOUPLE_CS_PIN);

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
		Serial.print("T1S");
		Serial.println(sensors[3]->AverageData(), SERIAL_FP_DIGITS);
	}
}

void Sensors::ReadConfig() {
	for (int i = 0; i < NUMSENSORS; i++)
		sensors[i]->ReadConfig();
}

void Sensors::WriteConfig() {
	for (int i = 0; i < NUMSENSORS; i++)
		sensors[i]->WriteConfig();
}

void Sensors::PrintValues() {
	for (int i = 0; i < NUMSENSORS; i++) {
		Serial.printf("S%dL%.6f", i+1, GetSlope(i));
		Serial.printf("S%dO%.6f", i+1, GetSlope(i));
	}
}

