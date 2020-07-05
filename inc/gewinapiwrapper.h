/*
	Game Engine WinAPI Wrapper

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_WIN_API_WRAPPER_CLASS_H
#define GAME_ENGINE_WIN_API_WRAPPER_CLASS_H

#include <windows.h>
#include <geapiwrapper.h>

class GEWinApiWrapper : public GEApiWrapper
{
public:
	GEWinApiWrapper();
	~GEWinApiWrapper();

	void setGlobalEventHandler(GEEventHandler *eventHandler);
	
	// CPU's stuff
	unsigned long long getHighResolutionTimerCounter();
	unsigned long long getHighResolutionTimerFrequency();

	// WINDOW SYSTEM's stuff
	int registerWindow();
	int createWindow(int x, int y, int width, int height, std::string name, unsigned int style);
	int destroyWindow();
	int showWindow();

	// SO MESSAGE's stuff
	void handleSystemMessages();

	// RENDERING SYSTEM's stuff
	int initializeRenderingSystem();
	int swapBuffers();

private:
	HWND hWindow;
	HDC hDC;
	HGLRC hRC;
};

LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif