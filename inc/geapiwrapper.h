/*
	Game Engine API Wrapper
	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
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
