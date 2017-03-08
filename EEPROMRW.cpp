/*
 * EEPROMConfig.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: cosmo
 */

#include "EEPROMRW.h"

float EEPROMRW::GetFloatValue(int addr) {

	return 0;
}

int EEPROMRW::GetIntValue(int addr) {

	return 0;
}

void EEPROMRW::SetFloatValue(int addr, float value) {
	for (int i = 0; i < 4; i++) {
		EEPROM[i] = (value >> (i * 8));
	}
}

void EEPROMRW::SetIntValue(int addr, int value) {
	for (int i = 0; i < 4; i++) {
		EEPROM[i] = (value >> (i * 8));
	}
}
