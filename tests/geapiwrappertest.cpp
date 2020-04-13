#include "geapiwrappertest.hpp"

#include <gewinapiwrapper.h>
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


	if(!apiWrapper->destroyWindow())
	{
		delete winApiWrapper;
		return 0;
	}

	GEEventHandler *eventHandler = new GEEventHandler();
	winApiWrapper->setEventHandler(eventHandler);
	winApiWrapper->handleSystemMessages();

	// if(!apiWrapper->initializeRenderingSystem())
	// {
	// 	delete winApiWrapper;
	// 	return 0;
	// }
	
	// if(!apiWrapper->showWindow())
	// {
	// 	delete winApiWrapper;
	// 	return 0;
	// }


	// if(!apiWrapper->getHighResolutionTimerCounter())
	// {
	// 	delete winApiWrapper;
	// 	return 0;
	// }

	// if(!apiWrapper->getHighResolutionTimerFrequency())
	// {
	// 	delete apiWrapper;
	// 	return 0;
	// }

	delete eventHandler;
	delete winApiWrapper;
	return 1;
}