#include "geapiwrappertest.hpp"

#include <gewinapiwrapper.h>
#include <iostream>

int testApiWrapper()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();

	winApiWrapper->setWindowClassName("APITESTCLASS");
	GEApiWrapper *apiWrapper = winApiWrapper;

	if(!apiWrapper->initializeWindow())
	{
		delete winApiWrapper;
		return 0;
	}

	if(!apiWrapper->initializeRenderingSystem())
	{
		delete winApiWrapper;
		return 0;
	}

	if(!apiWrapper->createWindow(0, 0, 100, 100, "api-test-class"))
	{
		delete winApiWrapper;
		return 0;
	}

	if(!apiWrapper->destroyWindow())
	{
		delete winApiWrapper;
		return 0;
	}

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

	delete winApiWrapper;
	return 1;
}