#ifndef GAME_ENGINE_API_WRAPPER_H
#define GAME_ENGINE_API_WRAPPER_H

#include <string>
#include <geeventhandler.h>
// #include <gerenderingsystem.h>

class GEApiWrapper
{
public:
	virtual unsigned long long getHighResolutionTimerCounter() { return 0; }
	virtual unsigned long long getHighResolutionTimerFrequency() { return 0; }

	virtual int initializeWindow() { return 1; }
	virtual int createWindow(int xPostion, int yPostion, int width, int height, std::string name, unsigned int style) {return 1;}
	virtual int destroyWindow() {return 1;}
	virtual int showWindow() {return 1;}
	virtual void handleSystemMessages() {}
	// virtual int initializeRenderingSystem(GERenderingSystem *renderingSystem) {return 1;}
	// virtual int swapBuffers() {return 1;}

	// Getters and Setters
	void setEventHandler(GEEventHandler *eventHandler);
	// GEEventHandler * getEventHandler();

protected:
	static GEEventHandler *eventHandler;
};

#endif
