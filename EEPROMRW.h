/*
 * EEPROMConfig.h
 *
 *  Created on: Mar 7, 2017
 *      Author: cosmo
 */

/**
 * bytes 0-3: X min position
 * bytes 4-7: X max position
 * bytes 8-11: Y min position
 * bytes 12-15: Y max position
 * bytes 16-19:
 */

#ifndef EEPROMRW_H_
#define EEPROMRW_H_

#include <EEPROM.h>

class EEPROMRW {
public:
	static float GetFloatValue(int addr);
	static int GetIntValue(int addr);
	static void SetFloatValue(int addr, float value);
	static void SetIntValue(int addr, int value);
};

#endif /* EEPROMRW_H_ */
