/*
 * Interpreter.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmo
 */

#include "Interpreter.h"

Interpreter::Interpreter(Platform *p) {
	platform = p;
	serialBuffer = new CommandBuffer();
}

void Interpreter::Update() {
	serialBuffer->FillBuffer();

	if (!serialBuffer->IsEmpty()) {
		if (serialBuffer->Seen('A')) {
			if (serialBuffer->GetIntValue() == 1) {
				if (serialBuffer->Seen('S')) {
					platform->MoveXInch(serialBuffer->GetFloatValue());
					//Serial.println(serialBuffer->GetFloatValue());
				}
			}
		}
		serialBuffer->CommandExecuted();
	}
}

