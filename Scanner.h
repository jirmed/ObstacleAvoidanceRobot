/**
 * @file Scanner.h
 *  @author Jiri Medved
 */
#include "Arduino.h"

#ifndef SCANNER_H_
#define SCANNER_H_

/**
 * Max left position
 */
#define LOOK_LEFT 145

/**
 * Center possition
 */
#define LOOK_CENTER 80

/**
 * Max right possition
 */
#define LOOK_RIGHT 25

#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

/**
 * @brief Ultrasonic scanner on servo chassis
 */

class Scanner {
public:

	/** @brief Default constructor
	 * @param servoPin - Servo Pin
	 * @param trigPin - Trigger Pin (Ultrasonic)
	 * @param echoPin - Echo Pin (Ultrasonic)
	 */
	Scanner(uint8_t servoPin, uint8_t trigPin, uint8_t echoPin);

	/**
	 * @brief Initialize the scanner - should be run in setup
	 */
	void begin();

	/**
	 * @brief Turns chassis to position
	 */
	void turnTo(uint8_t);

	/**
	 * @brief Turn max left and get distance
	 * @return Distance in cm
	 */
	uint16_t getLeft();

	/**
	 * @brief Turn to center and get distance
	 * @return Distance in cm
	 */
	uint16_t getCenter();

	/**
	 * @brief Turn max right and get distance
	 * @return Distance in cm
	 */
	uint16_t getRight();
private:
	Servo myServo;
	Ultrasonic myUltrasonic;
	uint8_t pos = LOOK_CENTER;
	uint8_t servoPin;
	static const int SCAN_DELAY = 10;
};

#endif /* SCANNER_H_ */
