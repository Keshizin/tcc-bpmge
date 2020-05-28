#include <iostream>

#include <ge.h>
#include <gewinapiwrapper.h>

// ----------------------------------------------------------------------------
//  CLASS METHODS DEFINITION
// ----------------------------------------------------------------------------

GameEngine::GameEngine(GEEventHandler *eventHandler)
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	winApiWrapper->setGlobalEventHandler(eventHandler);
	
	this->apiWrapper = winApiWrapper;
	this->timeHandler = new GETimeHandler();
	this->eventHandler = eventHandler;
	this->diag = new GEDiag(this->timeHandler);
	this->gameWindow = new GEWindow(winApiWrapper);
	this->renderingSystem = new GERenderingSystem(winApiWrapper);
}

GameEngine::~GameEngine()
{
	delete apiWrapper;
	delete timeHandler;
	delete diag;
	delete gameWindow;
	delete renderingSystem;
}

void GameEngine::startMainLoop()
{
	unsigned long long startTime = 0;
	unsigned long long endTime = 0;
	unsigned long long frameTime = 0;

	isRunning = 1;
	timeHandler->setInternalTimer(0);
	endTime = apiWrapper->getHighResolutionTimerCounter();
	diag->start(apiWrapper->getHighResolutionTimerFrequency());

	if(!eventHandler)
	{
		// substituir por um log
		std::cout << "(!) ERROR - User events not configured!" << std::endl;
		exit(1);
	}

	// Inicializando o sistema de renderização
	if(!renderingSystem->initialize())
	{
		exit(1);
	}

	renderingSystem->setRenderingSystem();

	while(isRunning)
	{
		startTime = apiWrapper->getHighResolutionTimerCounter();
		timeHandler->updateInternalTimer();
		diag->update();

		// ********************************************************************
		// START GAME LOOP EXECUTION
		// ********************************************************************
		apiWrapper->handleSystemMessages();

		// if(!isRunning)
		// 	break;

		eventHandler->frameEvent();
		renderingSystem->renderFrame();

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
	isRunning = 0;
}

// GETTERS AND SETTERS
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

GEWindow *GameEngine::getGameWindow()
{
	return gameWindow;
}

void GameEngine::setEventHandler(GEEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
}
