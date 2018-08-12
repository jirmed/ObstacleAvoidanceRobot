#include "Arduino.h"
#include "Scanner.h"
#include "Motor.h"
#include "Button.h"
#include "Remote.h"

#define TRIG_PIN A4
#define ECHO_PIN A5
#define SERVO_PIN 4

#define MIN_DISTANCE 30
#define MIN_DIFFERENCE 5

#define BUTTON_PIN A0
#define HEADER_LEFT_PIN A1
#define HEADER_RIGHT_PIN A2

#define SPEEDMETER_PIN_L 2
#define SPEEDMETER_PIN_R 3


#define REMOTE_PIN 12

const uint8_t ENA = 5;
const uint8_t ENB = 6;
const uint8_t IN1 = 9;
const uint8_t IN2 = 10;
const uint8_t IN3 = 7;
const uint8_t IN4 = 8;


const uint8_t MINSPEED = 100;
const uint8_t MAXSPEED = 255;

Scanner scanner(SERVO_PIN, TRIG_PIN, ECHO_PIN);
Motor motor( ENA, IN1, IN2, IN3, IN4, ENB, SPEEDMETER_PIN_L, SPEEDMETER_PIN_R, false, MINSPEED);
Button button(BUTTON_PIN);
Remote remote(REMOTE_PIN);

/*
inline void buttonInterruptHandler() {
	button.handleInterrupt();
}
*/

void setup() {
	Serial.begin(9600);
	scanner.begin();
	motor.begin();
//	button.setupInterruptHandler(BUTTON_PIN, buttonInterruptHandler, FALLING);
	remote.enableIRIn();
}

void handleIR() {
	switch (remote.getCommand()) {
	case remote.IR_ON:
		button.setState(!button.isState());
		break;
	case remote.IR_1:
		motor.turnLeft();
		break;
	case remote.IR_3:
		motor.turnRight();
		break;
	case remote.IR_2:
		motor.turnBack();
		break;
	default:
		break;
	}
}

void handleHeader() {
	if (digitalRead(HEADER_LEFT_PIN) || digitalRead(HEADER_RIGHT_PIN)) {
		motor.moveBack();
		motor.turnBack();
	}
}

// The loop function is called in an endless loop
void loop() {

	button.handle();
	handleIR();
	handleHeader();
	if (button.isState()) {
		go();
	} else {
		motor.stop();
	}

//	testTurn();
	delay(1);
}

void testScanner() {
	Serial.print("Left:");
	Serial.println(scanner.getLeft());
	//  delay(300);

	Serial.print("Right");
	Serial.println(scanner.getRight());
	//  delay(300);

	Serial.print("Center:");
	Serial.println(scanner.getCenter());
	delay(2000);
}

void testMotor() {
	motor.forward();
	delay(2000);
	motor.stop();

	motor.backward();
	delay(2000);
	motor.stop();
}

void testTurn() {
	motor.turnBack();
	delay(2000);
}

void go() {
	uint16_t distance = scanner.getCenter();
	Serial.println(distance);
	if (distance > MIN_DISTANCE) {
		motor.forwardCorrected();
	} else {
		motor.stop();
		handleObstacle();
	}
}

void handleObstacle() {
	int distanceLeft = scanner.getLeft();
	int distanceRight = scanner.getRight();
	int distanceCenter = scanner.getCenter();
	if (max(distanceLeft, distanceRight) > distanceCenter + MIN_DIFFERENCE)
		if (distanceLeft > distanceRight)
			motor.turnLeft();
		else
			motor.turnRight();
	else
		motor.turnBack();
}
