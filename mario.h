#pragma once
#define WIN32_LEAN_AND_MEAN

#include "entity.h"


namespace marioNS
{

}

class Mario : public Entity
{
public:
	//Constructor
	Mario();

	//Inherited from entity
	void update(float frameTime);
	void moveLeft(double frameTime);
	void moveRight(double frameTime);
};
