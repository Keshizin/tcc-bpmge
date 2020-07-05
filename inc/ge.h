#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>
#include <geeventhandler.h>
#include <gediag.h>
#include <gewindowsystem.h>
#include <gerenderingsystem.h>

#define GE_RUNNING 1
#define GE_STOPPED 2
#define GE_PAUSED  3

class GameEngine
{
public:
	GameEngine(GEEventHandler *eventHandler);
	~GameEngine();

	void startMainLoop();
	void stopMainLoop();
	void pauseGameLoop();
	void resumeGameLoop();

	GEApiWrapper * getApiWrapper();
	GETimeHandler * getTimeHandler();
	GEDiag *getDiag();
	GEWindowSystem *getGameWindow();
	GERenderingSystem *getRenderingSystem();

	void setEventHandler(GEEventHandler *eventHandler);

private:
	int runningStatus;

	GEApiWrapper *apiWrapper;
	GETimeHandler *timeHandler;
	GEEventHandler *eventHandler;
	GEDiag *diag;
	GEWindowSystem *gameWindow;
	GERenderingSystem *renderingSystem;
};

#endif