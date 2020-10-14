/*
	Game Engine Core
	This file is part of the BPM Game Engine.

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

#include <iostream>
#include <ge.h>
#include <gewinapiwrapper.h>

// ----------------------------------------------------------------------------
//  Game Engine constructor and destructor
// ----------------------------------------------------------------------------
GameEngine::GameEngine(GEEventHandler *eventHandler)
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	winApiWrapper->setGlobalEventHandler(eventHandler);

	this->eventHandler = eventHandler;
	this->apiWrapper = winApiWrapper;	
	this->gameWindow = new GEWindowSystem(this->apiWrapper);
	this->timeHandler = new GETimeHandler();
	this->diag = new GEDiag(this->timeHandler);
	this->renderingSystem = new GERenderingSystem(winApiWrapper);
}

GameEngine::~GameEngine()
{
	delete apiWrapper;
	apiWrapper = 0;

	delete gameWindow;
	gameWindow = 0;

	delete timeHandler;
	timeHandler = 0;

	delete diag;
	diag = 0;

	delete renderingSystem;
	renderingSystem = 0;
}

// ----------------------------------------------------------------------------
//  Game Engine methods definition
// ----------------------------------------------------------------------------
void GameEngine::startMainLoop()
{
	unsigned long long startTime = 0;
	unsigned long long endTime = 0;
	unsigned long long frameTime = 0;

	runningStatus = GE_RUNNING;
	timeHandler->setInternalTimer(0);
	timeHandler->setPerfomanceFrequency(apiWrapper->getHighResolutionTimerFrequency());
	endTime = apiWrapper->getHighResolutionTimerCounter();
	diag->start(1000);

	if(!eventHandler)
	{
		// substituir por um log
		std::cout << "(!) ERROR - User events not configured!" << std::endl;
		exit(1);
	}

	eventHandler->beforeMainLoopEvent();

	while(runningStatus != GE_STOPPED)
	{
		startTime = apiWrapper->getHighResolutionTimerCounter();
		timeHandler->updateInternalTimer();
		diag->update();

		// Message Pump!
		apiWrapper->handleSystemMessages();

		// ********************************************************************
		// START GAME LOOP EXECUTION HERE!
		// ********************************************************************
		// std::cout << "FPS: " << diag->getFramesPerSecond() << " | " << timeHandler->getFrameTime() << std::endl;;

		// CONTROLE DO GAME LOOP ATRAVÉS DE UM PRÓPRIO TIMER (GAME TIME)

		if(runningStatus == GE_RUNNING)
		{
			eventHandler->frameEvent();
			renderingSystem->renderFrame();
		}

		// ********************************************************************
		// END GAME LOOP EXECUTION HERE
		// ********************************************************************

		// Adicionar possível tempo restante do frame anterior para depois
		// adicionar o tempo de duração do quadro
		frameTime = startTime - endTime;
		endTime = apiWrapper->getHighResolutionTimerCounter();
		frameTime += (endTime - startTime);
		
		// FRAME RATE GOVERNING
		while(frameTime <= timeHandler->getFrameTimeLimit())
		{
			startTime = endTime;
			endTime = apiWrapper->getHighResolutionTimerCounter();
			frameTime += (endTime - startTime);
		}

		timeHandler->setFrameTime(frameTime);
	}
}

void GameEngine::stopMainLoop()
{
	runningStatus = GE_STOPPED;
}

void GameEngine::pauseGameLoop()
{
	runningStatus = GE_PAUSED;
}

void GameEngine::resumeGameLoop()
{
	runningStatus = GE_RUNNING;
}

void GameEngine::setFrameRate(int framePerSecond)
{
	if (!framePerSecond)
	{
		timeHandler->setFrameTimeLimit(0);
	}
	else
	{
		timeHandler->setFrameTimeLimit(apiWrapper->getHighResolutionTimerFrequency() / framePerSecond);
	}
}

// ----------------------------------------------------------------------------
//  Game Engine getters and setters
// ----------------------------------------------------------------------------
GEApiWrapper *GameEngine::getApiWrapper()
{
	return apiWrapper;
}

GEWindowSystem *GameEngine::getGameWindow()
{
	return gameWindow;
}

GERenderingSystem *GameEngine::getRenderingSystem()
{
	return renderingSystem;
}

GETimeHandler *GameEngine::getTimeHandler()
{
	return timeHandler;
}

GEDiag *GameEngine::getDiag()
{
	return diag;
}

void GameEngine::setEventHandler(GEEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
	this->apiWrapper->setGlobalEventHandler(eventHandler);
}