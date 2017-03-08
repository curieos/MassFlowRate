/*
 * CommandBuffer.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmo
 */

#include "CommandBuffer.h"

CommandBuffer::CommandBuffer() {
	readPointer = 0;
	writePointer = 0;
	bufferLength = 0;
	linePointer = -1;
	commandIndex = 0;
	inComment = false;
}

long CommandBuffer::GetLongValue() {
	if (linePointer < 0) {
		linePointer = -1;
		return 0;
	}

	long result = strtol(&commandBuffer[readPointer][linePointer + 1], NULL, 0);
	linePointer = -1;
	return result;
}

float CommandBuffer::GetFloatValue() {
	if (linePointer < 0) {
		linePointer = -1;
		return 0;
	}

	float result = (float) strtod(&commandBuffer[readPointer][linePointer + 1],
			NULL);
	linePointer = -1;
	return result;
}

bool CommandBuffer::Seen(char c) {
	linePointer = 0;
	char b;

	do {
		b = commandBuffer[readPointer][linePointer];
		if (b == c)
			return true;
		linePointer++;
	} while (b != 0 && b != ';');

	linePointer = -1;
	return false;
}

void CommandBuffer::FillBuffer() {
	while (bufferLength < BUFFER_LENGTH && Serial.available() > 0) {
		char c = Serial.read();			//the next char for the command

		if (c == '\n' || c == '\r') {
			//End of line
			if (!commandIndex) //if the command index is at 0 then the command is empty and we should skip it
				continue;

			inComment = false;
			newCommand[commandIndex] = 0;
			commandIndex = 0;

			QueueCommand(newCommand);
		} else if (commandIndex >= MAX_COMMAND_LENGTH) {
			//ignore characters past, maybe send an error code?
		} else {						//Add everything else to the new command
			if (c == ';')
				inComment = true;
			if (!inComment)
				newCommand[commandIndex++] = c;
		}
	}
}

bool CommandBuffer::QueueCommand(const char* command) {
	if (bufferLength > BUFFER_LENGTH)
		return false;
	strcpy(commandBuffer[writePointer], command);
	writePointer = (writePointer + 1) % BUFFER_LENGTH;
	bufferLength++;
	return true;
}

void CommandBuffer::CommandExecuted() {
	readPointer = (readPointer + 1) % BUFFER_LENGTH;
	bufferLength--;
}

char* CommandBuffer::CurrentCode() {
	return commandBuffer[readPointer];
}

bool CommandBuffer::IsEmpty() const {
	return bufferLength == 0;
}

