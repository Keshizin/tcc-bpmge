#include <iostream>

#include <ge.h>
#include <gewinapiwrapper.h>

// ----------------------------------------------------------------------------
//  GameEngine CLASS CONSTRUCTORS DEFINITION
// ----------------------------------------------------------------------------

GameEngine::GameEngine(GEEventHandler *eventHandler)
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	winApiWrapper->setGlobalEventHandler(eventHandler);
	
	this->apiWrapper = winApiWrapper;
	this->timeHandler = new GETimeHandler();
	this->eventHandler = eventHandler;
	this->diag = new GEDiag(this->timeHandler);
	this->gameWindow = new GEWindowSystem(winApiWrapper);
	// this->renderingSystem = new GERenderingSystem(winApiWrapper);
}

GameEngine::~GameEngine()
{
	delete apiWrapper;
	delete timeHandler;
	delete diag;
	delete gameWindow;
	delete renderingSystem;
}

// ----------------------------------------------------------------------------
//  GameEngine CLASS METHODS DEFINITION
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

	// renderingSystem->setProjection();

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
			// renderingSystem->renderFrame();
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
//  GameEngine CLASS GETTERS AND SETTERS METHODS DEFINITION
// ----------------------------------------------------------------------------

GEApiWrapper * GameEngine::getApiWrapper()
{
	return apiWrapper;
}

GETimeHandler * GameEngine::getTimeHandler()
{
	return timeHandler;
}

GEDiag *GameEngine::getDiag()
{
	return diag;
}

GEWindowSystem *GameEngine::getGameWindow()
{
	return gameWindow;
}

GERenderingSystem *GameEngine::getRenderingSystem()
{
	return renderingSystem;
}

void GameEngine::setEventHandler(GEEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
}