/*
 * Remote.h
 *
 *  Created on: 7. 5. 2017
 *      Author: jirka
 */

#ifndef REMOTE_H_
#define REMOTE_H_

#include <IRremote.h>

class Remote: public IRrecv {
public:
	Remote(uint8_t remotePin): IRrecv(remotePin) {};
	uint8_t getCommand();

	static const uint8_t
		IR_ON = 11,
		IR_1 = 1,
		IR_2 = 2,
		IR_3 = 3,
		IR_4 = 4,
		IR_5 = 5,
		IR_6 = 6,
		IR_7 = 7,
		IR_8 = 8,
		IR_9 = 9,
		IR_0 = 10;

private:
	uint8_t decodeResults(const decode_results& results);
};

#endif /* REMOTE_H_ */
