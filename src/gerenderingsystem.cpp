#include <gerenderingsystem.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>

void GERenderingSystem::setRenderingSystem()
{
	glViewport(0, 0, getViewportWidth(), getViewportHeight());

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(0,  getViewportWidth(), 0, getViewportHeight());
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch(backgroundColor)
	{
		case GE_BKG_COLOR_WHITE:
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			break;
		case GE_BKG_COLOR_BLACK:
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			break;
		case GE_BKG_COLOR_RED:
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			break;
		case GE_BKG_COLOR_GREEN:
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
			break;
		case GE_BKG_COLOR_BLUE:
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
			break;
		default:
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			break;
	}
}

void GERenderingSystem::renderFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GERenderingSystem::setViewportWidth(int viewportWidth)
{
	this->viewportWidth = viewportWidth;
}

int GERenderingSystem::getViewportWidth()
{
	return viewportWidth;
}

void GERenderingSystem::setViewportHeight(int viewportHeight)
{
	this->viewportHeight = viewportHeight;
}

int GERenderingSystem::getViewportHeight()
{
	return viewportHeight;
}

void GERenderingSystem::setBackgroundColor(int backgroundColor)
{
	this->backgroundColor = backgroundColor;
}

int GERenderingSystem::getBackgroundColor()
{
	return backgroundColor;
}
