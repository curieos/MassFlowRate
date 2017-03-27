/*
 * CommandBuffer.h
 *
 *  Created on: Mar 3, 2017
 *      Author: Caroline
 */

#ifndef COMMANDBUFFER_H_
#define COMMANDBUFFER_H_

#include <stdlib.h>
#include "Arduino.h"
#include "Configuration.h"

class CommandBuffer {
public:
	CommandBuffer();
	bool Seen(char c);				//Searches for c in the codeBuffer at readPointer and sets linePointer to it's index
	float GetFloatValue();			//Returns the float value following linePointer in the code buffer
	long GetLongValue();			//Returns the long value following linePointer in the code buffer
	int GetIntValue();
	void FillBuffer();
	char* CurrentCode();
	bool QueueCommand(const char* command);
	void CommandExecuted();
	bool IsEmpty() const;

private:
	char commandBuffer[BUFFER_LENGTH][MAX_COMMAND_LENGTH];
	uint8_t readPointer;		//Where in the buffer we need to read next
	uint8_t linePointer;		//Where in the line to read from (for the Get"X" functions)
	uint8_t writePointer;		//Where in the buffer we will write next
	uint8_t bufferLength;		//How long the buffer is
	int commandIndex;

	char newCommand[MAX_COMMAND_LENGTH];
	bool inComment;
};

inline int CommandBuffer::GetIntValue() {
	return static_cast<int>(GetLongValue());
}

#endif /* COMMANDBUFFER_H_ */
