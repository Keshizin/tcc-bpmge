#include "geevthandlertest.hpp"
#include <iostream>

void TestEventHandler::frameEvent()
{
	std::cout << "\t# Frame Event\n" << std::endl;
}

void TestEventHandler::mouseEvent(int button, int state, int x, int y)
{
	std::cout << "\t# Mouse Event"
		<< "\n\t\tbutton: " << button
		<< "\n\t\t state: " << state
		<< "\n\t\t     x: " << x
		<< "\n\t\t     y: " << y
		<< "\n" << std::endl;
}

void TestEventHandler::mouseMotionEvent(int x, int y)
{
	std::cout << "\t# Mouse Motion Event"
		<< "\n\t\tx: " << x
		<< "\n\t\ty: " << y
		<< "\n" << std::endl;
}

void TestEventHandler::keyboardEvent(unsigned char key, int state)
{
	std::cout << "\t# Keyboard Event"
		<< "\n\t\tkey: " << key
		<< "\n\t\tstate: " << state
		<< "\n" << std::endl;
}

void TestEventHandler::keyboardSpecialEvent(unsigned char key, int state)
{
	std::cout << "\t# Keyboard Special Event"
		<< "\n\t\tkey: " << key
		<< "\n\t\tstate: " << state
		<< "\n" << std::endl;
}

void TestEventHandler::resizeWindowEvent(int width, int height)
{
	std::cout << "\t# Resize Window Event"
		<< "\n\t\twidth: " << width
		<< "\n\t\theight: " << height
		<< "\n" << std::endl;
}

void TestEventHandler::finishAfterEvent()
{
	std::cout << "\t# Finish After Event" << "\n" << std::endl;
}

void TestEventHandler::finishBeforeEvent()
{
	std::cout << "\t# Finish Before Event" << "\n" << std::endl;
}

int eventHandlerTest()
{
	TestEventHandler *testEventHandler = new TestEventHandler();

	testEventHandler->frameEvent();
	testEventHandler->mouseEvent(0, 0, 1920, 1080);
	testEventHandler->mouseMotionEvent(1, 1);
	testEventHandler->keyboardEvent('Q', 1);
	testEventHandler->keyboardSpecialEvent(125, 1);
	testEventHandler->resizeWindowEvent(1920, 1080);
	testEventHandler->finishAfterEvent();
	testEventHandler->finishBeforeEvent();

	return 1;
}