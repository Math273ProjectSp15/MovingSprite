// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Move spacemario with arrow keys.
// Chapter 5 spacewar.cpp v1.0
// This class is the core of the game

#include "spaceWar.h"

using namespace marioNS;

//=============================================================================
// Constructor
//=============================================================================
Spacewar::Spacewar()
{}

//=============================================================================
// Destructor
//=============================================================================
Spacewar::~Spacewar()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Spacewar::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

    // nebula texture
    if (!nebulaTexture.initialize(graphics,NEBULA_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

    // planet texture
    //if (!planetTexture.initialize(graphics,PLANET_IMAGE))
    //    throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet texture"));

    // spacemario texture
    if (!marioTexture.initialize(graphics,MARIO_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mario texture"));

    // nebula
    if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));
	//nebula.setScale((float)(GAME_HEIGHT/nebula.getHeight()));
	nebula.setScale(GAME_HEIGHT * 1.0/nebula.getHeight());

    // planet
    //if (!planet.initialize(graphics,0,0,0,&planetTexture))
    //    throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));
    //// place planet in center of screen
    //planet.setX(GAME_WIDTH*0.5f  - planet.getWidth()*0.5f);
    //planet.setY(GAME_HEIGHT*0.5f - planet.getHeight()*0.5f);

    // mario
	//if (!mario.initialize(graphics, 0, 0, 0, &marioTexture))
	if (!mario.initialize(this,MARIO_WIDTH, MARIO_HEIGHT, MARIO_COLS, &marioTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mario"));
 //   mario.setX(GAME_WIDTH/4);                    // start above and left of planet
 //   mario.setY(GAME_HEIGHT/4);
	mario.setScale(0.5f);
 //   mario.setFrames(MARIO_START_FRAME, MARIO_END_FRAME);   // animation frames
 //   mario.setCurrentFrame(MARIO_START_FRAME);     // starting frame
 //   mario.setFrameDelay(MARIO_ANIMATION_DELAY);

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{
	if (input->isKeyDown(MARIO_RIGHT_KEY))            // if move right
	{
		mario.moveRight(frameTime);
	}
	if (input->isKeyDown(MARIO_LEFT_KEY))             // if move left
	{
		mario.moveLeft(frameTime);
	}
	//if (input->isKeyDown(mario_UP_KEY))               // if move up
	//{
	//	mario.setY(mario.getY() - frameTime * mario_SPEED);
	//	if (mario.getY() < -mario.getHeight())        // if off screen top
	//		mario.setY((float)GAME_HEIGHT);          // position off screen bottom
	//}
	//if (input->isKeyDown(mario_DOWN_KEY))             // if move down
	//{
	//	mario.setY(mario.getY() + frameTime * mario_SPEED);
	//	if (mario.getY() > GAME_HEIGHT)              // if off screen bottom
	//		mario.setY((float)-mario.getHeight());    // position off screen top
	//}
	mario.update(frameTime);

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Spacewar::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Spacewar::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    nebula.draw();                          // add the orion nebula to the scene
    //planet.draw();                          // add the planet to the scene
    mario.draw();                            // add the spacemario to the scene

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    marioTexture.onLostDevice();
    planetTexture.onLostDevice();
    nebulaTexture.onLostDevice();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    nebulaTexture.onResetDevice();
    planetTexture.onResetDevice();
    marioTexture.onResetDevice();

    Game::resetAll();
    return;
}
