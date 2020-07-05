/*
	Game Engine Rendering System

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#include <iostream>
#include <gerenderingsystem.h>

// #include <GL/gl.h>
// #include <GL/glu.h>

// ----------------------------------------------------------------------------
//  HELP METHODS
// ----------------------------------------------------------------------------
void glClearColorHex(int r, int g, int b, int a)
{
	glClearColor(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

// ----------------------------------------------------------------------------
//  GERenderingSystem constructor and destructor
// ----------------------------------------------------------------------------
GERenderingSystem::GERenderingSystem()
{
	this->renderingContext = GE_CONTEXT_2D;
	this->apiWrapper = 0;
	this->viewportWidth = 0;
	this->viewportHeight = 0;
	this->worldLeft = 0;
	this->worldRight = 0;
	this->worldTop = 0;
	this->worldBottom = 0;
	this->windowAspectCorrection = 0;
	this->projectionZNear = 0;
	this->projectionZFar = 0;
	this->windowAspectCorrectionState = 0;
}

GERenderingSystem::GERenderingSystem(GEApiWrapper *apiWrapper)
{
	this->renderingContext = GE_CONTEXT_2D;
	this->apiWrapper = apiWrapper;
	this->viewportWidth = 0;
	this->viewportHeight = 0;
	this->worldLeft = 0;
	this->worldRight = 0;
	this->worldTop = 0;
	this->worldBottom = 0;
	this->windowAspectCorrection = 0;
	this->projectionZNear = 0;
	this->projectionZFar = 0;
	this->windowAspectCorrectionState = 0;
}

// ----------------------------------------------------------------------------
//  GERenderingSystem methods definition
// ----------------------------------------------------------------------------
int GERenderingSystem::initialize()
{
	if(!apiWrapper)
	{
		std::cout << "(!) ERROR - It was not possible initialize rendering system: no apiwrapper.\n" << std::endl;
		return 0;
	}

	// (ATENÇÃO) É possível que neste ponto, apiWrapper não esteja mais
	// apontando para o objeto. Fazer essa validação!

	if(!apiWrapper->initializeRenderingSystem())
		return 0;

	return 1;
}

void GERenderingSystem::setViewport(int x, int y)
{
	glViewport(x, y, viewportWidth, viewportHeight);
}

void GERenderingSystem::setViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);

	this->viewportWidth = width;
	this->viewportHeight = height;
}

void GERenderingSystem::setProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(renderingContext == GE_CONTEXT_2D)
	{
		GLdouble left = worldLeft;
		GLdouble right = worldRight;
		GLdouble bottom = worldBottom;
		GLdouble top = worldTop;

		if(windowAspectCorrectionState)
		{
			if(viewportWidth <= viewportHeight)
			{
				windowAspectCorrection = static_cast<GLdouble>(viewportHeight) / static_cast<double>(viewportWidth);
				bottom *= windowAspectCorrection;
				top *= windowAspectCorrection;
			}
			else
			{
				windowAspectCorrection = static_cast<GLdouble>(viewportWidth) / static_cast<double>(viewportHeight);
				left *= windowAspectCorrection;
				right *= windowAspectCorrection;
			}
		}

		gluOrtho2D(left, right, bottom, top);
	}
	else if(renderingContext == GE_CONTEXT_3D)
	{
		windowAspectCorrection = static_cast<GLdouble>(viewportWidth) / static_cast<double>(viewportHeight);
		gluPerspective(projectionFOVY, windowAspectCorrection, projectionZNear, projectionZFar);
	}
}

void GERenderingSystem::renderFrame()
{
	if(!apiWrapper)
	{
		std::cout << "(!) ERROR - It was not possible initialize rendering system: no apiwrapper.\n" << std::endl;
		return;
	}

	// (ATENÇÃO) É possível que neste ponto, apiWrapper não esteja mais
	// apontando para o objeto. Fazer essa validação!

	this->apiWrapper->swapBuffers();
}

// ----------------------------------------------------------------------------
//  GERenderingSystem setters and getters
// ----------------------------------------------------------------------------
void GERenderingSystem::setRenderingContext(int renderingContext)
{
	this->renderingContext = renderingContext;
}

void GERenderingSystem::setApiWrapper(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
}

void GERenderingSystem::setViewportWidth(int viewportWidth)
{
	this->viewportWidth = viewportWidth;
}

void GERenderingSystem::setViewportHeight(int viewportHeight)
{
	this->viewportHeight = viewportHeight;
}

void GERenderingSystem::setWorldLeft(GLdouble worldLeft)
{
	this->worldLeft = worldLeft;
}

void GERenderingSystem::setWorldRight(GLdouble worldRight)
{
	this->worldRight = worldRight;
}

void GERenderingSystem::setWorldTop(GLdouble worldTop)
{
	this->worldTop = worldTop;
}

void GERenderingSystem::setWorldBottom(GLdouble worldBottom)
{
	this->worldBottom = worldBottom;
}

void GERenderingSystem::setWindowAspectCorrection(GLdouble windowAspectCorrection)
{
	this->windowAspectCorrection = windowAspectCorrection;
}

void GERenderingSystem::setProjectionZNear(GLdouble projectionZNear)
{
	this->projectionZNear = projectionZNear;
}

void GERenderingSystem::setProjectionZFar(GLdouble projectionZFar)
{
	this->projectionZFar = projectionZFar;
}

void GERenderingSystem::setProjectionFOVY(GLdouble fovy)
{
	this->projectionFOVY = fovy;
}

void GERenderingSystem::setWindowAspectCorrectionState(int state)
{
	this->windowAspectCorrectionState = state;
}

int GERenderingSystem::getRenderingContext()
{
	return renderingContext;
}

GEApiWrapper *GERenderingSystem::getApiWrapper()
{
	return apiWrapper;
}

int GERenderingSystem::getViewportWidth()
{
	return viewportWidth;
}

int GERenderingSystem::getViewportHeight()
{
	return viewportHeight;
}

GLdouble GERenderingSystem::getWorldLeft()
{
	return worldLeft;
}

GLdouble GERenderingSystem::getWorldRight()
{
	return worldRight;
}

GLdouble GERenderingSystem::getWorldTop()
{
	return worldTop;
}

GLdouble GERenderingSystem::getWorldBottom()
{
	return worldBottom;
}

GLdouble GERenderingSystem::getWindowAspectCorrection()
{
	return windowAspectCorrection;
}

GLdouble GERenderingSystem::getProjectionZNear()
{
	return projectionZNear;
}

GLdouble GERenderingSystem::getProjectionZFar()
{
	return projectionZFar;
}

GLdouble GERenderingSystem::getProjectionFOVY()
{
	return projectionFOVY;
}

int GERenderingSystem::getWindowAspectCorrectionState()
{
	return windowAspectCorrectionState;
}