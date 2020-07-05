#include "gerenderingsystemtest.hpp"

#include <gerenderingsystem.h>

// #include <geapiwrapper.h>
// #include <gewindowsystem.h>

// #include <iostream>

int testInstanceRenderingSystem()
{
	GERenderingSystem renderingSystem;

	if(renderingSystem.getRenderingContext() != GE_CONTEXT_2D)
		return 0;

	if(renderingSystem.getApiWrapper())
		return 0;

	if(renderingSystem.getViewportWidth())
		return 0;

	if(renderingSystem.getViewportHeight())
		return 0;

	if(renderingSystem.getWorldLeft())
		return 0;

	if(renderingSystem.getWorldRight())
		return 0;

	if(renderingSystem.getWorldTop())
		return 0;

	if(renderingSystem.getWorldBottom())
		return 0;

	if(renderingSystem.getWindowAspectCorrection())
		return 0;

	if(renderingSystem.getProjectionZNear())
		return 0;

	if(renderingSystem.getProjectionZFar())
		return 0;

	GEApiWrapper apiWrapper;

	renderingSystem.setRenderingContext(GE_CONTEXT_3D);
	renderingSystem.setApiWrapper(&apiWrapper);
	renderingSystem.setViewportWidth(640);
	renderingSystem.setViewportHeight(480);
	renderingSystem.setWorldLeft(-10);
	renderingSystem.setWorldRight(10);
	renderingSystem.setWorldTop(10);
	renderingSystem.setWorldBottom(-10);
	renderingSystem.setWindowAspectCorrection(static_cast<GLdouble>(640) / static_cast<GLdouble>(480));
	renderingSystem.setProjectionZNear(1.0);
	renderingSystem.setProjectionZFar(500.0);

	if(renderingSystem.getRenderingContext() != GE_CONTEXT_3D)
		return 0;

	if(!renderingSystem.getApiWrapper())
		return 0;

	if(renderingSystem.getViewportWidth() != 640)
		return 0;

	if(renderingSystem.getViewportHeight() != 480)
		return 0;

	if(renderingSystem.getWorldLeft() != -10)
		return 0;

	if(renderingSystem.getWorldRight() != 10)
		return 0;

	if(renderingSystem.getWorldTop() != 10)
		return 0;

	if(renderingSystem.getWorldBottom() != -10)
		return 0;

	if(renderingSystem.getWindowAspectCorrection() != static_cast<GLdouble>(640) / static_cast<GLdouble>(480))
		return 0;

	if(renderingSystem.getProjectionZNear() != 1.0)
		return 0;

	if(renderingSystem.getProjectionZFar() != 500.0)
		return 0;

	return 1;
}

int testRenderingSystem()
{
	return 1;
}

// int isRenderingTestDone = 0;
// GEApiWrapper *renderingApiWrapper;
// GEWindowSystem *testWindow;
// GERenderingSystem *renderingSystem;

// void RenderingTestEventHandler::frameEvent()
// {
// }

// void RenderingTestEventHandler::resizeWindowEvent(int width, int height)
// {
// 	// std::cout << "\t# Resize Window Event"
// 	// 	<< "\n\t\twidth: " << width
// 	// 	<< "\n\t\theight: " << height
// 	// 	<< "\n" << std::endl;

// 	// testWindow->setWidth(width);
// 	// testWindow->setHeight(width);
// 	// renderingSystem->setViewportWidth(width);
// 	// renderingSystem->setViewportHeight(width);
// 	// renderingSystem->setRenderingSystem();
// }

// void RenderingTestEventHandler::finishAfterEvent()
// {
// 	isRenderingTestDone = 1;
// }

// void RenderingTestEventHandler::finishBeforeEvent()
// {
// 	renderingApiWrapper->destroyWindow();
// }

// int testRenderingSystem()
// {
// 	// testWindow = new GEWindow();

// 	// renderingApiWrapper = testWindow->getApiWrapper();
// 	// renderingSystem = testWindow->getRenderingSystem();

// 	// RenderingTestEventHandler *renderingTestEventHandler = new RenderingTestEventHandler;
// 	// renderingApiWrapper->setEventHandler(renderingTestEventHandler);

// 	// testWindow->setName("BPM Game Engine - TEST RENDERING SYSTEM");
// 	// testWindow->setStyle(GE_WIN_COMPLETE);

// 	// if(!testWindow->createWindow())
// 	// {
// 	// 	delete renderingTestEventHandler;
// 	// 	return 0;
// 	// }

// 	// testWindow->showWindow();
// 	// renderingSystem->setBackgroundColor(GE_BKG_COLOR_BLUE);
// 	// renderingSystem->setRenderingSystem();

// 	// while(!isRenderingTestDone)
// 	// {
// 	// 	renderingApiWrapper->handleSystemMessages();

// 	// 	if(isRenderingTestDone)
// 	// 		break;

// 	// 	renderingSystem->renderFrame();
// 	// 	renderingApiWrapper->swapBuffers();
// 	// }

// 	// delete renderingTestEventHandler;
// 	// delete testWindow;
// 	return 1;
// }