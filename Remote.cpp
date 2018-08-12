/*
 * Remote.cpp
 *
 *  Created on: 7. 5. 2017
 *      Author: jirka
 */

#include "Remote.h"

uint8_t Remote::decodeResults(const decode_results& results) {
	switch (results.value) {
	case 0xFFA25D:
		return IR_ON;
	case 0xFFE01F:
		return IR_1;
	case 0xFFA857:
		return IR_2;
	case 0xFF906F:
		return IR_3;
	default:
		return 0;
	}
	return 0;
}

uint8_t Remote::getCommand() {
	uint8_t result = 0;
	decode_results results;
	while (decode(&results)) {
		uint8_t value = decodeResults(results);
		if (value) {
			result = value;
		}
//		Serial.println(results.value, HEX);
		resume(); // Receive the next value
	}
	return result;
}
