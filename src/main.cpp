#include <windows.h>
#include <iostream>

#include <gewindow.h>
#include <geeventhandler.h>
#include <geapiwrapper.h>
#include <gerenderingsystem.h>

class DemoEventHandler : public GEEventHandler
{
	void frameEvent();
	void mouseEvent(int button, int state, int x, int y);
	void mouseMotionEvent(int x, int y);
	void keyboardEvent(unsigned char key, int state);
	void keyboardSpecialEvent(unsigned char key, int state);
	void resizeWindowEvent(int width, int height);
	void finishAfterEvent();
	void finishBeforeEvent();
};

GEWindow *windowDemo = 0;
GEApiWrapper *apiWrapper = 0;
GERenderingSystem *mainRenderingSystem = 0;

int isFinish = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::cout << "HELLO BPM Game Engine!" << std::endl;

	windowDemo = new GEWindow();
	windowDemo->setName("BPM Game Engine - DEMO 1 - SPLASH");
	windowDemo->setWidth(800);
	windowDemo->setHeight(600);
	windowDemo->setXPosition(960 - 400);
	windowDemo->setYPosition(540 - 300);
	windowDemo->setStyle(GE_WIN_SPLASH);

	apiWrapper = windowDemo->getApiWrapper();
	mainRenderingSystem = windowDemo->getRenderingSystem();

	DemoEventHandler *demoEventHandler = new DemoEventHandler();
	apiWrapper->setEventHandler(demoEventHandler);

	if(!windowDemo->createWindow())
	{
		delete demoEventHandler;
		delete windowDemo;
		return 0;
	}

	mainRenderingSystem->setBackgroundColor(GE_BKG_COLOR_BLUE);
	mainRenderingSystem->setRenderingSystem();
	windowDemo->showWindow();

	while(!isFinish)
	{
		apiWrapper->handleSystemMessages();

		if(isFinish)
			break;

		mainRenderingSystem->renderFrame();
		apiWrapper->swapBuffers();
	}

	windowDemo->setName("BPM Game Engine - DEMO 1 - DEFAULT");
	windowDemo->setWidth(1600);
	windowDemo->setHeight(800);
	windowDemo->setXPosition(960 - 800);
	windowDemo->setYPosition(540 - 400);
	windowDemo->setStyle(GE_WIN_DEFAULT);

	if(!windowDemo->createWindow())
	{
		delete demoEventHandler;
		delete windowDemo;
		return 0;
	}

	mainRenderingSystem->setBackgroundColor(GE_BKG_COLOR_BLACK);
	mainRenderingSystem->setRenderingSystem();
	windowDemo->showWindow();

	isFinish = 0;

	while(!isFinish)
	{
		apiWrapper->handleSystemMessages();

		if(isFinish)
			break;

		mainRenderingSystem->renderFrame();
		apiWrapper->swapBuffers();
	}

	windowDemo->setName("BPM Game Engine - DEMO 1 - COMPLETE");
	windowDemo->setWidth(640);
	windowDemo->setHeight(480);
	windowDemo->setXPosition(960 - 320);
	windowDemo->setYPosition(540 - 240);
	windowDemo->setStyle(GE_WIN_COMPLETE);

	if(!windowDemo->createWindow())
	{
		delete demoEventHandler;
		delete windowDemo;
		return 0;
	}

	mainRenderingSystem->setBackgroundColor(GE_BKG_COLOR_WHITE);
	mainRenderingSystem->setRenderingSystem();
	windowDemo->showWindow();

	isFinish = 0;

	while(!isFinish)
	{
		apiWrapper->handleSystemMessages();

		if(isFinish)
			break;

		mainRenderingSystem->renderFrame();
		apiWrapper->swapBuffers();
	}

	std::cout << "BYE BPM Game Engine!" << std::endl;

	delete demoEventHandler;
	delete windowDemo;

	return 1;
}

void DemoEventHandler::frameEvent()
{
}

void DemoEventHandler::mouseEvent(int button, int state, int x, int y)
{
	std::cout << "> mouse event | button: " << button << " | state: " << state << " | x: " << x << " | y: " << y << std::endl;
}

void DemoEventHandler::mouseMotionEvent(int x, int y)
{
	// std::cout << "> mouse motion event | x: " << x << " | y: " << y << std::endl;
}

void DemoEventHandler::keyboardEvent(unsigned char key, int state)
{
	std::cout << "> keyboard event | key: " << key << " | state: " << state << std::endl;
}

void DemoEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
	std::cout << "> special keyboard event | key: " << key << " | state: " << state << std::endl;
}

void DemoEventHandler::resizeWindowEvent(int width, int height)
{
	std::cout << "> resize window event | width: " << width << " | height: " << height << std::endl;
	windowDemo->setWidth(width);
	windowDemo->setHeight(height);
	mainRenderingSystem->setViewportWidth(width);
	mainRenderingSystem->setViewportHeight(height);
	mainRenderingSystem->setRenderingSystem();
}

void DemoEventHandler::finishAfterEvent()
{
	isFinish = 1;
}

void DemoEventHandler::finishBeforeEvent()
{
	windowDemo->destroyWindow();
}