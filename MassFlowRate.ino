#include "MassFlowRate.h"

Platform *platform;

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(BAUDRATE);
	Serial.setTimeout(SERIAL_TIMEOUT);
	SPI.begin();

	platform = new Platform();
}

// The loop function is called in an endless loop
void loop() {
	platform->Update();

	if (Serial.available() > 0) {
		if (isalpha(Serial.peek())) {
			String command = Serial.readStringUntil('\n');
			command = command.toUpperCase();
			char code = command.charAt(0);
			int codeNum = command.charAt(1) - '0';
			double value = command.substring(3, command.length()).toFloat();
			InterpetInput(code, codeNum, value);
		}

		else {
			while (Serial.available() > 0 && !isalpha(Serial.peek())) {
				Serial.read();
			}
		}
	}
}

void InterpetInput (char code, int codeNum, double value) {
	switch (code) {
	case 'V':
		Serial.print("VER");
		Serial.println(VERSION);
		break;
	case 'E':
		platform->PrintEndstopStatus();
		break;
	case 'A':
		platform->MoveToInch(value, 0);
		break;
	default:
		break;
	}
}
