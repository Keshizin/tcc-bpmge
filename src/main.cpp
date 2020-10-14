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

GameEngine *gameEngine = 0;
GETimer *timer = 0;

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

	timer = new GETimer(gameEngine->getTimeHandler());

	// STARTING GAME LOOP
	gameEngine->setFrameRate(0);
	gameEngine->startMainLoop();

	// RELEASE GAME ENGINE
	delete gameEngine;
	delete timer;

	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}

// GLOBAL METHODS DEFINITION

void UserEventHandler::frameEvent()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if(timer->isDone())
	{
		std::cout << "timer is done" << std::endl;

		GLfloat red = (rand() % 256) / 255.0;
		GLfloat green = (rand() % 256) / 255.0;
		GLfloat blue = (rand() % 256) / 255.0;

		glClearColor(red, green, blue, 1.0f);

		timer->start();
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
	if(key == '1' && state)
	{
		std::cout << "start timer" << std::endl;
		timer->start();
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0);
	timer->setTimer(3000);
}