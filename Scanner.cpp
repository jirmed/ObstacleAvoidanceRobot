/*
 * Scanner.cpp
 *
 *  Created on: 29. 4. 2017
 *      Author: jirka
 */
#include "Scanner.h"

Scanner::Scanner(uint8_t servoPin, uint8_t trigPin, uint8_t echoPin)
	: myServo(),
	  myUltrasonic(trigPin, echoPin),
	  pos(LOOK_CENTER),
	  servoPin(servoPin) {
}

void Scanner::begin() {
	myServo.attach(servoPin);
	myServo.write(pos);
}

void Scanner::turnTo(uint8_t turnPos) {
	while (pos != turnPos) {
		if (pos < turnPos) {
			pos++;
		} else {
			pos--;
		}
		myServo.write(pos);
//		tone(11,800,50);
		delay(5);;
	}
	delay(10);
}


uint16_t Scanner::getLeft() {
	turnTo(LOOK_LEFT);
	delay (SCAN_DELAY);
	return myUltrasonic.distanceRead();
}

uint16_t Scanner::getCenter() {
turnTo(LOOK_CENTER);
	delay (SCAN_DELAY);
return myUltrasonic.distanceRead();
}

uint16_t Scanner::getRight() {
turnTo(LOOK_RIGHT);
	delay (SCAN_DELAY);
return myUltrasonic.distanceRead();
}

