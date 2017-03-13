/*
 * EEPROMConfig.h
 *
 *  Created on: Mar 7, 2017
 *      Author: Caroline
 */

#ifndef EEPROMRW_H_
#define EEPROMRW_H_

#include <EEPROM.h>
#include <string.h>

class EEPROMRW {
public:
	static float GetFloatValue(int addr);
	static int GetIntValue(int addr);
	static void SetFloatValue(int addr, float value);
	static void SetIntValue(int addr, int value);
};

#endif /* EEPROMRW_H_ */
