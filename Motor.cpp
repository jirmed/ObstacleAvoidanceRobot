/*
 * Motor.cpp
 *
 *  Created on: 30. 4. 2017
 *      Author: jirka
 */

#include "Motor.h"

Motor::Motor(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4,
		uint8_t enb, uint8_t speedMeterPinL, uint8_t speedMeterPinR,
		boolean invert, uint8_t minspeed) :
		L298N(ena, in1, in2, in3, in4, enb, invert, minspeed), speedMeterL(
				speedMeterPinL), speedMeterR(speedMeterPinR) {
}

void Motor::turnLeft() {
	turn(&Motor::left, QUARTER_TURN_PULSES, MAX_SPEED);
}

void Motor::turnRight() {
	turn(&Motor::right, QUARTER_TURN_PULSES, MAX_SPEED);
}

void Motor::turnBack() {
	turn(&Motor::left, 2*QUARTER_TURN_PULSES, MAX_SPEED);
}

void Motor::moveBack() {
	backward(MAX_SPEED, 500);
	stop();
}

void Motor::forwardCorrected() {
//	  percent = 100;
//	  this->drive(FORWARD_L, 255, 100, 0);
//	  forward();
	if (getPulsesTotal()>=500){
	Serial.print("Pulses Left:");
	Serial.println(speedMeterL.getPulses());
	Serial.print("Pulses Right:");
	Serial.println(speedMeterR.getPulses());
	percent += ((1.0 * speedMeterL.getPulses()) /(1.0 * speedMeterR.getPulses()) - 1.0) * 50;
	percent =  percent < 80 ? 80 : (percent > 120 ? 120: percent);
	Serial.print("Percent:");
	Serial.println(percent);

	clearCounters();
	}
//	  Serial.println(percent);
	  drive((percent <= 100) ? FORWARD_L :FORWARD_R, MAX_SPEED,
        (percent <= 100) ? percent : 200 - percent);
//	  this->drive(FORWARD_R, 254, 96);
}

void Motor::turn(void (Motor::*fn)(uint8_t, int),
		unsigned long pulses, uint8_t speed,
		int delay ) {
	clearCounters();
	while(getPulsesTotal()<= pulses) {
	(this->*fn)(speed,delay);
	}
	stop();
	clearCounters();
}

void Motor::clearCounters() {
	speedMeterL.clearCounter();
	speedMeterR.clearCounter();
}

unsigned long int Motor::getPulsesTotal() {
	return speedMeterR.getPulses() + speedMeterR.getPulses();
}

void Motor::begin() {
	speedMeterL.begin();
	speedMeterR.begin();
}
