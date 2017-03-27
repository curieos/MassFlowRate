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
	serialBuffer->FillBuffer();

	if (!serialBuffer->IsEmpty()) {
		if (serialBuffer->Seen('A')) {
			ActuatorCommands();
		} else if (serialBuffer->Seen(' ')) {

		}
		serialBuffer->CommandExecuted();
	}
}

void Interpreter::ActuatorCommands() {
	if (serialBuffer->Seen('H')) {
		platform->HomeAll();
	} else {
		switch (serialBuffer->GetIntValue()) {
		case 1:
			if (serialBuffer->Seen('S')) {
				platform->MoveXInch(serialBuffer->GetFloatValue());
			}
			break;
		case 2:
			if (serialBuffer->Seen('S')) {
				platform->MoveYInch(serialBuffer->GetFloatValue());
			}
			break;
		}
	}
}

