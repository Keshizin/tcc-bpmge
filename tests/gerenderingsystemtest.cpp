#include "gerenderingsystemtest.hpp"

#include <gerenderingsystem.h>
#include <geapiwrapper.h>
#include <gewindow.h>

#include <iostream>

int isRenderingTestDone = 0;
GEApiWrapper *renderingApiWrapper;
GEWindow *testWindow;
GERenderingSystem *renderingSystem;

void RenderingTestEventHandler::frameEvent()
{
}

void RenderingTestEventHandler::resizeWindowEvent(int width, int height)
{
	std::cout << "\t# Resize Window Event"
		<< "\n\t\twidth: " << width
		<< "\n\t\theight: " << height
		<< "\n" << std::endl;

	testWindow->setWidth(width);
	testWindow->setHeight(width);
	renderingSystem->setViewportWidth(width);
	renderingSystem->setViewportHeight(width);
	renderingSystem->setRenderingSystem();
}

void RenderingTestEventHandler::finishAfterEvent()
{
	isRenderingTestDone = 1;
}

void RenderingTestEventHandler::finishBeforeEvent()
{
	renderingApiWrapper->destroyWindow();
}

int testRenderingSystem()
{
	testWindow = new GEWindow();

	renderingApiWrapper = testWindow->getApiWrapper();
	renderingSystem = testWindow->getRenderingSystem();

	RenderingTestEventHandler *renderingTestEventHandler = new RenderingTestEventHandler;
	renderingApiWrapper->setEventHandler(renderingTestEventHandler);

	testWindow->setName("BPM Game Engine - TEST RENDERING SYSTEM");
	testWindow->setStyle(GE_WIN_COMPLETE);

	if(!testWindow->createWindow())
	{
		delete renderingTestEventHandler;
		return 0;
	}

	testWindow->showWindow();
	renderingSystem->setBackgroundColor(GE_BKG_COLOR_BLUE);
	renderingSystem->setRenderingSystem();

	while(!isRenderingTestDone)
	{
		renderingApiWrapper->handleSystemMessages();

		if(isRenderingTestDone)
			break;

		renderingSystem->renderFrame();
		renderingApiWrapper->swapBuffers();
	}

	delete renderingTestEventHandler;
	delete testWindow;
	return 1;
}