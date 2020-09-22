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

#ifndef SPRITE_2D_SIZE
#define SPRITE_2D_SIZE 16
#endif

VERTEX sprite2D_vertices[] = {
	{-SPRITE_2D_SIZE,  SPRITE_2D_SIZE, 0.0},
	{ SPRITE_2D_SIZE,  SPRITE_2D_SIZE, 0.0},
	{-SPRITE_2D_SIZE, -SPRITE_2D_SIZE, 0.0},
	{ SPRITE_2D_SIZE, -SPRITE_2D_SIZE, 0.0}
};

FACE sprite2D_faces[] = {
	{3, {0, 1, 2}},
	{3, {1, 3, 2}}
};

MODEL sprite2D_model = {
	sprite2D_vertices, sprite2D_faces, 2
};

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
	gameEngine->getGameWindow()->setName("BPM Game Engine - DEMO");
	gameEngine->getGameWindow()->setWidth(GAME_WINDOW_WIDTH);
	gameEngine->getGameWindow()->setHeight(GAME_WINDOW_HEIGHT);
	gameEngine->getGameWindow()->setX(0);
	gameEngine->getGameWindow()->setY(0);
	gameEngine->getGameWindow()->setStyle(GE_WIN_COMPLETE);
	gameEngine->getGameWindow()->createWindow();

	// SETTING UP RENDERING ENGINE
	gameEngine->getRenderingSystem()->setRenderingContext(GE_CONTEXT_2D);
	gameEngine->getRenderingSystem()->setViewport(0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);

	gameEngine->getRenderingSystem()->setWorldLeft(WORLD_LEFT);
	gameEngine->getRenderingSystem()->setWorldRight(WORLD_RIGHT);
	gameEngine->getRenderingSystem()->setWorldTop(WORLD_TOP);
	gameEngine->getRenderingSystem()->setWorldBottom(WORLD_BOTTOM);
	
	gameEngine->getRenderingSystem()->setWindowAspectCorrectionState(true);
	gameEngine->getRenderingSystem()->initialize();

	gameEngine->getRenderingSystem()->setProjection();
	gameEngine->getGameWindow()->showWindow();

	// STARTING GAME LOOP
	gameEngine->setFrameRate(120);
	gameEngine->startMainLoop();

	// RELEASE GAME ENGINE
	delete gameEngine;

	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}

// GLOBAL METHODS DEFINITION

void UserEventHandler::frameEvent()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	// glColor3f(1.0f, 0.0f, 0.0f);
	// drawGEModel(&sprite2D_model);
}

void UserEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void UserEventHandler::mouseMotionEvent(int x, int y)
{
}

void UserEventHandler::keyboardEvent(unsigned char key, int state)
{
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
	// gameEngine->getRenderingSystem()->setWorldLeft(-width);
	// gameEngine->getRenderingSystem()->setWorldRight(width);
	// gameEngine->getRenderingSystem()->setWorldTop(height);
	// gameEngine->getRenderingSystem()->setWorldBottom(-height);
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
}

void UserEventHandler::pauseEvent()
{
}

void UserEventHandler::beforeMainLoopEvent()
{
}