// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 5 constants.h v1.0
#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// graphic images
const char NEBULA_IMAGE[] = "pictures\\full-background.png";
//const char NEBULA_IMAGE[] = "pictures\\orion.jpg";  // photo source NASA/courtesy of nasaimages.org 
const char PLANET_IMAGE[] = "pictures\\planet.png"; // picture of planet
//const char SHIP_IMAGE[]   = "pictures\\ship.png";   // spaceship
const char MARIO_IMAGE[] = "pictures\\RedHeadBoy.png";   // spaceship


// window
const char CLASS_NAME[] = "Spacewar";
const char GAME_TITLE[] = "Spacewar";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  1280;               // width of game in pixels
const UINT GAME_HEIGHT = 800;               // height of game in pixels
const float ROTATION_RATE = 180.0f;         // degrees per second
const float SCALE_RATE = 0.2f;              // % change per second


// game
const double PI = 3.14159265;
const float FRAME_RATE  = 200.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const int BACKGROUND_HEIGHT = 1536;

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key
const UCHAR MARIO_LEFT_KEY    = VK_LEFT;     // left arrow
const UCHAR MARIO_RIGHT_KEY   = VK_RIGHT;    // right arrow
const UCHAR MARIO_UP_KEY      = VK_UP;       // up arrow
const UCHAR MARIO_DOWN_KEY    = VK_DOWN;     // down arrow

//mario consants
const int  MARIO_START_FRAME = 0;            // starting frame of MARIO animation
const int  MARIO_END_FRAME = 5;              // last frame of MARIO animation
const float MARIO_ANIMATION_DELAY = 0.05f;    // time between frames of MARIO animation
const int  MARIO_COLS = 6;                   // MARIO texture has 2 columns
const int  MARIO_WIDTH = 98;                 // width of MARIO image
const int  MARIO_HEIGHT = 162;                // height of MARIO image
const float MARIO_SPEED = 400.0f;            // pixels per second
const float MARIO_SCALE = 1.5f;              // starting MARIO scale
const int X = 0;
const int Y = 1166 / (BACKGROUND_HEIGHT)* GAME_HEIGHT;
const double MASS = 300.00;					//MASS



#endif
