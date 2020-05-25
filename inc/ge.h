#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>
#include <gediag.h>

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

	// void setFramesPerSecond(unsigned long long framesPerSecond);
	// unsigned long long getFramesPerSecond();

private:
	int isRunning;
	GETimeHandler *timeHandler;
	GEApiWrapper *apiWrapper;
	GEDiag *diag;
	GEEventHandler *eventHandler;
};

#endif