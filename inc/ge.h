#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>

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

private:
	int isRunning;
	GEApiWrapper *apiWrapper;
	GETimeHandler *timeHandler;
	GEEventHandler *eventHandler;
};

#endif