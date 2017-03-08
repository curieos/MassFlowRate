#include "MassFlowRate.h"

Platform *platform;
Sensors *sensors;
Interpreter *interpreter;

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(BAUDRATE);
	Serial.setTimeout(SERIAL_TIMEOUT);
	SPI.begin();
	analogReadResolution(ADC_RESOLUTION);

	delay(500);

	platform = new Platform();
	sensors = new Sensors();
	interpreter = new Interpreter(platform);
}

// The loop function is called in an endless loop
void loop() {
	platform->Update();
	sensors->Update();
	interpreter->Update();
}
