#include <ge.h>
#include <gewinapiwrapper.h>
#include <iostream>

GameEngine::GameEngine()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	this->apiWrapper = winApiWrapper;

	GETimeHandler *timeHandler = new GETimeHandler();
	this->timeHandler = timeHandler;
}

GameEngine::~GameEngine()
{
	delete timeHandler;
	delete apiWrapper;
}

void GameEngine::startMainLoop()
{
	unsigned long long startTime = 0;
	unsigned long long endTime = 0;
	unsigned long long frameTime = 0;

	isRunning = 1;

	endTime = apiWrapper->getHighResolutionTimerCounter();

	while(isRunning)
	{
		startTime = apiWrapper->getHighResolutionTimerCounter();
		// ********************************************************************
		// START GAME LOOP EXECUTION
		// ********************************************************************
		apiWrapper->handleSystemMessages();
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
void GameEngine::setEventHandler(GEEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
	this->apiWrapper->setEventHandler(eventHandler);
}

GETimeHandler * GameEngine::getTimeHandler()
{
	return timeHandler;
}

GEApiWrapper * GameEngine::getApiWrapper()
{
	return apiWrapper;
}