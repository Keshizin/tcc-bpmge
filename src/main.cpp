#include <windows.h>
#include <iostream>

#include <ge.h>
// #include <gewindow.h>
// #include <gerenderingsystem.h>

class UserEventHandler : public GEEventHandler
{
	void frameEvent();
// 	void mouseEvent(int button, int state, int x, int y);
// 	void mouseMotionEvent(int x, int y);
// 	void keyboardEvent(unsigned char key, int state);
// 	void keyboardSpecialEvent(unsigned char key, int state);
// 	void resizeWindowEvent(int width, int height);
// 	void finishAfterEvent();
// 	void finishBeforeEvent();
};

GameEngine *singletonGameEngineDemo = 0;
GETimer *timer;
// GERenderingSystem *mainRenderingSystem = 0;

// int splashMode = 1;
// int _seconds = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::cout << "HELLO BPM Game Engine!" << std::endl;

	UserEventHandler userEventHandler;
	singletonGameEngineDemo = new GameEngine(&userEventHandler);

	singletonGameEngineDemo->getGameWindow()->setName("BPM Game Engine");
	singletonGameEngineDemo->getGameWindow()->setWidth(640);
	singletonGameEngineDemo->getGameWindow()->setHeight(480);
	singletonGameEngineDemo->getGameWindow()->setXPosition(960 - 320);
	singletonGameEngineDemo->getGameWindow()->setYPosition(540 - 240);
	singletonGameEngineDemo->getGameWindow()->setStyle(GE_WIN_DEFAULT);

	// mainRenderingSystem = windowDemo->getRenderingSystem();

	if(!singletonGameEngineDemo->getGameWindow()->createWindow())
	{
		delete singletonGameEngineDemo;
		return 0;
	}

	singletonGameEngineDemo->getGameWindow()->showWindow();

	// mainRenderingSystem->setBackgroundColor(GE_BKG_COLOR_UBUNTU_PURPLE);
	// mainRenderingSystem->setRenderingSystem();
	// windowDemo->showWindow();

	timer = new GETimer(singletonGameEngineDemo->getTimeHandler());
	timer->setTimer(singletonGameEngineDemo->getApiWrapper()->getHighResolutionTimerFrequency() * 10);
	timer->start();

	singletonGameEngineDemo->startMainLoop();

	singletonGameEngineDemo->getGameWindow()->destroyWindow();

	// splashMode = 0;

	// windowDemo->setWidth(1600);
	// windowDemo->setHeight(800);
	// windowDemo->setXPosition(960 - 800);
	// windowDemo->setYPosition(540 - 400);
	// windowDemo->setStyle(GE_WIN_DEFAULT);

	// if(!windowDemo->createWindow())
	// {
	// 	delete _timer;
	// 	delete demoEventHandler;
	// 	delete windowDemo;
	// 	delete singletonGameEngineDemo;
	// 	return 0;
	// }

	// mainRenderingSystem->setBackgroundColor(GE_BKG_COLOR_WHITE);
	// mainRenderingSystem->setRenderingSystem();
	// windowDemo->showWindow();

	// _timer->setTimer(singletonGameEngineDemo->getApiWrapper()->getHighResolutionTimerFrequency());
	// _timer->start();

	// singletonGameEngineDemo->startMainLoop();
	// singletonGameEngineDemo->startMainLoop();


	std::cout << "BYE BPM Game Engine!" << std::endl;

	singletonGameEngineDemo->getDiag()->print();

	// delete windowDemo;
	delete timer;
	delete singletonGameEngineDemo;
	return 1;
}

void UserEventHandler::frameEvent()
{
	if(timer->isDone())
	{
		singletonGameEngineDemo->stopMainLoop();
	}
	// 	if(splashMode)
	// 	{
	// 		singletonGameEngineDemo->stopMainLoop();
	// 	}
	// 	else
	// 	{
			
	// 		_timer->start();

	// 		if(_seconds == 10)
	// 		{
	// 			windowDemo->destroyWindow();
	// 			singletonGameEngineDemo->stopMainLoop();
	// 		}

	// 		_seconds++;
	// 	}
		
	// 	return;

	// mainRenderingSystem->renderFrame();
	// windowDemo->getApiWrapper()->swapBuffers();
}

// void DemoEventHandler::mouseEvent(int button, int state, int x, int y)
// {
// 	std::cout << "> mouse event | button: " << button << " | state: " << state << " | x: " << x << " | y: " << y << std::endl;
// }

// void DemoEventHandler::mouseMotionEvent(int x, int y)
// {
// 	// std::cout << "> mouse motion event | x: " << x << " | y: " << y << std::endl;
// }

// void DemoEventHandler::keyboardEvent(unsigned char key, int state)
// {
// 	std::cout << "> keyboard event | key: " << key << " | state: " << state << std::endl;
// }

// void DemoEventHandler::keyboardSpecialEvent(unsigned char key, int state)
// {
// 	std::cout << "> special keyboard event | key: " << key << " | state: " << state << std::endl;
// }

// void DemoEventHandler::resizeWindowEvent(int width, int height)
// {
// 	std::cout << "> resize window event | width: " << width << " | height: " << height << std::endl;
// 	// windowDemo->setWidth(width);
// 	// windowDemo->setHeight(height);
// 	// mainRenderingSystem->setViewportWidth(width);
// 	// mainRenderingSystem->setViewportHeight(height);
// 	// mainRenderingSystem->setRenderingSystem();
// }

// void DemoEventHandler::finishAfterEvent()
// {
// 	singletonGameEngineDemo->stopMainLoop();
// }

// void DemoEventHandler::finishBeforeEvent()
// {
// 	windowDemo->destroyWindow();
// }