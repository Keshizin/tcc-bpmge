#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>
#include <geeventhandler.h>
#include <gediag.h>
#include <gewindow.h>
#include <gerenderingsystem.h>

class GameEngine
{
public:
	GameEngine(GEEventHandler *eventHandler);
	~GameEngine();

	void startMainLoop();
	void stopMainLoop();

	// GETTERS AND SETTERS
	GEApiWrapper * getApiWrapper();
	GETimeHandler * getTimeHandler();
	GEDiag *getDiag();
	GEWindow *getGameWindow();

	void setEventHandler(GEEventHandler *eventHandler);

private:
	int isRunning;
	GEApiWrapper *apiWrapper;
	GETimeHandler *timeHandler;
	GEEventHandler *eventHandler;
	GEDiag *diag;
	GEWindow *gameWindow;
	GERenderingSystem *renderingSystem;
};

#endif