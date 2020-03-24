#ifndef GAME_ENGINE_API_WRAPPER_H
#define GAME_ENGINE_API_WRAPPER_H

#include <geevthandler.h>
#include <string>

class GEApiWrapper
{
public:
	// Common methods for all OS and Rendering APIs that must redefined.
	virtual int initializeWindow() {return 1;}
	virtual int initializeRenderingSystem() {return 1;}
	virtual int createWindow(int width, int height, std::string name) {return 1;}
	virtual int destroyWindow() {return 1;}
	virtual int showWindow() {return 1;}

	// Getters and Setters
	void setEventHandler(GEEventHandler *eventHandler);
	GEEventHandler * getEventHandler();

protected:
	static GEEventHandler *eventHandler;
};

#endif