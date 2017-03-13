/*
 * Platform.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: Caroline
 */

#include "Platform.h"

Platform::Platform() {
	x = new Actuator(X_STEP_PIN, X_DIR_PIN, X_MAX_PIN, X_MIN_PIN);
	y = new Actuator(Y_STEP_PIN, Y_DIR_PIN, Y_MAX_PIN, Y_MIN_PIN);

	x->Initialize(X_CS_PIN);
	y->Initialize(Y_CS_PIN);
}

void Platform::MoveX(double pos) {
	//f (this->y->GetPosition() > -2) {
		this->x->MoveTo(pos);
	//}
}

void Platform::MoveXInch(double pos) {
	MoveX(pos * INCH_TO_MM);
}

void Platform::MoveY(double pos) {
	//if (this->x->GetPosition() > -2) {
		this->y->MoveTo(pos);
	//}
}

void Platform::MoveYInch(double pos) {
	MoveY(pos * INCH_TO_MM);
}

void Platform::Update() {
	x->Run();
	y->Run();
}

