/*
 * Platform.h
 *
 *  Created on: Jan 26, 2017
 *      Author: Caroline
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "Actuator.h"
#include "Configuration.h"

/**
 * This object contains and manages 2 actuators
 */
class Platform {
public:
	Platform();

	/**
	 * This function moves the X actuator to a position in inches
	 * @param pos The position to move to in inches
	 */
	void MoveXInch(double pos);

	/**
	 * This function moves the Y actuator to a position in inches
	 * @param pos The position to move to in inches
	 */
	void MoveYInch(double pos);

	/**
	 * This function moves the X actuator to a position in mm
	 * @param pos The position to move to in mm
	 */
	void MoveX(double pos);

	/**
	 * This function moves the Y actuator to a position in mm
	 * @param pos The position to move to in mm
	 */
	void MoveY(double pos);

	/**
	 * This function tells all actuators to move to the home position
	 */
	void HomeAll();

	/**
	 * This function is meant to be called every loop(). It will check the state of the actuators, handle printing the positions to serial, and tell the actuators to move
	 */
	void Update();

	/**
	 * A debug function to check if the endstops are working correctly
	 */
	void PrintEndstopStatus();

	/**
	 * Called to print the positions of the actuators in "A{actuator #}S{position} format
	 */
	void PrintPositions();

	/**
	 * This function tells the actuators to write their config data to EEPROM
	 */
	void WriteConfig();

	/**
	 * This funcition tells the actuators to read the config data from EEPROM, useful to revert bad config changes
	 */
	void ReadConfig();

	//inline bool Moving() { return x->Moving() || y->Moving(); }
	/**
	 * This function makes the current position of the X actuator the "0" point.
	 */
	inline void SetXMid() {
		x->SetMidPosition();
	}

	/**
	 * This function makes the current position of the Y actuator the "0" point.
	 */
	inline void SetYMid() {
		y->SetMidPosition();
	}

	/**
	 * This function returns the current MoveState. This can be used to determine if any actuators are in use, and what they are doing.
	 * @return The current movement state
	 */
	inline MoveState GetState() {
		return state;
	}

private:
	/**
	 * This is the timer object used to keep track of when we last sent serial data
	 */
	elapsedMillis timer;

	/**
	 * The overall state of the actuators. If one is moving this is moving, else if one is homing this is homing, else if one is calibrating this is calibrating, etc
	 */
	MoveState state;

	/**
	 * The actuator that moves in the "X" direction
	 */
	Actuator *x;

	/**
	 * The actuator that moves in the "Y" direction
	 */
	Actuator *y;

	/**
	 * Keeps track of wether we have homed yet
	 */
	bool homed;
};

#endif /* PLATFORM_H_ */
