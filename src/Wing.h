/*
 * Wing.h
 *
 *  Created on: Oct 25, 2015
 *      Author: ratpack
 */

#ifndef SRC_WING_H_
#define SRC_WING_H_

#include "WPILib.h"

class Wing {
public:
	Wing(Victor * flapper, Victor * extender);
	virtual ~Wing();

	void update();

	void extend();
	void retract();
	void flap (float speed);
protected:
	Victor * flapper;
	Victor * extender;

	const float EXTEND_SPEED = 0.8;
};

#endif /* SRC_WING_H_ */
