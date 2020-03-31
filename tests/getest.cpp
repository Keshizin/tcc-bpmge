#include "getest.hpp"

#include <GEWinApiWrapper.h>
#include <iostream>

GameEngine *gameEngine = 0;
unsigned long long timer = 0;
unsigned long long numberOfFrames = 0;
int seconds = 0;

void TestEventHandler::frameEvent()
{
	// Exemplo de implementação de um timer
	timer += gameEngine->getTimeHandler()->getFrameTime();
	unsigned long long frequency = gameEngine->getApiWrapper()->getHighResolutionTimerFrequency();

	if(timer >= frequency)
	{
		std::cout << "FPS: " << numberOfFrames << std::endl;
		numberOfFrames = 0;
		timer = 0;

		seconds++;

		if(seconds == 5)
			gameEngine->stopLoop();
	}

	numberOfFrames++;
}

int testInstanceGameEngine()
{
	GEApiWrapper *apiWrapper = new GEApiWrapper();
	GameEngine gameEngine(apiWrapper);
	delete apiWrapper;
	return 1;
}

int testMainLoop()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	GEApiWrapper *apiWrapper = winApiWrapper;
	
	gameEngine = new GameEngine(apiWrapper);

	GETimeHandler *timeHandler = new GETimeHandler();
	gameEngine->setTimeHandler(timeHandler);

	TestEventHandler *testEventHandler = new TestEventHandler();
	gameEngine->setEventHandler(testEventHandler);

	std::cout << "> start main loop (for 5 seconds)..." << std::endl;
	gameEngine->mainLoop();
	std::cout << "> end main loop...\n" << std::endl;
	seconds = 0;

	delete winApiWrapper;
	delete timeHandler;
	delete testEventHandler;
	delete gameEngine;
	return 1;
}