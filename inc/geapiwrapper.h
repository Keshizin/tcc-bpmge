#ifndef GAME_ENGINE_API_WRAPPER_H
#define GAME_ENGINE_API_WRAPPER_H

#include <string>
#include <geeventhandler.h>

class GEApiWrapper
{
public:
	virtual void setGlobalEventHandler(GEEventHandler *eventHandler) {}
	
	// CPU's stuff
	virtual unsigned long long getHighResolutionTimerCounter() { return 0; }
	virtual unsigned long long getHighResolutionTimerFrequency() { return 0; }

	// WINDOW SYSTEM's stuff
	virtual int initializeWindow() { return 1; }
	virtual int createWindow(int xPostion, int yPostion, int width, int height, std::string name, unsigned int style) {return 1;}
	virtual int destroyWindow() {return 1;}
	virtual int showWindow() {return 1;}

	// SO MESSAGE's stuff
	virtual void handleSystemMessages() {}

	// OPENGL REDENRING's stuff
	virtual int initializeRenderingSystem() {return 1;}
	virtual int swapBuffers() {return 1;}
};

#endif
