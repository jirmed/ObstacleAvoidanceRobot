/*
 * SpeedMeter.cpp
 *
 *  Created on: 22. 7. 2017
 *      Author: jirka
 */

#include "SpeedMeter.h"

SpeedMeter * SpeedMeter::instances[2] = { NULL, NULL };

SpeedMeter::SpeedMeter(const uint8_t pin) :
		pin(pin),
		lastMillis(millis()){
}


inline void SpeedMeter::switchPressedExt0() {
	if (SpeedMeter::instances[0] != NULL)
		SpeedMeter::instances[0]->sensorFalling();
} // end of SpeedMeter::switchPressedExt0

inline void SpeedMeter::switchPressedExt1() {
	if (SpeedMeter::instances[1] != NULL)
		SpeedMeter::instances[1]->sensorFalling();
} // end of SpeedMeter::switchPressedExt1

void SpeedMeter::begin() {
	pinMode(pin, INPUT_PULLUP);
	switch (pin) {
	case 2:
		attachInterrupt(0, switchPressedExt0, FALLING);
		instances[0] = this;
		break;

	case 3:
		attachInterrupt(1, switchPressedExt1, FALLING);
		instances[1] = this;
		break;

	}
	clearCounter();
} // end of SpeedMeter::begin

inline void SpeedMeter::sensorFalling() {
	pulses++;
}


void SpeedMeter::clearCounter() {
	pulses = 0;
	lastMillis = millis();
}
