#ifndef GAME_ENGINE_WIN_API_WRAPPER_H
#define GAME_ENGINE_WIN_API_WRAPPER_H

#include <GEApiWrapper.h>
#include <windows.h>
#include <string>

class GEWinApiWrapper : public GEApiWrapper
{
public:
	int initializeWindow();
	int initializeRenderingSystem();
	int createWindow(int xPostion, int yPostion, int width, int height, std::string name);
	int destroyWindow();
	int showWindow();

	unsigned long long getHighResolutionTimerCounter();
	unsigned long long getHighResolutionTimerFrequency();
	// void handleMessages();

	// GETTERS AND SETTERS
	void setWindowClassName(std::string windowClassName);
	std::string getWindowClassName();

private:
	static LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	std::string windowClassName;
	HWND hWindow;
};

#endif