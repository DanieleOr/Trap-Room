/*
=================
cRocket.h
- Header file for class definition - SPECIFICATION
- Header file for the Rocket class which is a child of cSprite class
=================
*/
#ifndef _CMAN_H
#define _CMAN_H
#include "cSprite.h"

class cMan : public cSprite
{
private:
	SDL_Point manVelocity;

public:
	cMan();
	void update(double deltaTime);		// Rocket update method
	void setManVelocity(SDL_Point rocketVel);   // Sets the velocity for the rocket
	SDL_Point getManVelocity();				 // Gets the rocket velocity
};
#endif