/*
=================
cMan.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cMan.h"

/*
=================================================================
Defualt Constructor
=================================================================
*/
cMan::cMan() : cSprite()
{
	this->manVelocity = { 0.0f, 0.0f };
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cMan::update(double deltaTime)
{

	FPoint direction = { 0.0f, 0.0f };
	direction.X = (sin(this->getSpriteRotAngle()*PI / 180));
	direction.Y = -(cos(this->getSpriteRotAngle()*PI / 180));

	direction.X *= this->getSpriteTranslation().x;
	direction.Y *= this->getSpriteTranslation().y;

	this->manVelocity.x = this->manVelocity.x + direction.X;
	this->manVelocity.y = this->manVelocity.y + direction.Y;

	SDL_Rect currentSpritePos = this->getSpritePos();
	currentSpritePos.x += this->getSpriteTranslation().x * deltaTime * 10;
	currentSpritePos.y += this->getSpriteTranslation().y * deltaTime * 10;

	this->manVelocity.x *= 0.95;
	this->manVelocity.y *= 0.95;
	
	this->setSpritePos({ currentSpritePos.x , currentSpritePos.y  });
	cout << "man" << endl;
	this->setBoundingRect(this->getSpritePos());

	if (currentSpritePos.x <= 1 || currentSpritePos.x >= (1024 - this->getSpriteDimensions().w))
	{
		this->setSpriteTranslation({ this->getSpriteTranslation().x * (-1), this->getSpriteTranslation().y });
	}

	if (currentSpritePos.y <= 1 || currentSpritePos.y >= (700 - this->getSpriteDimensions().h))
	{
		this->setSpriteTranslation({ this->getSpriteTranslation().x, this->getSpriteTranslation().y * (-1) });
	}
	this->setSpriteTranslation({0,0});
}
/*
=================================================================
Sets the velocity for the man
=================================================================
*/
void cMan::setManVelocity(SDL_Point manVel)
{
	manVelocity = manVel;
}
/*
=================================================================
Gets the man velocity
=================================================================
*/
SDL_Point cMan::getManVelocity()
{
	return manVelocity;
}


/*
=================================================================
Update the sprite position
=================================================================
*/


//
//	glm::vec2 spriteVelocityAdd = glm::vec2(0.0f, 0.0f);
//	spriteVelocityAdd.x = (glm::sin(glm::radians(spriteRotation)));
//	spriteVelocityAdd.y = -(glm::cos(glm::radians(spriteRotation)));
//
//	spriteVelocityAdd *= spriteTranslation;
//
//	manVelocity += spriteVelocityAdd;
//
//	spritePos2D += manVelocity * deltaTime;
//
//	manVelocity *= 0.95;
//
//	/*
//	==============================================================
//	| Check for collisions
//	==============================================================
//	*/
//	for (vector<cBullet*>::iterator bulletIterartor = themanBullets.begin(); bulletIterartor != themanBullets.end(); ++bulletIterartor)
//	{
//		(*bulletIterartor)->update(deltaTime);
//		for (vector<cAsteroid*>::iterator asteroidIterator = theAsteroids.begin(); asteroidIterator != theAsteroids.end(); ++asteroidIterator)
//		{
//			if ((*asteroidIterator)->collidedWith((*asteroidIterator)->getBoundingRect(), (*bulletIterartor)->getBoundingRect()))
//			{
//				// if a collision set the bullet and asteroid to false
//				(*asteroidIterator)->setActive(false);
//				(*bulletIterartor)->setActive(false);
//			}
//		}
//	}
//
//	vector<cBullet*>::iterator bulletIterartor = themanBullets.begin();
//	while (bulletIterartor != themanBullets.end())
//	{
//		if ((*bulletIterartor)->isActive() == false)
//		{
//			bulletIterartor = themanBullets.erase(bulletIterartor);
//		}
//		else
//		{
//			//(*bulletIterartor)->update(deltaTime);
//			(*bulletIterartor)->render();
//			(*bulletIterartor)->renderCollisionBox();
//			++bulletIterartor;
//		}
//	}
//}