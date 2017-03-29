/*
 * Platform.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: Caroline
 */

#include "Platform.h"

Platform::Platform() {
	x = new Actuator(X_STEP_PIN, X_DIR_PIN, X_MIN_PIN, X_MAX_PIN, X_MID_REG, X_MAX_REG);
	y = new Actuator(Y_STEP_PIN, Y_DIR_PIN, Y_MIN_PIN, Y_MAX_PIN, Y_MID_REG, Y_MAX_REG);

	x->Initialize(X_CS_PIN);
	y->Initialize(Y_CS_PIN);

	homed = false;
	state = Ready;
}

void Platform::MoveX(double pos) {
	if (!homed) return;

	if (this->y->GetPositionInch() <= -2.5f) {
		this->x->MoveTo(pos);
	}
}

void Platform::MoveXInch(double pos) {
	MoveX(pos * INCH_TO_MM);
}

void Platform::MoveY(double pos) {
	if (!homed) return;

	if (this->x->GetPositionInch() <= -2.5f) {
		this->y->MoveTo(pos);
	}
}

void Platform::MoveYInch(double pos) {
	MoveY(pos * INCH_TO_MM);
}

void Platform::HomeAll() {
	this->x->Home();
	this->y->Home();
	homed = true;
}

void Platform::WriteConfig() {

}

void Platform::ReadConfig() {

}

void Platform::PrintPositions() {
	Serial.print("A1S");
	Serial.println(x->GetPositionInch(), SERIAL_FP_DIGITS);
	Serial.print("A2S");
	Serial.println(y->GetPositionInch(), SERIAL_FP_DIGITS);
}

void Platform::Update() {
	if (x->GetState() == Moving || y->GetState() == Moving) {
		state = Moving;
	} else if (x->GetState() == Homing || y->GetState() == Homing) {
		state = Homing;
	} else if (x->GetState() == Calibrating || y->GetState() == Calibrating) {
		state = Calibrating;
	} else {
		state = Ready;
	}

	switch (state) {
	case Moving:
		if (timer > 20) {
			timer -= 20;

			PrintPositions();
		}
		break;
	case Homing:
	case Calibrating:
		break;
	case Ready:
		if (timer > 1000) {
			timer = 0;

			PrintPositions();
		}
		break;
	}

	x->Run();
	y->Run();
}

