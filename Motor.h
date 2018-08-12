/*
 * Motor.h
 *
 *  Created on: 30. 4. 2017
 *      Author: jirka
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <L298N.h>
#include "SpeedMeter.h"
#define MAX_SPEED 255
#define TURN_TIME 500
#define TURN_BACK_TIME 900

class Motor: public L298N {
//	using: L298N::L298N;
private:
	void turn(void (Motor::*fn)(uint8_t, int),
			unsigned long pulses, uint8_t speed = MAX_SPEED,
			int delay = 1);
	void clearCounters();
	unsigned long int getPulsesTotal();
	long percent = 100;

	static const int QUARTER_TURN_PULSES = 60;

public:
	Motor(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4,
			uint8_t enb, uint8_t speedMeterPinL, uint8_t speedMeterPinR,
			boolean invert = false, uint8_t minspeed = 0);
	void turnLeft();
	void turnRight();
	void turnBack();
	void moveBack();
	void forwardCorrected();
	SpeedMeter speedMeterL;
	SpeedMeter speedMeterR;
	void begin();
};

#endif /* MOTOR_H_ */
