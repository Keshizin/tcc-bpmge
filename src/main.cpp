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

#include <ge.h>

// ----------------------------------------------------------------------------
//  GLOBAL ESCOPE
// ----------------------------------------------------------------------------
#define GAME_WINDOW_WIDTH 640
#define GAME_WINDOW_HEIGHT 480

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
	std::cout << "> HELLO BPM Game Engine" << std::endl;

	#ifdef GEDEBUG
	std::cout << "(!) DEBUG MODE ACTIVATED" << std::endl;
	#endif

	// START UP GAME ENGINE
	UserEventHandler eventHandler;
	gameEngine = new GameEngine(&eventHandler);

	// SETTING UP WINDOW GAME
	gameEngine->getGameWindow()->setWidth(640);
	gameEngine->getGameWindow()->setHeight(480);
	gameEngine->getGameWindow()->setX(0);
	gameEngine->getGameWindow()->setY(0);
	gameEngine->getGameWindow()->setStyle(GE_WIN_COMPLETE);
	gameEngine->getGameWindow()->createWindow();

	// SETTING UP RENDERING ENGINE
	// gameEngine.getRenderingSystem()->setRenderingContext(GE_CONTEXT_2D);
	// gameEngine.getRenderingSystem()->setViewportWidth(GAME_WINDOW_WIDTH);
	// gameEngine.getRenderingSystem()->setViewportHeight(GAME_WINDOW_HEIGHT);
	// gameEngine.getRenderingSystem()->setWorldLeft(-(GAME_WINDOW_WIDTH / 2));
	// gameEngine.getRenderingSystem()->setWorldRight(GAME_WINDOW_WIDTH / 2);
	// gameEngine.getRenderingSystem()->setWorldTop(GAME_WINDOW_HEIGHT / 2);
	// gameEngine.getRenderingSystem()->setWorldBottom(-(GAME_WINDOW_HEIGHT / 2));
	// gameEngine.getRenderingSystem()->setWindowAspectCorrectionState(0);
	// gameEngine.getRenderingSystem()->initialize();

	gameEngine->getGameWindow()->showWindow();

	// STARTING GAME LOOP
	std::cout << "@DEBUG | frame time limit: " << (gameEngine->getApiWrapper()->getHighResolutionTimerFrequency() / 60) << std::endl;

	gameEngine->getTimeHandler()->setFrameTimeLimit(gameEngine->getApiWrapper()->getHighResolutionTimerFrequency() / 60);
	gameEngine->startMainLoop();

	// RELEASE GAME ENGINE
	delete gameEngine;

	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}

// GLOBAL METHODS DEFINITION

void UserEventHandler::frameEvent()
{
}

void UserEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void UserEventHandler::mouseMotionEvent(int x, int y)
{
}

void UserEventHandler::keyboardEvent(unsigned char key, int state)
{
}

void UserEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
}

void UserEventHandler::resizeWindowEvent(int width, int height)
{
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
}

void UserEventHandler::pauseEvent()
{
}

void UserEventHandler::beforeMainLoopEvent()
{
}