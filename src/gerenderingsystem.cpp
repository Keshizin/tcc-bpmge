#include <gerenderingsystem.h>

#include <GL/gl.h>
#include <GL/glu.h>

GERenderingSystem::GERenderingSystem(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
	this->renderingMode = GE_RENDERING_SYSTEM_2D;
}

int GERenderingSystem::initialize(int width, int height)
{
	if(!apiWrapper->initializeRenderingSystem())
		return 0;

	setViewport(width, height);
	return 1;
}

void GERenderingSystem::setViewport(int width, int height)
{
	this->viewportWidth = width;
	this->viewportHeight = height;
}

void GERenderingSystem::setProjection()
{
	glViewport(0, 0, viewportWidth, viewportHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(renderingMode == GE_RENDERING_SYSTEM_2D)
	{		
		gluOrtho2D(0, viewportWidth, 0, viewportHeight);
	}
	else if(renderingMode == GE_RENDERING_SYSTEM_3D)
	{
		gluPerspective(45.0, static_cast<GLfloat>(viewportWidth) / static_cast<GLfloat>(viewportHeight), 1.0, 1000.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.97f, 0.76f, 0.09f, 1.0f);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// switch(backgroundColor)
	// {
	// 	case GE_BKG_COLOR_WHITE:
	// 		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// 		break;
	// 	case GE_BKG_COLOR_BLACK:
	// 		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// 		break;
	// 	case GE_BKG_COLOR_RED:
	// 		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	// 		break;
	// 	case GE_BKG_COLOR_GREEN:
	// 		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	// 		break;
	// 	case GE_BKG_COLOR_BLUE:
	// 		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	// 		break;

	// 	case GE_BKG_COLOR_UBUNTU_PURPLE:
	// 		//48182D
	// 		glClearColor(0.28f, 0.09f, 0.18f, 1.0f);
	// 		break;

	// 	default:
	// 		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// 		break;
	// }
}

void GERenderingSystem::renderFrame()
{
	this->apiWrapper->swapBuffers();
}

void GERenderingSystem::setRenderingMode(int renderingMode)
{
	this->renderingMode = renderingMode;
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

// void GERenderingSystem::setBackgroundColor(int backgroundColor)
// {
// 	this->backgroundColor = backgroundColor;
// }

// int GERenderingSystem::getBackgroundColor()
// {
// 	return backgroundColor;
// }
