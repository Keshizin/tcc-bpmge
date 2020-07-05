#include "geevthandlertest.hpp"
#include <iostream>

void TestEventHandler::frameEvent()
{
	// std::cout << "\ttest event handler - frame event" << std::endl;
}

void TestEventHandler::mouseEvent(int button, int state, int x, int y)
{
	// std::cout << "\ttest event handler - mouse event"
	// 	<< "\n\t\tbutton: " << button
	// 	<< "\n\t\t state: " << state
	// 	<< "\n\t\t     x: " << x
	// 	<< "\n\t\t     y: " << y
	// 	<< std::endl;
}

void TestEventHandler::mouseMotionEvent(int x, int y)
{
	// std::cout << "\ttest event handler - mouse motion event"
	// 	<< "\n\t\t     x: " << x
	// 	<< "\n\t\t     y: " << y
	// 	<< std::endl;
}

void TestEventHandler::keyboardEvent(unsigned char key, int state)
{
	// std::cout << "\ttest event handler - keyboard event"
	// 	<< "\n\t\t key: " << key
	// 	<< "\n\t\t state: " << state
	// 	<< std::endl;
}

void TestEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
	// std::cout << "\ttest event handler - keyboard special event"
	// 	<< "\n\t\t key: " << key
	// 	<< "\n\t\t state: " << state
	// 	<< std::endl;
}

void TestEventHandler::resizeWindowEvent(int width, int height)
{
	// std::cout << "\ttest event handler - resize window event"
	// 	<< "\n\t\t width: " << width
	// 	<< "\n\t\t height: " << height
	// 	<< std::endl;
}

void TestEventHandler::finishAfterEvent()
{
	// std::cout << "\ttest event handler - finish after event" << std::endl;
}

void TestEventHandler::finishBeforeEvent()
{
	// std::cout << "\ttest event handler - finish before event" << std::endl;
}

void TestEventHandler::resumeEvent()
{
	// std::cout << "\ttest event handler - resume event" << std::endl;
}

void TestEventHandler::pauseEvent()
{
	// std::cout << "\ttest event handler - pause event" << std::endl;
}

int testUserEventHandler()
{
	TestEventHandler testEventHandler;
	GEEventHandler *eventHandler = &testEventHandler;

	eventHandler->frameEvent();
	eventHandler->mouseEvent(0, 0, 1920, 1080);
	eventHandler->mouseMotionEvent(1, 1);
	eventHandler->keyboardEvent('Q', 1);
	eventHandler->keyboardSpecialEvent(125, 1);
	eventHandler->resizeWindowEvent(1920, 1080);
	eventHandler->finishAfterEvent();
	eventHandler->finishBeforeEvent();
	eventHandler->resumeEvent();
	eventHandler->pauseEvent();
	return 1;
}