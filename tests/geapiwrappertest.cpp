#include "geapiwrappertest.hpp"

#include <gewinapiwrapper.h>
#include <gewindow.h>

#include <iostream>

int testWinApiWrapper()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();

	winApiWrapper->setWindowClassName("WINAPICLASS");

	if(winApiWrapper->getWindowClassName().compare("WINAPICLASS"))
	{
		std::cout << "> Wrong window class name: " << winApiWrapper->getWindowClassName() << std::endl;
		return 0;
	}

	GEApiWrapper *apiWrapper = winApiWrapper;

	if(!apiWrapper->initializeWindow())
	{
		delete winApiWrapper;
		return 0;
	}


	if(!apiWrapper->createWindow(0, 0, 100, 100, "api-test-class", 1))
	{
		delete winApiWrapper;
		return 0;
	}

	GERenderingSystem * renderingSystem = new GERenderingSystem();

	if(!apiWrapper->initializeRenderingSystem(renderingSystem))
	{
		delete renderingSystem;
		delete winApiWrapper;
		return 0;
	}

	if(!apiWrapper->destroyWindow())
	{
		delete renderingSystem;
		delete winApiWrapper;
		return 0;
	}

	GEEventHandler *eventHandler = new GEEventHandler();
	winApiWrapper->setEventHandler(eventHandler);
	winApiWrapper->handleSystemMessages();
	
	if(!apiWrapper->showWindow())
	{
		delete winApiWrapper;
		return 0;
	}

	if(!apiWrapper->getHighResolutionTimerCounter())
	{
		delete winApiWrapper;
		return 0;
	}

	if(!apiWrapper->getHighResolutionTimerFrequency())
	{
		delete apiWrapper;
		return 0;
	}

	delete renderingSystem;
	delete eventHandler;
	delete winApiWrapper;
	return 1;
}

int isADone = 0;
int activeMouseEvents = 0;
int activeKeyboardsEvents = 0;

GEApiWrapper *apiWrapperTestPtr;

void ApiWrapperTestEventHandler::mouseEvent(int button, int state, int x, int y)
{
	if(activeMouseEvents)
	{
		std::cout << "\t# Mouse Event"
			<< "\n\t\tbutton: " << button
			<< "\n\t\t state: " << state
			<< "\n\t\t     x: " << x
			<< "\n\t\t     y: " << y
			<< "\n" << std::endl;
	}
}

void ApiWrapperTestEventHandler::mouseMotionEvent(int x, int y)
{
	if(activeMouseEvents)
	{
		std::cout << "\t# Mouse Motion Event"
			<< "\n\t\tx: " << x
			<< "\n\t\ty: " << y
			<< "\n" << std::endl;
	}
}

void ApiWrapperTestEventHandler::keyboardEvent(unsigned char key, int state)
{
	if(activeKeyboardsEvents)
	{
		std::cout << "\t# Keyboard Event"
			<< "\n\t\tkey: " << key
			<< "\n\t\tstate: " << state
			<< "\n" << std::endl;
	}
}

void ApiWrapperTestEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
	if(activeKeyboardsEvents)
	{
		std::cout << "\t# Keyboard Special Event"
			<< "\n\t\tkey: " << key
			<< "\n\t\tstate: " << state
			<< "\n" << std::endl;
	}
}

void ApiWrapperTestEventHandler::finishAfterEvent()
{
	isADone = 1;
}

void ApiWrapperTestEventHandler::finishBeforeEvent()
{
	apiWrapperTestPtr->destroyWindow();
}

int testWinMouseEvent()
{
	activeMouseEvents = 1;

	GEWindow testWindow;

	ApiWrapperTestEventHandler *apiWrapperTestEventHandler = new ApiWrapperTestEventHandler();
	testWindow.getApiWrapper()->setEventHandler(apiWrapperTestEventHandler);

	testWindow.setName("BPM Game Engine | TEST MOUSE EVENTS");

	if(!testWindow.createWindow())
	{
		delete apiWrapperTestEventHandler;
		return 0;
	}

	testWindow.showWindow();
	apiWrapperTestPtr = testWindow.getApiWrapper();

	while(!isADone)
	{
		apiWrapperTestPtr->handleSystemMessages();
	}

	activeMouseEvents = 0;
	delete apiWrapperTestEventHandler;
	return 1;
}

int testWinKeyboardEvent()
{
	activeKeyboardsEvents = 1;
	GEWindow testWindow;

	ApiWrapperTestEventHandler *apiWrapperTestEventHandler = new ApiWrapperTestEventHandler();
	testWindow.getApiWrapper()->setEventHandler(apiWrapperTestEventHandler);

	testWindow.setName("BPM Game Engine | TEST KEYBOARD EVENTS");

	if(!testWindow.createWindow())
	{
		delete apiWrapperTestEventHandler;
		return 0;
	}

	testWindow.showWindow();
	apiWrapperTestPtr = testWindow.getApiWrapper();

	isADone = 0;

	while(!isADone)
	{
		apiWrapperTestPtr->handleSystemMessages();
	}

	activeKeyboardsEvents = 0;
	delete apiWrapperTestEventHandler;
	return 1;
}