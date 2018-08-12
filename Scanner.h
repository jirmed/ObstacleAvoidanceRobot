/*
 * Scanner.h
 *
 *  Created on: 29. 4. 2017
 *      Author: jirka
 */
#include "Arduino.h"

#ifndef SCANNER_H_
#define SCANNER_H_

#define LOOK_LEFT 145
#define LOOK_CENTER 80
#define LOOK_RIGHT 25

#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

class Scanner {
public:
	Scanner(uint8_t servoPin, uint8_t trigPin, uint8_t echoPin);
	void begin();
	void turnTo(uint8_t);
	uint16_t getLeft();
	uint16_t getCenter();
	uint16_t getRight();
private:
	Servo myServo;
	Ultrasonic  myUltrasonic;
	uint8_t pos = LOOK_CENTER;
	uint8_t servoPin;
	static const int SCAN_DELAY = 10;
};

#endif /* SCANNER_H_ */
