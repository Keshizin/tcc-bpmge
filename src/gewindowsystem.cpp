/*
	Game Engine Window System Class
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

#include <iostream>
#include <gewindowsystem.h>

// ----------------------------------------------------------------------------
//  GEWindowSystem constructor and destructor
// ----------------------------------------------------------------------------
GEWindowSystem::GEWindowSystem()
{
	this->width = 640;
	this->height = 480;
	this->x = 0;
	this->y = 0;
	this->style = GE_WIN_DEFAULT;
	this->apiWrapper = 0;
}

GEWindowSystem::GEWindowSystem(GEApiWrapper *apiWrapper)
{
	this->width = 640;
	this->height = 480;
	this->x = 0;
	this->y = 0;
	this->style = GE_WIN_DEFAULT;
	this->apiWrapper = apiWrapper;
}

GEWindowSystem::~GEWindowSystem()
{
}

// ----------------------------------------------------------------------------
//  GEWindowSystem methods definition
// ----------------------------------------------------------------------------
int GEWindowSystem::createWindow()
{
	if(!apiWrapper)
	{
		std::cout << "(!) ERROR - It was not possible create a window: no apiwrapper.\n" << std::endl;
		return 0;
	}

	// (ATENÇÃO) É possível que neste ponto, apiWrapper não esteja mais
	// apontando para o objeto. Fazer essa validação!

	if(!apiWrapper->registerWindow())
		return 0;

	if(!apiWrapper->createWindow(getX(), getY(), getWidth(), getHeight(), getName(), getStyle()))
		return 0;

	return 1;
}

int GEWindowSystem::destroyWindow()
{
	if(!apiWrapper)
	{
		std::cout << "(!) ERROR - It was not possible destroy a window: no apiwrapper.\n" << std::endl;
		return 0;
	}

	// (ATENÇÃO) É possível que neste ponto, apiWrapper não esteja mais
	// apontando para o objeto. Fazer essa validação!

	if(!apiWrapper->destroyWindow())
		return 0;

	return 1;
}

int GEWindowSystem::showWindow()
{
	if(!apiWrapper)
	{
		std::cout << "(!) ERROR - It was not possible show a window: no apiwrapper.\n" << std::endl;
		return 0;
	}

	// (ATENÇÃO) É possível que neste ponto, apiWrapper não esteja mais
	// apontando para o objeto. Fazer essa validação!

	return apiWrapper->showWindow();
}

// ----------------------------------------------------------------------------
//  GEWindowSystem setters and getters
// ----------------------------------------------------------------------------

void GEWindowSystem::setName(std::string name)
{
	this->name = name;
}

void GEWindowSystem::setWidth(int width)
{
	this->width = width;
}

void GEWindowSystem::setHeight(int height)
{
	this->height = height;
}

void GEWindowSystem::setStyle(int style)
{
	this->style = style;
}

void GEWindowSystem::setX(int x)
{
	this->x = x;
}

void GEWindowSystem::setY(int y)
{
	this->y = y;
}

void GEWindowSystem::setApiWrapper(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
}

std::string GEWindowSystem::getName()
{
	return name;
}

int GEWindowSystem::getWidth()
{
	return width;
}

int GEWindowSystem::getHeight()
{
	return height;
}

int GEWindowSystem::getStyle()
{
	return style;
}

int GEWindowSystem::getX()
{
	return x;
}

int GEWindowSystem::getY()
{
	return y;
}

GEApiWrapper *GEWindowSystem::getApiWrapper()
{
	return apiWrapper;
}