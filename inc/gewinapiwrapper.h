#ifndef GAME_ENGINE_WIN_API_WRAPPER_H
#define GAME_ENGINE_WIN_API_WRAPPER_H

#include <geapiwrapper.h>
#include <gerenderingsystem.h>

#include <windows.h>
#include <string>

class GEWinApiWrapper : public GEApiWrapper
{
public:
	int initializeWindow();
	int createWindow(int xPostion, int yPostion, int width, int height, std::string name, unsigned int style);
	int destroyWindow();
	void handleSystemMessages();
	int showWindow();	
	int initializeRenderingSystem(GERenderingSystem *renderingSystem);
	int swapBuffers();
	unsigned long long getHighResolutionTimerCounter();
	unsigned long long getHighResolutionTimerFrequency();

	// GETTERS AND SETTERS
	void setWindowClassName(std::string windowClassName);
	std::string getWindowClassName();

private:
	static LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	std::string windowClassName;
	HWND hWindow;
	HDC hDC;
	HGLRC hRC = NULL;
};

#endif