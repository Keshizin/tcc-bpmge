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
#include <diblib.h>

#define GAME_SPLASH_WINDOW_WIDTH 640
#define GAME_SPLASH_WINDOW_HEIGHT 480

#define GAME_WINDOW_WIDTH 640
#define GAME_WINDOW_HEIGHT 480
#define WORLD_LEFT   -1
#define WORLD_RIGHT   640
#define WORLD_TOP     480
#define WORLD_BOTTOM -1

// ----------------------------------------------------------------------------
//  GLOBAL ESCOPE
// ----------------------------------------------------------------------------

class SplashEventHandler : public GEEventHandler
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

class GameEventHandler : public GEEventHandler
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

GameEngine *gameEngine = 0;

DIB splashImage;
GESprite splashSprite;
GETimer *timer = 0;

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
	SplashEventHandler eventHandler;
	gameEngine = new GameEngine(&eventHandler);

	// SETTING UP WINDOW GAME
	gameEngine->getGameWindow()->setName("Game Engine - BOUNDING COLLISION TEST!");
	gameEngine->getGameWindow()->setWidth(GAME_SPLASH_WINDOW_WIDTH);
	gameEngine->getGameWindow()->setHeight(GAME_SPLASH_WINDOW_HEIGHT);
	gameEngine->getGameWindow()->setX(960 - (GAME_SPLASH_WINDOW_WIDTH / 2));
	gameEngine->getGameWindow()->setY(540 - (GAME_SPLASH_WINDOW_HEIGHT / 2));
	gameEngine->getGameWindow()->setStyle(GE_WIN_SPLASH);
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
	// delete timer;

	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}

// ----------------------------------------------------------------------------
//  SPLASH EVENT DECLARATION
// ----------------------------------------------------------------------------
void SplashEventHandler::frameEvent()
{
	glClear(GL_COLOR_BUFFER_BIT);
	splashSprite.draw();
}

void SplashEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void SplashEventHandler::mouseMotionEvent(int x, int y)
{
}

void SplashEventHandler::keyboardEvent(unsigned char key, int state)
{
	if(key == '1' && state)
	{
		timer->start();
	}

	if(key == 27)
	{
		gameEngine->stopMainLoop();
	}
}

void SplashEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
}

void SplashEventHandler::resizeWindowEvent(int width, int height)
{
	gameEngine->getRenderingSystem()->setViewport(0, 0, width, height);
	gameEngine->getRenderingSystem()->setWorldLeft(-width);
	gameEngine->getRenderingSystem()->setWorldRight(width);
	gameEngine->getRenderingSystem()->setWorldTop(height);
	gameEngine->getRenderingSystem()->setWorldBottom(-height);
	gameEngine->getRenderingSystem()->setProjection();
}

void SplashEventHandler::finishAfterEvent()
{
	gameEngine->stopMainLoop();
}

void SplashEventHandler::finishBeforeEvent()
{
	gameEngine->getGameWindow()->destroyWindow();
}

void SplashEventHandler::resumeEvent()
{
	gameEngine->resumeGameLoop();
}

void SplashEventHandler::pauseEvent()
{
	gameEngine->pauseGameLoop();
}

void SplashEventHandler::beforeMainLoopEvent()
{
	glClearColorHex(0xF7, 0xC2, 0x17, 1);
	timer->setTimer(1000);

	splashImage.loadFile("assets/logo.bmp", 1);
	
	splashSprite.setPosition((GAME_SPLASH_WINDOW_WIDTH - splashImage.getWidth()) / 2, (GAME_SPLASH_WINDOW_HEIGHT - splashImage.getHeight()) / 2);
	splashSprite.setSpeed(0, 0);
	splashSprite.setSize(splashImage.getWidth(), splashImage.getHeight());

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, splashImage.getWidth(), splashImage.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, splashImage.getColorIndex());
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	splashSprite.setTextureID(textureID);
	
	splashImage.release();
}

// ----------------------------------------------------------------------------
//  GAME EVENT DECLARATION
// ----------------------------------------------------------------------------
void GameEventHandler::frameEvent()
{
}

void GameEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void GameEventHandler::mouseMotionEvent(int x, int y)
{
}

void GameEventHandler::keyboardEvent(unsigned char key, int state)
{
}

void GameEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
}

void GameEventHandler::resizeWindowEvent(int width, int height)
{
}

void GameEventHandler::finishAfterEvent()
{
}

void GameEventHandler::finishBeforeEvent()
{
}

void GameEventHandler::resumeEvent()
{
}

void GameEventHandler::pauseEvent()
{
}

void GameEventHandler::beforeMainLoopEvent()
{
}
