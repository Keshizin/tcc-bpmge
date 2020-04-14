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

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void GERenderingSystem::renderFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GERenderingSystem::setDoubleBufferMode(int bufferMode)
{
	this->doubleBufferMode = bufferMode;
}

int GERenderingSystem::isDoubleBufferMode()
{
	return doubleBufferMode;
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