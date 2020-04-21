#include "getest.hpp"
#include <iostream>
#include <getimer.h>

int testInstanceGameEngine()
{
	GameEngine gameEngine;
	return 1;
}

GameEngine *singletonGameEngine = 0;

int testMainLoop()
{
	singletonGameEngine = new GameEngine();

	TestGEEventHandler *testGEEventHandler = new TestGEEventHandler();
	singletonGameEngine->setEventHandler(testGEEventHandler);

	std::cout << "> start main loop..." << std::endl;
	singletonGameEngine->startMainLoop();
	std::cout << "> end main loop...\n" << std::endl;

	delete testGEEventHandler;
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

int hasTimer = 0;
int seconds = 0;

GETimer *timer;

int testTimer()
{
	singletonGameEngine = new GameEngine();

	TestGEEventHandler *testGEEventHandler = new TestGEEventHandler();
	singletonGameEngine->setEventHandler(testGEEventHandler);

	hasTimer = 1;

	timer = new GETimer(singletonGameEngine->getTimeHandler());
	timer->setTimer(10000000);
	timer->start();
	singletonGameEngine->startMainLoop();
	hasTimer = 0;

	delete timer;
	delete testGEEventHandler;
	delete singletonGameEngine;
	return 1;
}

void TestGEEventHandler::frameEvent()
{
	if(hasTimer)
	{
		if(timer->isDone())
		{
			std::cout << ".";
			seconds++;
			timer->start();
			
			if(seconds == 10)
				singletonGameEngine->stopMainLoop();
		}
	}
	else
	{
		singletonGameEngine->stopMainLoop();
	}
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
