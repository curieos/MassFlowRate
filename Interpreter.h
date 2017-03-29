/*
 * Interpreter.h
 *
 *  Created on: Mar 3, 2017
 *      Author: Caroline
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "CommandBuffer.h"
#include "Platform.h"
#include "Sensors.h"

class Interpreter {
public:
	Interpreter(Platform *p, Sensors *s);
	void Update();
	void ActuatorCommands();
	void SensorCommands();

private:
	CommandBuffer *serialBuffer;
	Platform *platform;
	Sensors *sensors;
};

#endif /* INTERPRETER_H_ */
