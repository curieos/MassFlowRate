/*
 * Interpreter.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: Caroline
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
			switch (serialBuffer->GetIntValue()) {
			case 1:
				if (serialBuffer->Seen('S')) {
					platform->MoveXInch(serialBuffer->GetFloatValue());
					Serial.println(serialBuffer->GetFloatValue());
				}
				break;
			case 2:
				if (serialBuffer->Seen('S')) {
					platform->MoveYInch(serialBuffer->GetFloatValue());
					Serial.println(serialBuffer->GetFloatValue());
				}
				break;
			}
		}
		serialBuffer->CommandExecuted();
	}
}

