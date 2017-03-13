#include "MassFlowRate.h"
#include "EEPROMRW.h"

Platform *platform;
Sensors *sensors;
Interpreter *interpreter;

#define FRESH_FLASH false

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

	if (FRESH_FLASH) {
		EEPROMRW::SetFloatValue(X_MIN_REG, ACTUATOR_MIN_DEFAULT);
		EEPROMRW::SetFloatValue(X_MAX_REG, ACTUATOR_MAX_DEFAULT);
		EEPROMRW::SetFloatValue(Y_MIN_REG, ACTUATOR_MIN_DEFAULT);
		EEPROMRW::SetFloatValue(Y_MAX_REG, ACTUATOR_MAX_DEFAULT);
		EEPROMRW::SetFloatValue(ABS_SLOPE_REG, ABS_SLOPE_DEFAULT);
		EEPROMRW::SetFloatValue(ABS_OFFSET_REG, ABS_OFFSET_DEFAULT);
		EEPROMRW::SetFloatValue(DIFF_1_SLOPE_REG, DIFF_SLOPE_DEFAULT);
		EEPROMRW::SetFloatValue(DIFF_1_OFFSET_REG, DIFF_OFFSET_DEFAULT);
		EEPROMRW::SetFloatValue(DIFF_2_SLOPE_REG, DIFF_SLOPE_DEFAULT);
		EEPROMRW::SetFloatValue(DIFF_2_OFFSET_REG, DIFF_OFFSET_DEFAULT);
	}
}

// The loop function is called in an endless loop
void loop() {
	platform->Update();
	sensors->Update();
	interpreter->Update();
}
