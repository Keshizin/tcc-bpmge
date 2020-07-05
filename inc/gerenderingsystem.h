/*
	Game Engine Rendering System

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_RENDERING_SYSTEM_H
#define GAME_ENGINE_RENDERING_SYSTEM_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <geapiwrapper.h>

// #define GE_BKG_COLOR_WHITE 1
// #define GE_BKG_COLOR_BLACK 2
// #define GE_BKG_COLOR_RED   3
// #define GE_BKG_COLOR_GREEN 4
// #define GE_BKG_COLOR_BLUE  5
// #define GE_BKG_COLOR_UBUNTU_PURPLE 6

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

	int initialize();
	void setViewport(int x, int y);
	void setViewport(int x, int y, int width, int height);
	void setProjection();
	void renderFrame();

	void setRenderingContext(int renderingContext);
	void setApiWrapper(GEApiWrapper *apiWrapper);
	void setViewportWidth(int viewportWidth);
	void setViewportHeight(int viewportHeight);
	void setWorldLeft(GLdouble worldLeft);
	void setWorldRight(GLdouble worldRight);
	void setWorldTop(GLdouble worldTop);
	void setWorldBottom(GLdouble worldBottom);
	void setWindowAspectCorrection(GLdouble windowAspectCorrection);
	void setProjectionZNear(GLdouble projectionZNear);
	void setProjectionZFar(GLdouble projectionZFar);
	void setProjectionFOVY(GLdouble fovy);
	void setWindowAspectCorrectionState(int state);

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
};

#endif