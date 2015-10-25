/*
 * Wing.cpp
 *
 *  Created on: Oct 25, 2015
 *      Author: ratpack
 */

#include <Wing.h>

Wing::Wing(Victor * flapper, Victor * extender)
	:flapper(flapper), extender(extender)
{}

Wing::~Wing() {
	// TODO Auto-generated destructor stub
}

void Wing::extend() {
	extender->Set(EXTEND_SPEED);
}

void Wing::retract() {
	extender->Set(-EXTEND_SPEED);
}

void Wing::flap(float speed){
	flapper->Set(speed);
}

void Wing::update(){
	extender->Set(0);
	flapper->Set(0);
}
