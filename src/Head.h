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
	Head(Victor * jaw, Victor * head, DigitalOutput * eyeLight, Servo * eyeServo);
	virtual ~Head();
	void Head_up();
	void Head_down();
	void Jaw_up();
	void Jaw_down();
	void reset();
	void toggle_eyes();
	void setEyesPosition(float position);
private:
	Victor * jaw;
	Victor * head;
	Servo * eyeServo;
	DigitalOutput * eyeLight;
	bool eyes_on;
};

#endif /* SRC_HEAD_H_ */
