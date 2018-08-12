/*
 * Drive.cpp
 *
 *  Created on: 30. 4. 2017
 *      Author: jirka
 */

#include "Drive.h"

Drive::Drive(): motor(ENA, IN1, IN2, IN3, IN4, ENB, false, MINSPEED) {
	// TODO Auto-generated constructor stub

}

void Drive::forward() {
	motor.forward();
}

void Drive::backward() {
	motor.forward();
}

void Drive::stop() {
	motor.stop(true);
}
