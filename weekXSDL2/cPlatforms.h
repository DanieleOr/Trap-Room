/*
=================
cAsteroid.h
- Header file for class definition - SPECIFICATION
- Header file for the Rocket class which is a child of cSprite class
=================
*/
#ifndef _CPLATFORMS_H
#define _CPLATFORMS_H
#include "cSprite.h"

class cPlatforms : public cSprite
{
private:
	SDL_Point platformVelocity;

public:
	cPlatforms();
	void update(double deltaTime);		// Rocket update method
	void setPlatformVelocity(SDL_Point platformVel);   // Sets the velocity for the asteroid
	SDL_Point getPlatformVelocity();				 // Gets the asteroid velocity
};
#endif