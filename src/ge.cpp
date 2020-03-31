#include <ge.h>

GameEngine::GameEngine(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
}

#include <iostream>

void GameEngine::mainLoop()
{
	unsigned long long startTime;
	unsigned long long endTime;
	unsigned long long frameTime;

	isRunning = 1;

	endTime = apiWrapper->getHighResolutionTimerCounter();

	while(isRunning)
	{
		startTime = apiWrapper->getHighResolutionTimerCounter();
		// ********************************************************************
		// START GAME LOOP EXECUTION
		// ********************************************************************

		eventHandler->frameEvent();

		// ********************************************************************
		// END GAME LOOP EXECUTION HERE
		// ********************************************************************
		frameTime = startTime - endTime; // adicionando possível tempo restante do frame anterior
		endTime = apiWrapper->getHighResolutionTimerCounter();
		frameTime += endTime - startTime;
		timeHandler->setFrameTime(frameTime);
	}
}

void GameEngine::stopLoop()
{
	isRunning = 0;
}

// GETTERS AND SETTERS
void GameEngine::setEventHandler(GEEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
}

void GameEngine::setTimeHandler(GETimeHandler *timeHandler)
{
	this->timeHandler = timeHandler;
}

GETimeHandler * GameEngine::getTimeHandler()
{
	return timeHandler;
}

GEApiWrapper * GameEngine::getApiWrapper()
{
	return apiWrapper;
}