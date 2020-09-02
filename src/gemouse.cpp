/*
	Game Engine Mouse
	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

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