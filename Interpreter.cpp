/*
 * Interpreter.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: Caroline
 */

#include "Interpreter.h"

Interpreter::Interpreter(Platform *p, Sensors *s) {
	platform = p;
	sensors = s;
	serialBuffer = new CommandBuffer();
}

void Interpreter::Update() {
	if (!sensors->Enabled()) {
		if (platform->GetState() == Ready) sensors->Enable();
	}

	serialBuffer->FillBuffer();

	if (!serialBuffer->IsEmpty()) {
		if (serialBuffer->Seen('A')) {
			sensors->Disable();
			ActuatorCommands();
		} else if (serialBuffer->Seen('S')) {
			SensorCommands();
		}
		serialBuffer->CommandExecuted();
	}
}

void Interpreter::SensorCommands() {

}

void Interpreter::ActuatorCommands() {
	if (serialBuffer->Seen('H')) { //Home all
		platform->HomeAll();
	} else if (serialBuffer->Seen('W')) { //Write calibration to EEPROM
		platform->WriteConfig();
	} else if (serialBuffer->Seen('R')) { //Read calibration from EEPROM
		platform->ReadConfig();
	} else if (serialBuffer->Seen('A')) {
		switch (serialBuffer->GetIntValue()) {
		case 1:
			if (serialBuffer->Seen('S')) {
				platform->MoveXInch(serialBuffer->GetFloatValue());
			} else if (serialBuffer->Seen('M')) { //Find the max position

			} else if (serialBuffer->Seen('C')) { //
				platform->SetXMid();
			}
			break;
		case 2:
			if (serialBuffer->Seen('S')) {
				platform->MoveYInch(serialBuffer->GetFloatValue());
			} else if (serialBuffer->Seen('M')) {

			} else if (serialBuffer->Seen('C')) {
				platform->SetYMid();
			}
			break;
		}
	}
}

