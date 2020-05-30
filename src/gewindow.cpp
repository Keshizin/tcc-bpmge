#include <gewindow.h>

// ----------------------------------------------------------------------------
//  GameEngine CLASS CONSTRUCTORS DEFINITION
// ----------------------------------------------------------------------------

GEWindow::GEWindow(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
	this->width = 640;
	this->height = 480;
	this->xPosition = 1;
	this->yPosition = 1;
}

GEWindow::~GEWindow()
{
}

// ----------------------------------------------------------------------------
//  GameEngine CLASS METHODS DEFINITION
// ----------------------------------------------------------------------------

int GEWindow::createWindow()
{
	if(!apiWrapper->initializeWindow())
		return 0;

	if(!apiWrapper->createWindow(getXPosition(), getYPosition(), getWidth(), getHeight(), getName(), getStyle()))
		return 0;

	return 1;
}

int GEWindow::destroyWindow()
{
	if(!apiWrapper->destroyWindow())
		return 0;

	return 1;
}

int GEWindow::showWindow()
{
	apiWrapper->showWindow();
	return 1;
}

// ----------------------------------------------------------------------------
//  GameEngine CLASS GETTERS AND SETTERS METHODS DEFINITION
// ----------------------------------------------------------------------------

void GEWindow::setName(std::string name)
{
	this->name = name;
}

void GEWindow::setWidth(int width)
{
	this->width = width;
}

void GEWindow::setHeight(int height)
{
	this->height = height;
}

void GEWindow::setStyle(int style)
{
	this->style = style;
}

void GEWindow::setXPosition(int xPosition)
{
	this->xPosition = xPosition;
}

void GEWindow::setYPosition(int yPosition)
{
	this->yPosition = yPosition;
}

std::string GEWindow::getName()
{
	return name;
}

int GEWindow::getWidth()
{
	return width;
}

int GEWindow::getHeight()
{
	return height;
}

int GEWindow::getStyle()
{
	return style;
}

int GEWindow::getXPosition()
{
	return xPosition;
}

int GEWindow::getYPosition()
{
	return yPosition;
}