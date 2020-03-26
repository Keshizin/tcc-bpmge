#include <gewindow.h>

GEWindow::GEWindow(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
}

int GEWindow::createWindow()
{
	if(!apiWrapper->initializeWindow())
		return 0;

	if(!apiWrapper->createWindow(getXPosition(), getYPosition(), getWidth(), getHeight(), getName()))
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

void GEWindow::setApiWrapper(GEApiWrapper *apiWrapper)
{
	this->apiWrapper = apiWrapper;
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

GEApiWrapper *GEWindow::getApiWrapper()
{
	return apiWrapper;
}