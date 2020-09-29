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

#ifndef GAME_ENGINE_SPRITE_H
#define GAME_ENGINE_SPRITE_H

#include <geobject.h>
#include <gemodel.h>

enum BOUNDSACTION { BA_STOP = 0, BA_WRAP, BA_BOUNCE, BA_DIE };

class GESprite : public GEObject
{
public:
	// constructors
	GESprite();
	GESprite(MODEL *model);

	// public methods
	void update(double frameTime);
	void draw();

	void setPosition(int x, int y);
	void setSize(int width, int height);
	void setSpeed(int speed_x, int speed_y);

	// Getters and Setters
	void setPositionX(int position_x);
	int getPositionX();

	void setPositionY(int position_y);
	int getPositionY();

	void setWidth(int width);
	int getWidth();

	void setHeight(int height);
	int getHeight();

	void setSpeedX(int speed_x);
	int getSpeedX();

	void setSpeedY(int speed_y);
	int getSpeedY();

	void setZOrder(int zOrder);
	int getZOrder();

	void setVisible(bool visible);
	bool getVisible();

	void setBounding(double left, double right, double top, double bottom);

	void setBoundsAction(BOUNDSACTION boundsAction);
	BOUNDSACTION getBoundsAction();

private:
	int position_x;
	int position_y;
	int width;
	int height;
	int speed_x;
	int speed_y;
	int zOrder;
	bool visible;
	float color[9]; // ela deverá ser removida

	MODEL *model;
	GERECT bounding;
	BOUNDSACTION boundsAction;
	// RETÂNGULO DE COLISÃO
	// RETÂNGULO DE BOUNDING
	// AÇÕES DE BOUNDING
	// AÇÕES DE COLISÃO
	// BITMAP IMAGEM
	// TRANSPARÊNCIA
};

#endif