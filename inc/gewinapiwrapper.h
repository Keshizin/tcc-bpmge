#ifndef GAME_ENGINE_WIN_API_WRAPPER_H
#define GAME_ENGINE_WIN_API_WRAPPER_H

#include <windows.h>
#include <geapiwrapper.h>
#include <string>

class GEWinApiWrapper : public GEApiWrapper
{
public:
	void setGlobalEventHandler(GEEventHandler *eventHandler);
	
	// CPU's stuff
	unsigned long long getHighResolutionTimerCounter();
	unsigned long long getHighResolutionTimerFrequency();

	// WINDOW SYSTEM's stuff
	int initializeWindow();
	int createWindow(int xPostion, int yPostion, int width, int height, std::string name, unsigned int style);
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
	HGLRC hRC = NULL;
};

LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif