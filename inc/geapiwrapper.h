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
	virtual int createWindow(int xPostion, int yPostion, int width, int height, std::string name) {return 1;}
	virtual int destroyWindow() {return 1;}
	virtual int showWindow() {return 1;}
	virtual unsigned long long getHighResolutionTimerCounter() { return 0; }
	virtual unsigned long long getHighResolutionTimerFrequency() { return 0; }
	virtual void handleSystemMessages() {}

	// GETTERS AND SETTERS
	void setEventHandler(GEEventHandler *eventHandler);
	GEEventHandler * getEventHandler();

protected:
	static GEEventHandler *eventHandler;
};

#endif
