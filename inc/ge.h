#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>
#include <gediag.h>

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void startMainLoop();
	void stopMainLoop();

	// GETTERS AND SETTERS
	void setEventHandler(GEEventHandler *eventHandler);

	GEApiWrapper * getApiWrapper();
	GETimeHandler * getTimeHandler();
	GEDiag *getDiag();

	void setFramesPerSecond(unsigned long long framesPerSecond);
	unsigned long long getFramesPerSecond();

private:
	int isRunning;
	GEApiWrapper *apiWrapper;
	GETimeHandler *timeHandler;
	GEEventHandler *eventHandler;
	GEDiag *diag;
};

#endif