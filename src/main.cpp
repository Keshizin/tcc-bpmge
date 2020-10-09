/*
	Game Engine Template
	This file provide a template for a game created with BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <windows.h>
#include <iostream>
#include <ctime>

#include <ge.h>
#include <gesprite.h>

// ----------------------------------------------------------------------------
//  GLOBAL ESCOPE
// ----------------------------------------------------------------------------
#define GAME_WINDOW_WIDTH 800
#define GAME_WINDOW_HEIGHT 800

#define WORLD_LEFT   -1000
#define WORLD_RIGHT   1000
#define WORLD_TOP     1000
#define WORLD_BOTTOM -1000

#define SPRITE_COUNTING 1000
#define SPRITE_SIZE 32

GESprite *sprites;
GameEngine *gameEngine = 0;

class UserEventHandler : public GEEventHandler
{
	void frameEvent();
	void mouseEvent(int button, int state, int x, int y);
	void mouseMotionEvent(int x, int y);
	void keyboardEvent(unsigned char key, int state);
	void keyboardSpecialEvent(unsigned char key, int state);
	void resizeWindowEvent(int width, int height);
	void finishAfterEvent();
	void finishBeforeEvent();
	void resumeEvent();
	void pauseEvent();
	void beforeMainLoopEvent();
};

// ----------------------------------------------------------------------------
//  MAIN APPLICATION
// ----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(0));

	std::cout << "> HELLO BPM Game Engine" << std::endl;

	#ifdef GEDEBUG
	std::cout << "(!) DEBUG MODE ACTIVATED" << std::endl;
	#endif

	// START UP GAME ENGINE
	UserEventHandler eventHandler;
	gameEngine = new GameEngine(&eventHandler);

	// SETTING UP SPRITES
	sprites = new GESprite[SPRITE_COUNTING];

	// SETTING UP WINDOW GAME
	gameEngine->getGameWindow()->setName("Game Engine - BOUNDING COLLISION TEST!");
	gameEngine->getGameWindow()->setWidth(GAME_WINDOW_WIDTH);
	gameEngine->getGameWindow()->setHeight(GAME_WINDOW_HEIGHT);
	gameEngine->getGameWindow()->setX(960 - (GAME_WINDOW_WIDTH / 2));
	gameEngine->getGameWindow()->setY(540 - (GAME_WINDOW_HEIGHT / 2));
	gameEngine->getGameWindow()->setStyle(GE_WIN_COMPLETE);
	gameEngine->getGameWindow()->createWindow();

	// SETTING UP RENDERING ENGINE
	gameEngine->getRenderingSystem()->setRenderingContext(GE_CONTEXT_2D);
	gameEngine->getRenderingSystem()->setViewport(0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	gameEngine->getRenderingSystem()->setWorld(WORLD_LEFT, WORLD_RIGHT, WORLD_TOP, WORLD_BOTTOM);
	gameEngine->getRenderingSystem()->setWindowAspectCorrectionState(false);
	// gameEngine->getRenderingSystem()->setWorldAxisSate(true);
	gameEngine->getRenderingSystem()->initialize();
	gameEngine->getApiWrapper()->setVSync(0);

	gameEngine->getRenderingSystem()->setProjection();
	gameEngine->getGameWindow()->showWindow();

	// SETTING UP SPRITES
	for(int i = 0; i < SPRITE_COUNTING; i++)
	{
		int speed_x = (rand() % 800) - 400;
		int speed_y = (rand() % 800) - 400;

		sprites[i].setPosition(0, 0);
		sprites[i].setSpeed(speed_x, speed_y);
		sprites[i].setSize(SPRITE_SIZE, SPRITE_SIZE);
		sprites[i].setBoundsAction(BA_BOUNCE);
		sprites[i].setBounding(WORLD_LEFT / 2, WORLD_RIGHT / 2, WORLD_TOP / 2, WORLD_BOTTOM / 2);
	}

	// STARTING GAME LOOP
	gameEngine->setFrameRate(0);
	gameEngine->startMainLoop();

	// RELEASE GAME ENGINE
	delete gameEngine;

	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}

// GLOBAL METHODS DEFINITION

void UserEventHandler::frameEvent()
{
	// glClearColor(1.0, 1.0, 1.0, 0.0);
	// glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearColorHex(28, 29, 23, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);

	// gameEngine->getRenderingSystem()->drawWorldAxis();

	// updating sprites
	for(int i = 0; i < SPRITE_COUNTING; i++)
	{
		sprites[i].update(gameEngine->getTimeHandler()->getFrameTimeInSeconds());
	}

	// drawing sprites
	for(int i = 0; i < SPRITE_COUNTING; i++)
	{
		sprites[i].draw();
	}
}

void UserEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void UserEventHandler::mouseMotionEvent(int x, int y)
{
}

void UserEventHandler::keyboardEvent(unsigned char key, int state)
{
	if(key == '0' && state == 0)
	{
		for (int i = 0; i < SPRITE_COUNTING; i++)
			sprites[i].setVisible(!sprites[i].getVisible());
	}

	if(key == '1' && state == 0)
	{
		for (int i = 0; i < SPRITE_COUNTING; i++)
			sprites[i].setBoundsAction(BA_STOP);
	}

	if(key == '2' && state == 0)
	{
		for (int i = 0; i < SPRITE_COUNTING; i++)
			sprites[i].setBoundsAction(BA_WRAP);
	}

	if(key == '3' && state == 0)
	{
		for (int i = 0; i < SPRITE_COUNTING; i++)
			sprites[i].setBoundsAction(BA_BOUNCE);
	}

	if(key == '4' && state == 0)
	{
		for(int i = 0; i < SPRITE_COUNTING; i++)
		{
			int x = (rand() % (WORLD_RIGHT * 2 - SPRITE_SIZE)) + WORLD_LEFT;
			int y = (rand() % (WORLD_TOP * 2 - SPRITE_SIZE)) + WORLD_BOTTOM;
			sprites[i].setPosition(x, y);
		}
	}

	if(key == '5' && state == 0)
	{
		for(int i = 0; i < SPRITE_COUNTING; i++)
		{
			int speed_x = (rand() % 800) - 400;
			int speed_y = (rand() % 800) - 400;
			sprites[i].setSpeed(speed_x, speed_y);
		}
	}

	if(key == '6' && state == 0)
	{
		for(int i = 0; i < SPRITE_COUNTING; i++)
		{
			sprites[i].setBounding(-1920, 1920, 1017, -1017);
		}
	}

	if(key == '7' && state == 0)
	{
		for(int i = 0; i < SPRITE_COUNTING; i++)
		{
			int speed_x = (rand() % 800) - 400;
			int speed_y = (rand() % 800) - 400;

			sprites[i].setPosition(0, 0);
			sprites[i].setSpeed(speed_x, speed_y);
			sprites[i].setBounding(WORLD_LEFT / 2, WORLD_RIGHT / 2, WORLD_TOP / 2, WORLD_BOTTOM / 2);
		}
	}

	if(key == '8' && state == 0)
	{
		for(int i = 0; i < SPRITE_COUNTING; i++)
		{
			sprites[i].setPosition(0, 0);
			sprites[i].setSpeed(0, 0);
		}
	}

	if(key == 27)
	{
		gameEngine->stopMainLoop();
	}
}

void UserEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
}

void UserEventHandler::resizeWindowEvent(int width, int height)
{
	gameEngine->getRenderingSystem()->setViewport(0, 0, width, height);
	gameEngine->getRenderingSystem()->setWorldLeft(-width);
	gameEngine->getRenderingSystem()->setWorldRight(width);
	gameEngine->getRenderingSystem()->setWorldTop(height);
	gameEngine->getRenderingSystem()->setWorldBottom(-height);
	gameEngine->getRenderingSystem()->setProjection();

	for(int i = 0; i < SPRITE_COUNTING; i++)
	{
		sprites[i].setBounding(-width, width, height, -height);
	}
}

void UserEventHandler::finishAfterEvent()
{
	gameEngine->stopMainLoop();
}

void UserEventHandler::finishBeforeEvent()
{
	gameEngine->getGameWindow()->destroyWindow();
}

void UserEventHandler::resumeEvent()
{
	gameEngine->resumeGameLoop();
}

void UserEventHandler::pauseEvent()
{
	gameEngine->pauseGameLoop();
}

void UserEventHandler::beforeMainLoopEvent()
{
}