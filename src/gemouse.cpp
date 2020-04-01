#include <gemouse.h>

void GEMouse::setXPosition(int xPosition)
{
	this->xPosition = xPosition;
}

void GEMouse::setYPosition(int yPosition)
{
	this->yPosition = yPosition;
}

void GEMouse::setLButton(int lButton)
{
	this->buttons[0] = lButton;
}

void GEMouse::setMButton(int mButton)
{
	this->buttons[1] = mButton;
}

void GEMouse::setRButton(int rButton)
{
	this->buttons[2] = rButton;
}

void GEMouse::setLState(int lState)
{
	this->states[0] = lState;
}

void GEMouse::setMState(int mState)
{
	this->states[1] = mState;
}

void GEMouse::setRState(int rState)
{
	this->states[2] = rState;
}


int GEMouse::getXPosition()
{
	return xPosition;
}

int GEMouse::getYPosition()
{
	return yPosition;
}

int GEMouse::getLButton()
{
	return buttons[0];
}

int GEMouse::getMButton()
{
	return buttons[1];
}

int GEMouse::getRButton()
{
	return buttons[2];
}

int GEMouse::getLState()
{
	return states[0];
}

int GEMouse::getMState()
{
	return states[1];
}

int GEMouse::getRState()
{
	return states[2];
}