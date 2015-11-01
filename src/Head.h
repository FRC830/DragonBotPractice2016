/*
 * Head.h
 *
 *  Created on: Oct 25, 2015
 *      Author: ratpack
 */
#include "WPILib.h"

#ifndef SRC_HEAD_H_
#define SRC_HEAD_H_

class Head {
public:
	Head(Victor * jaw, Victor * head, DigitalOutput * eyes);
	virtual ~Head();
	void Head_up();
	void Head_down();
	void Jaw_up();
	void Jaw_down();
	void reset();
	void toggle_eyes();
private:
	Victor * jaw;
	Victor * head;
	DigitalOutput * eyes;
	bool eyes_on;
};

#endif /* SRC_HEAD_H_ */
