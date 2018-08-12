/**
 * @brief Robot drive
 * @author Jiri Medved
 */

#ifndef DRIVE_H_
#define DRIVE_H_

#include <Arduino.h>
#include <L298N.h>

/**
 * @brief Drive class (L298N motor wrapper)
 */
class Drive {
public:
	Drive();
	/**
	 * Drive forward
	 */
	void forward();
	/**
	 * Drive backward
	 */
	void backward();
	/**
	 * Stop
	 */
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
