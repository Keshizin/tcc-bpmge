#include "getest.hpp"
#include <iostream>

// GameEngine *gameEngine = 0;
// unsigned long long timer = 0;
// unsigned long long numberOfFrames = 0;
// int seconds = 0;

int testInstanceGameEngine()
{
	GameEngine gameEngine;
	return 1;
}

GameEngine *singletonGameEngine = 0;

int testMainLoop()
{
	singletonGameEngine = new GameEngine();

	// GETimeHandler *timeHandler = new GETimeHandler();
	// gameEngine->setTimeHandler(timeHandler);

	TestGEEventHandler *testGEEventHandler = new TestGEEventHandler();
	singletonGameEngine->setEventHandler(testGEEventHandler);

	std::cout << "> start main loop..." << std::endl;
	singletonGameEngine->startMainLoop();
	std::cout << "> end main loop...\n" << std::endl;
	// seconds = 0;

	// delete winApiWrapper;
	// delete timeHandler;
	// delete testEventHandler;
	delete singletonGameEngine;
	return 1;
}

int testTimeHandler()
{
	singletonGameEngine = new GameEngine();

	TestGEEventHandler *testGEEventHandler = new TestGEEventHandler();
	singletonGameEngine->setEventHandler(testGEEventHandler);

	singletonGameEngine->startMainLoop();
	std::cout << "> frame time: " << singletonGameEngine->getTimeHandler()->getFrameTime() << " cycles." << std::endl;

	delete testGEEventHandler;
	delete singletonGameEngine;
	return 1;
}

void TestGEEventHandler::frameEvent()
{
	std::cout << "> frame event executed." << std::endl;
	singletonGameEngine->stopMainLoop();

	// // Exemplo de implementação de um timer
	// timer += gameEngine->getTimeHandler()->getFrameTime();
	// unsigned long long frequency = gameEngine->getApiWrapper()->getHighResolutionTimerFrequency();

	// if(timer >= frequency)
	// {
	// 	std::cout
	// 		<< "FPS: " << numberOfFrames
	// 		<< " | frame time: " << gameEngine->getTimeHandler()->getFrameTime()
	// 		<< std::endl;

	// 	numberOfFrames = 0;
	// 	timer = 0;

	// 	seconds++;

	// 	if(seconds == 5)
	// 		gameEngine->stopLoop();
	// }

	// numberOfFrames++;
}

void TestGEEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void TestGEEventHandler::mouseMotionEvent(int x, int y)
{
}

void TestGEEventHandler::keyboardEvent(unsigned char key, int state)
{
}

void TestGEEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
}

void TestGEEventHandler::resizeWindowEvent(int width, int height)
{
}

void TestGEEventHandler::finishAfterEvent()
{
	singletonGameEngine->stopMainLoop();
}

void TestGEEventHandler::finishBeforeEvent()
{
}
