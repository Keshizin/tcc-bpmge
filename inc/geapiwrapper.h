/*
	Game Engine API Wrapper

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_API_WRAPPER_CLASS_H
#define GAME_ENGINE_API_WRAPPER_CLASS_H

#include <string>
#include <geeventhandler.h>

class GEApiWrapper
{
public:
	virtual ~GEApiWrapper() {};

	virtual void setGlobalEventHandler(GEEventHandler *eventHandler) {}
	
	// CPU's stuff
	virtual unsigned long long getHighResolutionTimerCounter() { return 0; }
	virtual unsigned long long getHighResolutionTimerFrequency() { return 0; }

	// Window System's stuff
	virtual int registerWindow() { return 1; }
	virtual int createWindow(int x, int y, int width, int height, std::string name, unsigned int style) { return 1; }
	virtual int destroyWindow() { return 1; }
	virtual int showWindow() { return 1; }

	// SO MESSAGE's stuff
	virtual void handleSystemMessages() {}

	// OPENGL REDENRING's stuff
	virtual int initializeRenderingSystem() { return 1; }
	virtual int swapBuffers() { return 1; }
};

#endif
