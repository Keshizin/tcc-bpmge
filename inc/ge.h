#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <geapiwrapper.h>
#include <getimehandler.h>

class GameEngine
{
public:
	GameEngine(GEApiWrapper *apiWrapper);
	void mainLoop();
	void stopLoop();

	// GETTERS AND SETTERS
	void setEventHandler(GEEventHandler *eventHandler);
	void setTimeHandler(GETimeHandler *timeHandler);

	GETimeHandler * getTimeHandler();
	GEApiWrapper * getApiWrapper();

private:
	int isRunning;
	GEApiWrapper *apiWrapper;
	GETimeHandler *timeHandler;
	GEEventHandler *eventHandler;
};

#endif