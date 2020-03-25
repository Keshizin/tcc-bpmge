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
	int createWindow(int width, int height, std::string name);
	int destroyWindow();
	int showWindow();

	// Getters and Setters
	void setWindowClassName(std::string windowClassName);
	std::string getWindowClassName();

private:
	static LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	std::string windowClassName;
};

#endif