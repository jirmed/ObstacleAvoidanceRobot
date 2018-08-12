/*
 * Drive.h
 *
 *  Created on: 30. 4. 2017
 *      Author: jirka
 */

#ifndef DRIVE_H_
#define DRIVE_H_

#include <Arduino.h>
#include <L298N.h>

class Drive {
public:
	Drive();
	void forward();
	void backward();
	void stop();
private:
	L298N motor;

	const uint8_t ENA = 10;
	const uint8_t ENB = 5;
	const uint8_t IN1 = 8;
	const uint8_t IN2 = 9;
	const uint8_t IN3 = 6;
	const uint8_t IN4 = 7;

	const uint8_t MINSPEED = 150;
	const uint8_t MAXSPEED = 200;
};

#endif /* DRIVE_H_ */
