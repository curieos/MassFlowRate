# MassFlowRate
Code to run a mass airflow experiment on a Teensy 3.2

## Electronics
This code is meant to run on a Teensy 3.2 with AMIS30543 stepper drivers, an Adafruit MAX31855, two OMEGA differential pressure sensors and an OMEGA pressure transducer. Pinouts can be read/changed from the Configuration.h file.

## Hardware
The electronics are meant to control two perpendicular stepper controlled actuators. We are using screw driven ones from OpenBuilds and mechanical switch endstops to set the endpoints.

## Code
The code is split into several objects. Most of it runs on 3 separate systems that can interact from time to time. There is a serial interpreter which contains a serial command buffer object, a sensors object which contains and controls all the sensors, and a platform object which contains and controls the actuators and prevents the pitot tubes from crashing in the tube.
There are a few libraries this relys on to compile. The code needs the SPI, EEPROM, AccelStepper, AMIS30543, and Adafruit_MAX31855 libraries. If you are not using Teensy, you will also need the ElapsedMillis library from PJRC.
