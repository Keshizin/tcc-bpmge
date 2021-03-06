/*
	Game Engine Rendering System
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

#ifndef GAME_ENGINE_RENDERING_SYSTEM_H
#define GAME_ENGINE_RENDERING_SYSTEM_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <geapiwrapper.h>
#include <gemodel.h>
// #include <windows.h>

// #define GE_BKG_COLOR_WHITE 1
// #define GE_BKG_COLOR_BLACK 2
// #define GE_BKG_COLOR_RED   3
// #define GE_BKG_COLOR_GREEN 4
// #define GE_BKG_COLOR_BLUE  5
// #define GE_BKG_COLOR_UBUNTU_PURPLE 6
// #define GE_BKG_COLOR_PINK 0xFFB2AD

// ----------------------------------------------------------------------------
//  Rendering System Context (2D or 3D)
// ----------------------------------------------------------------------------
#define GE_CONTEXT_2D 0x01
#define GE_CONTEXT_3D 0x02

// ----------------------------------------------------------------------------
//  HELP METHODS
// ----------------------------------------------------------------------------
void glClearColorHex(int r, int g, int b, int a);

// ----------------------------------------------------------------------------
//  Rendering System class
// ----------------------------------------------------------------------------
class GERenderingSystem
{
public:
	GERenderingSystem();
	GERenderingSystem(GEApiWrapper *apiWrapper);

	// ----------------------------------------------------------------------------
	//  Public Methods
	// ----------------------------------------------------------------------------
	int initialize();
	void setViewport(int x, int y);
	void setViewport(int x, int y, int width, int height);
	void setProjection();
	void renderFrame();
	void drawWorldAxis();

	// ----------------------------------------------------------------------------
	//  Getters and Setters
	// ----------------------------------------------------------------------------
	void setRenderingContext(int renderingContext);
	void setApiWrapper(GEApiWrapper *apiWrapper);
	void setViewportWidth(int viewportWidth);
	void setViewportHeight(int viewportHeight);
	void setWorldLeft(GLdouble worldLeft);
	void setWorldRight(GLdouble worldRight);
	void setWorldTop(GLdouble worldTop);
	void setWorldBottom(GLdouble worldBottom);
	void setWorld(GLdouble left, GLdouble right, GLdouble top, GLdouble bottom);
	void setWindowAspectCorrection(GLdouble windowAspectCorrection);
	void setProjectionZNear(GLdouble projectionZNear);
	void setProjectionZFar(GLdouble projectionZFar);
	void setProjectionFOVY(GLdouble fovy);
	void setWindowAspectCorrectionState(int state);
	void setWorldAxisState(int state);

	int getRenderingContext();
	GEApiWrapper *getApiWrapper();
	int getViewportWidth();
	int getViewportHeight();
	GLdouble getWorldLeft();
	GLdouble getWorldRight();
	GLdouble getWorldTop();
	GLdouble getWorldBottom();
	GLdouble getWindowAspectCorrection();
	GLdouble getProjectionZNear();
	GLdouble getProjectionZFar();
	GLdouble getProjectionFOVY();
	int getWindowAspectCorrectionState();
	int getWorldAxisState();

private:
	int renderingContext;
	GEApiWrapper *apiWrapper;

	int viewportWidth;
	int viewportHeight;

	GLdouble worldLeft;
	GLdouble worldRight;
	GLdouble worldTop;
	GLdouble worldBottom;

	GLdouble windowAspectCorrection;
	GLdouble projectionZNear;
	GLdouble projectionZFar;
	GLdouble projectionFOVY;

	int windowAspectCorrectionState;
	int worldAxisState;
	
};

#endif