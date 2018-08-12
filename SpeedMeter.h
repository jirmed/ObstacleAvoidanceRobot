/*
 * SpeedMeter.h
 *
 *  Created on: 22. 7. 2017
 *      Author: jirka
 */
#include "Arduino.h"

#ifndef SPEEDMETER_H_
#define SPEEDMETER_H_

class SpeedMeter {
private:
	uint8_t pin;

	volatile unsigned long pulses;

	unsigned long lastMillis;

	static SpeedMeter * instances[2];

	static void switchPressedExt0();

	static void switchPressedExt1();

public:
	SpeedMeter(const uint8_t pin);

	void begin();

	void sensorFalling();

	void clearCounter();

	unsigned long getPulses() {
		return pulses;
	}
};

#endif

