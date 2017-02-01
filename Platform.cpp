/*
 * Platform.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: cosmo
 */

#include "Platform.h"

Platform::Platform() {
	x = new Actuator(X_STEP_PIN, X_DIR_PIN);
	//y = new Actuator(Y_STEP_PIN, Y_DIR_PIN);

	xEndstops = new Endstops(X_MAX_PIN, X_MIN_PIN);
	//yEndstops = new Endstops(Y_MAX_PIN, Y_MIN_PIN);

	x->Initialize(X_CS_PIN);
}

void Platform::MoveToInch(double x, double y) {
	MoveTo(x*INCH_TO_MM, y*INCH_TO_MM);
}

void Platform::MoveTo(double x, double y) {
	this->x->MoveTo(x);
}

void Platform::Update() {
	x->Run();
	//y->Run();
}

void Platform::PrintEndstopStatus() {
	Serial.print("XMIN: ");
	Serial.print(xEndstops->CheckHome());
	Serial.print(" EITHER: ");
	Serial.print(xEndstops->CheckStops());
}

