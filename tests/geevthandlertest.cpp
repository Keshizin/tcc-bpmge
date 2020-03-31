#include "geevthandlertest.hpp"
#include <iostream>

void UserEventHandler::frameEvent()
	{
		std::cout << "\t# Frame Event\n" << std::endl;
	}

void UserEventHandler::mouseEvent(int button, int state, int x, int y)
{
	std::cout << "\t# Mouse Event"
		<< "\n\t\tbutton: " << button
		<< "\n\t\t state: " << state
		<< "\n\t\t     x: " << x
		<< "\n\t\t     y: " << y
		<< "\n" << std::endl;
}

void UserEventHandler::mouseMotionEvent(int x, int y)
{
	std::cout << "\t# Mouse Motion Event"
		<< "\n\t\tx: " << x
		<< "\n\t\ty: " << y
		<< "\n" << std::endl;
}

void UserEventHandler::resizeWindow(int width, int height)
{
	std::cout << "\t# Resize Window Event"
		<< "\n\t\twidth: " << width
		<< "\n\t\theight: " << height
		<< "\n" << std::endl;
}

int eventHandlerTest()
{
	UserEventHandler *userEventHandler = new UserEventHandler();
	userEventHandler->frameEvent();
	userEventHandler->mouseEvent(0, 0, 1920, 1080);
	userEventHandler->mouseMotionEvent(1, 1);
	userEventHandler->resizeWindow(1920, 1080);
	return 1;
}