#include <ge.h>
#include <gewinapiwrapper.h>
#include <iostream>

GameEngine::GameEngine(GEEventHandler *eventHandler)
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	this->apiWrapper = winApiWrapper;
	this->apiWrapper->setEventHandler(eventHandler);
	this->eventHandler = eventHandler;
	this->timeHandler = new GETimeHandler();
	this->diag = new GEDiag(this->timeHandler);
}

GameEngine::~GameEngine()
{
	delete timeHandler;
	delete apiWrapper;
	delete diag;
}

void GameEngine::startMainLoop()
{
	unsigned long long startTime = 0;
	unsigned long long endTime = 0;
	unsigned long long frameTime = 0;

	isRunning = 1;
	timeHandler->setTimer(0);
	endTime = apiWrapper->getHighResolutionTimerCounter();
	diag->start(apiWrapper->getHighResolutionTimerFrequency());

	while(isRunning)
	{
		startTime = apiWrapper->getHighResolutionTimerCounter();
		timeHandler->updateTimer();
		diag->update();
		// ********************************************************************
		// START GAME LOOP EXECUTION
		// ********************************************************************
		// apiWrapper->handleSystemMessages();

		// if(!isRunning)
		// 	break;

		eventHandler->frameEvent();

		// ********************************************************************
		// END GAME LOOP EXECUTION HERE
		// ********************************************************************
		frameTime = startTime - endTime; // adicionando possível tempo restante do frame anterior
		endTime = apiWrapper->getHighResolutionTimerCounter();
		timeHandler->setFrameTime(frameTime + (endTime - startTime));
	}
}

void GameEngine::stopMainLoop()
{
	isRunning = 0;
}

// GETTERS AND SETTERS
GETimeHandler * GameEngine::getTimeHandler()
{
	return timeHandler;
}

GEApiWrapper * GameEngine::getApiWrapper()
{
	return apiWrapper;
}

GEDiag *GameEngine::getDiag()
{
	return diag;
}