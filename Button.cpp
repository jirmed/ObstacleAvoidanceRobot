/*
 * Button.cpp
 *
 *  Created on: 30. 4. 2017
 *      Author: jirka
 */

#include "Button.h"

Button::Button (uint8_t pin): pin(pin), state(false) {
}

void Button::setupInterruptHandler( void (*ISR)(void),
		int value) {
	attachInterrupt(digitalPinToInterrupt(this->pin), ISR, value);
}

void Button::handleInterrupt(void) {
	this->toggleState();
}

void Button::handle() {
	if (!lastState) {
		lastState = ! digitalRead(pin);
	}
	else if (!digitalRead(this->pin)) {
		toggleState();
	}
}

void Button::toggleState(void) {
	if ((lastMillis + DEBOUNCE_MILLIS) < millis()) {
		lastMillis = millis();
		state = !state;
	}

}
