/*
 * Button.h
 *
 *  Created on: 30. 4. 2017
 *      Author: jirka
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <Arduino.h>
#define DEBOUNCE_MILLIS 10

class Button {
public:
	Button(uint8_t pin);
	void setupInterruptHandler( void (*ISR)(void), int value);
	void handleInterrupt(void);
	void handle(void);

	void toggleState(void);

	boolean isState() const {
		return state;
	}

	void setState(boolean state) {
		this->state = state;
	}

private:
	uint8_t pin;
	boolean state;
	boolean lastState;
	uint32_t lastMillis = 0UL;
};

#endif /* BUTTON_H_ */
