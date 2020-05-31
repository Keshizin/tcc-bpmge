#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>
#include <geeventhandler.h>
#include <gediag.h>
#include <gewindow.h>
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
	GEWindow *getGameWindow();
	GERenderingSystem *getRenderingSystem();

	void setEventHandler(GEEventHandler *eventHandler);

private:
	int runningStatus;

	GEApiWrapper *apiWrapper;
	GETimeHandler *timeHandler;
	GEEventHandler *eventHandler;
	GEDiag *diag;
	GEWindow *gameWindow;
	GERenderingSystem *renderingSystem;
};

#endif