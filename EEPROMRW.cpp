/*
 * EEPROMConfig.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: Caroline
 */

#include "EEPROMRW.h"

float EEPROMRW::GetFloatValue(int addr) {
	float value;
	unsigned char c[4];

	for (int i = 0; i < 4; addr++, i++) {
		c[i] = EEPROM[addr];
	}

	memcpy(&value, &c, sizeof(value));

	return value;
}

int EEPROMRW::GetIntValue(int addr) {
	int value;
	unsigned char c[4];

	for (int i = 0; i < 4; addr++, i++) {
		c[i] = EEPROM[addr];
	}

	memcpy(&value, &c, sizeof(value));

	return value;
}

void EEPROMRW::SetFloatValue(int addr, float value) {
	if (GetFloatValue(addr) == value) return; //Prevent EEPROM wear

	unsigned char *c = reinterpret_cast<unsigned char*>(&value);
	for (int i = 0; i < 4; i++, addr++) {
		EEPROM[addr] = c[i];
	}
}

void EEPROMRW::SetIntValue(int addr, int value) {
	if (GetIntValue(addr) == value) return; //Prevent EEPROM wear

	for (int i = 0; i < 4; i++, addr++) {
		EEPROM[addr] = (value >> (i * 8));
	}
}
