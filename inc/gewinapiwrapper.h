#ifndef GAME_ENGINE_WIN_API_WRAPPER_H
#define GAME_ENGINE_WIN_API_WRAPPER_H

#include <windows.h>
#include <geapiwrapper.h>
#include <string>
// #include <gerenderingsystem.h>

class GEWinApiWrapper : public GEApiWrapper
{
public:
	unsigned long long getHighResolutionTimerCounter();
	unsigned long long getHighResolutionTimerFrequency();

	int initializeWindow();
	int createWindow(int xPostion, int yPostion, int width, int height, std::string name, unsigned int style);
	int destroyWindow();
	int showWindow();	
	void handleSystemMessages();
	// int initializeRenderingSystem(GERenderingSystem *renderingSystem);
	// int swapBuffers();

	// // GETTERS AND SETTERS
	void setWindowClassName(std::string windowClassName);
	std::string getWindowClassName();

private:
	static LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	std::string windowClassName;
	HWND hWindow;
	// HDC hDC;
	// HGLRC hRC = NULL;
};

#endif