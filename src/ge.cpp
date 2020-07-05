/*
	Game Engine Core

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
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
	endTime = apiWrapper->getHighResolutionTimerCounter();
	diag->start(apiWrapper->getHighResolutionTimerFrequency());

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

		// ********************************************************************
		// START GAME LOOP EXECUTION
		// ********************************************************************
		apiWrapper->handleSystemMessages();

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
		timeHandler->setFrameTime(frameTime + (endTime - startTime));
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

// ----------------------------------------------------------------------------
//  Game Engine getters and setters
// ----------------------------------------------------------------------------
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