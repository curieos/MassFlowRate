/*
 * Interpreter.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmo
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "MassFlowRate.h"

class Interpreter {
public:
	Interpreter(Platform *p);
	void Update();

private:
	CommandBuffer *serialBuffer;
	Platform *platform;
};

#endif /* INTERPRETER_H_ */
