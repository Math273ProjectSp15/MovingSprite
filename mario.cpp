#include "mario.h"

using namespace marioNS;

Mario::Mario()
{
	spriteData.width = MARIO_WIDTH;           // size of Ship1
	spriteData.height = MARIO_HEIGHT;
	spriteData.x = X;                   // location on screen
	spriteData.y = Y;
	//spriteData.rect.bottom = shipNS::HEIGHT;    // rectangle to select parts of an image
	//spriteData.rect.right = shipNS::WIDTH;
	velocity.x = 5;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = MARIO_ANIMATION_DELAY;
	startFrame = MARIO_START_FRAME;      // first frame of ship animation
	endFrame = MARIO_END_FRAME;      // last frame of ship animation
	currentFrame = startFrame;
	//radius = WIDTH / 2.0;
	mass = MASS;
	//collisionType = entityNS::CIRCLE;
}

void Mario::update(float frameTime)
{

}

void Mario::moveLeft(double frameTime)
{
	setX(getX() + frameTime * MARIO_SPEED);
	if (getX() > GAME_WIDTH)               // if off screen right
		setX((float)-getWidth());     // position off screen left

}

void Mario::moveRight(double frameTime)
{
	setX(getX() - frameTime * MARIO_SPEED);
	if (getX() < -getWidth())         // if off screen left
		setX((float)GAME_WIDTH);           // position off screen right
}