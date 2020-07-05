#include "geapiwrappertest.hpp"

#include <gewinapiwrapper.h>
#include <geeventhandler.h>

#include <iostream>

int isMouseEvent = 0;
int isMouseMotionEvent = 0;
int isKeyboardEvent = 0;
int isKeyboardSpecialEvent = 0;

class AWTestEventHandler : public GEEventHandler
{
public:
	void mouseEvent(int button, int state, int x, int y) { isMouseEvent = 1; }
	void mouseMotionEvent(int x, int y) { isMouseMotionEvent = 1; }
	void keyboardEvent(unsigned char key, int state) { isKeyboardEvent = 1; } 
	void keyboardSpecialEvent(unsigned char key, int state) { isKeyboardSpecialEvent = 1; }
};

#include <iostream>

int testInstanceApiWrapper()
{
	GEApiWrapper apiWrapper;
	GEEventHandler eventHandler;

	apiWrapper.setGlobalEventHandler(&eventHandler);
	apiWrapper.getHighResolutionTimerCounter();
	apiWrapper.getHighResolutionTimerFrequency();
	apiWrapper.registerWindow();
	apiWrapper.createWindow(0, 0, 640, 480, "API WRAPPER TEST", 0);
	apiWrapper.destroyWindow();
	apiWrapper.showWindow();
	apiWrapper.handleSystemMessages();
	apiWrapper.initializeRenderingSystem();
	apiWrapper.swapBuffers();

	return 1;
}

int testInstanceWinApiWrapper()
{
	GEWinApiWrapper winApiWrapper;
	GEEventHandler eventHandler;

	winApiWrapper.setGlobalEventHandler(&eventHandler);
	winApiWrapper.getHighResolutionTimerCounter();
	winApiWrapper.getHighResolutionTimerFrequency();
	winApiWrapper.registerWindow();
	winApiWrapper.createWindow(0, 0, 640, 480, "API WRAPPER TEST", 0);
	winApiWrapper.showWindow();
	winApiWrapper.handleSystemMessages();
	winApiWrapper.initializeRenderingSystem();
	winApiWrapper.swapBuffers();
	winApiWrapper.destroyWindow();

	return 1;
}

int testApiWrapperPoly()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	GEEventHandler eventHandler;
	winApiWrapper->setGlobalEventHandler(&eventHandler);
	GEApiWrapper *apiWrapper = winApiWrapper;
	apiWrapper->getHighResolutionTimerCounter();
	apiWrapper->getHighResolutionTimerFrequency();
	apiWrapper->registerWindow();
	apiWrapper->createWindow(0, 0, 640, 480, "API WRAPPER TEST", 0);
	apiWrapper->showWindow();
	apiWrapper->handleSystemMessages();
	apiWrapper->initializeRenderingSystem();
	apiWrapper->swapBuffers();
	apiWrapper->destroyWindow();
	delete winApiWrapper;
	return 1;
}

int testMouseEvent()
{
	GEWinApiWrapper winApiWrapper;
	AWTestEventHandler eventHandler;
	winApiWrapper.setGlobalEventHandler(&eventHandler);
	winApiWrapper.registerWindow();
	winApiWrapper.createWindow(0, 0, 640, 480, "API WRAPPER TEST", 0);
	winApiWrapper.showWindow();

	while(!(isMouseEvent && isMouseMotionEvent))
	{
		winApiWrapper.handleSystemMessages();
	}	

	winApiWrapper.destroyWindow();
	return 1;
}

int testKeyboardEvent()
{
	GEWinApiWrapper winApiWrapper;
	AWTestEventHandler eventHandler;
	winApiWrapper.setGlobalEventHandler(&eventHandler);
	winApiWrapper.registerWindow();
	winApiWrapper.createWindow(0, 0, 640, 480, "API WRAPPER TEST", 0);
	winApiWrapper.showWindow();

	while(!(isKeyboardEvent && isKeyboardSpecialEvent))
	{
		winApiWrapper.handleSystemMessages();
	}	

	winApiWrapper.destroyWindow();

	return 1;
}