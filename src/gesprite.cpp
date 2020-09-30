/*
	Game Engine Sprite
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

#include <gesprite.h>
#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>

GESprite::GESprite()
{
	this->model = 0;
	this->visible = true;
}

GESprite::GESprite(MODEL *model)
{
	this->model = model;
	this->visible = true;
}

void GESprite::update(double frameTime)
{
	for (int i = 0; i < 9; i++)
		color[i] = (rand() % 255) / 255.0;

	this->position_x += static_cast<double>(speed_x) * frameTime;
	this->position_y += static_cast<double>(speed_y) * frameTime;

	// CHECK COLLISION WITH YOUR BOUNDARY
	if(this->boundsAction == BA_STOP)
	{
		if(position_x + width > bounding.right)
		{
			position_x = bounding.right - width;
		}
		else if(position_x < bounding.left)
		{
			position_x = bounding.left;
		}

		if(position_y + height > bounding.top)
		{
			position_y = bounding.top - height;
		}
		else if(position_y < bounding.bottom)
		{
			position_y = bounding.bottom;
		}
	}
	else if(this->boundsAction == BA_WRAP)
	{
		if(position_x + width > bounding.right)
		{
			position_x = bounding.left;
		}
		else if(position_x < bounding.left)
		{
			position_x = bounding.right - width;
		}

		if(position_y + height > bounding.top)
		{
			position_y = bounding.bottom;
		}
		else if(position_y < bounding.bottom)
		{
			position_y = bounding.top - height;
		}
	}
	if(this->boundsAction == BA_BOUNCE)
	{
		if(position_x + width > bounding.right)
		{
			position_x = bounding.right - width;
			speed_x = -speed_x;
		}
		else if(position_x < bounding.left)
		{
			position_x = bounding.left;
			speed_x = -speed_x;
		}

		if(position_y + height > bounding.top)
		{
			position_y = bounding.top - height;
			speed_y = -speed_y;
		}
		else if(position_y < bounding.bottom)
		{
			position_y = bounding.bottom;
			speed_y = -speed_y;
		}
	}
	if(this->boundsAction == BA_DIE)
	{

	}
}

void GESprite::draw()
{
	if(visible)
	{
		// if (model)
		// {
		// 	drawGEModel(model);
		// }

		glBegin(GL_LINE_LOOP);
		glColor3fv(&color[0]);
		glVertex2i(position_x, position_y + height);
		glVertex2i(position_x + width, position_y + height);
		glVertex2i(position_x, position_y);
		glVertex2i(position_x + width, position_y + height);
		glVertex2i(position_x + width, position_y);
		glVertex2i(position_x, position_y);
		glEnd();
	}
}

void GESprite::setPosition(int x, int y)
{
	this->position_x = x;
	this->position_y = y;
}

void GESprite::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void GESprite::setSpeed(int speed_x, int speed_y)
{
	this->speed_x = speed_x;
	this->speed_y = speed_y;
}

void GESprite::setPositionX(int position_x)
{
	this->position_x = position_x;
}

int GESprite::getPositionX()
{
	return this->position_x;
}

void GESprite::setPositionY(int position_y)
{
	this->position_y = position_y;
}

int GESprite::getPositionY()
{
	return this->position_y;
}
	
void GESprite::setWidth(int width)
{
	this->width = width;
}

int GESprite::getWidth()
{
	return this->width;
}

void GESprite::setHeight(int height)
{
	this->height = height;
}

int GESprite::getHeight()
{
	return this->height;
}

void GESprite::setSpeedX(int speed_x)
{
	this->speed_x = speed_x;
}

int GESprite::getSpeedX()
{
	return this->speed_x;
}

void GESprite::setSpeedY(int speed_y)
{
	this->speed_y = speed_y;
}

int GESprite::getSpeedY()
{
	return this->speed_y;
}

void GESprite::setZOrder(int zOrder)
{
	this->zOrder = zOrder;
}

int GESprite::getZOrder()
{
	return zOrder;
}

void GESprite::setVisible(bool visible)
{
	this->visible = visible;
}

bool GESprite::getVisible()
{
	return visible;
}

void GESprite::setBounding(double left, double right, double top, double bottom)
{
	this->bounding.left = left;
	this->bounding.right = right;
	this->bounding.top = top;
	this->bounding.bottom = bottom;
}

void GESprite::setBoundsAction(BOUNDSACTION boundsAction)
{
	this->boundsAction = boundsAction;
}

BOUNDSACTION GESprite::getBoundsAction()
{
	return this->boundsAction;
}