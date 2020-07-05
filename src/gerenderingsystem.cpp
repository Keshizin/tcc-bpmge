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

void GERenderingSystem::setViewport()
{
	glViewport(0, 0, viewportWidth, viewportHeight);
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

// ----------------------------------------------------------------------------
//  GERenderingSystem methods definition
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

void GERenderingSystem::setWordLeft(GLdouble worldLeft)
{
	this->worldLeft = worldLeft;
}

void GERenderingSystem::setWordRight(GLdouble worldRight)
{
	this->worldRight = worldRight;
}

void GERenderingSystem::setWordTop(GLdouble worldTop)
{
	this->worldTop = worldTop;
}

void GERenderingSystem::setWordBottom(GLdouble worldBottom)
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

GLdouble GERenderingSystem::getWordLeft()
{
	return worldLeft;
}

GLdouble GERenderingSystem::getWordRight()
{
	return worldRight;
}

GLdouble GERenderingSystem::getWordTop()
{
	return worldTop;
}

GLdouble GERenderingSystem::getWordBottom()
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

// void GERenderingSystem::setProjection()
// {
// 	glViewport(0, 0, viewportWidth, viewportHeight);

// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();

// 	if(renderingMode == GE_CONTEXT_2D)
// 	{		
// 		gluOrtho2D(0, viewportWidth, 0, viewportHeight);
// 	}
// 	else if(renderingMode == GE_CONTEXT_3D)
// 	{
// 		gluPerspective(45.0, static_cast<GLfloat>(viewportWidth) / static_cast<GLfloat>(viewportHeight), 1.0, 1000.0);
// 	}

// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();

// 	glClearColor(0.97f, 0.76f, 0.09f, 1.0f);
// 	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

// 	// switch(backgroundColor)
// 	// {
// 	// 	case GE_BKG_COLOR_WHITE:
// 	// 		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
// 	// 		break;
// 	// 	case GE_BKG_COLOR_BLACK:
// 	// 		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
// 	// 		break;
// 	// 	case GE_BKG_COLOR_RED:
// 	// 		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
// 	// 		break;
// 	// 	case GE_BKG_COLOR_GREEN:
// 	// 		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
// 	// 		break;
// 	// 	case GE_BKG_COLOR_BLUE:
// 	// 		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
// 	// 		break;

// 	// 	case GE_BKG_COLOR_UBUNTU_PURPLE:
// 	// 		//48182D
// 	// 		glClearColor(0.28f, 0.09f, 0.18f, 1.0f);
// 	// 		break;

// 	// 	default:
// 	// 		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
// 	// 		break;
// 	// }
// }

// void GERenderingSystem::renderFrame()
// {
// 	this->apiWrapper->swapBuffers();
// }

// void GERenderingSystem::setRenderingMode(int renderingMode)
// {
// 	this->renderingMode = renderingMode;
// }

// // void GERenderingSystem::setBackgroundColor(int backgroundColor)
// // {
// // 	this->backgroundColor = backgroundColor;
// // }

// // int GERenderingSystem::getBackgroundColor()
// // {
// // 	return backgroundColor;
// // }
