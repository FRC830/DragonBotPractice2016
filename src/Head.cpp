/*
 * Head.cpp
 *
 *  Created on: Oct 25, 2015
 *      Author: ratpack
 */

#include <Head.h>

Head::Head(Victor * jaw, Victor * head, DigitalOutput * eyes)
	:jaw(jaw), head(head), eyes(eyes), eyes_on(false)
{
	eyes->Set(0);
}


Head::~Head() {
	// TODO Auto-generated destructor stub
}

void Head::Head_up() {
	head->Set(0.4);
}

void Head::Head_down() {
	head->Set(-0.2);
}

void Head::Jaw_up() {
	jaw->Set(0.2);
}

void Head::Jaw_down() {
	jaw->Set(-0.4);
}

void Head::reset() {
	jaw->Set(0.0);
	head->Set(0.0);
}

void Head::toggle_eyes() {
	eyes_on = !eyes_on;
	eyes->Set(eyes_on);
}
