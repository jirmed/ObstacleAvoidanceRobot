/**
 * @file
 * @brief Start stop button
 * @author Jiri Medved
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <Arduino.h>

/**
 * Minimum time between presses
 */
#define DEBOUNCE_MILLIS 10

/**
 * @brief Start/stop Button class
 */
class Button {
public:
	/**
	 * @brief Default constructor
	 * @param pin - Button pin
	 */
	Button(uint8_t pin);

	/**
	 * @brief Runs when button state changes
	 * @param *ISR - routine to handle - should always be handleInterrupt()
	 * @param value - state value (LOW, RISING, FALLING, CHANGE)
	 */
	void setupInterruptHandler( void (*ISR)(void), int value);

	/**
	 * @brief Handles interrupt - toggles button state
	 */
	void handleInterrupt(void);

	/**
	 * @brief Toggle state when pressed
	 */
	void handle(void);

	/**
	 * @brief Toggle state
	 */
	void toggleState(void);

	/**
	 * @brief Get State
	 * @return Current State
	 */
	boolean isState() const {
		return state;
	}

	/**
	 * @brief Set state
	 * @param state - New State
	 */
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
