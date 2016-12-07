/*
=================
cAsteroid.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cPlatforms.h"

/*
=================================================================
Defualt Constructor
=================================================================
*/
cPlatforms::cPlatforms() : cSprite()
{
	this->platformVelocity = { 10.0, 0.0 };
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cPlatforms::update(double deltaTime)
{

	SDL_Rect currentSpritePos = this->getSpritePos();
	currentSpritePos.x += this->getSpriteTranslation().x * deltaTime * 20;
	currentSpritePos.y += this->getSpriteTranslation().y * deltaTime * 20;

	this->setSpritePos({ currentSpritePos.x, currentSpritePos.y });
	cout << "Asteroid position - x: " << this->getSpritePos().x << " y: " << this->getSpritePos().y << " deltaTime: " << deltaTime << endl;
	this->setBoundingRect(this->getSpritePos());

	if (currentSpritePos.x <= 0 || currentSpritePos.x >= (WINDOW_WIDTH - this->getSpriteDimensions().w))
	{
		this->setSpriteTranslation({ this->getSpriteTranslation().x * (-1), this->getSpriteTranslation().y });
	}

	if (currentSpritePos.y <= 0 || currentSpritePos.y >= (WINDOW_HEIGHT - this->getSpriteDimensions().h))
	{
		this->setSpriteTranslation({ this->getSpriteTranslation().x, this->getSpriteTranslation().y * (-1) });
	}
}
/*
=================================================================
  Sets the velocity for the Asteroid
=================================================================
*/
void cPlatforms::setPlatformVelocity(SDL_Point PlatformVel)
{
	platformVelocity = PlatformVel;
}
/*
=================================================================
  Gets the Asteroid velocity
=================================================================
*/
SDL_Point cPlatforms::getPlatformVelocity()
{
	return platformVelocity;
}
