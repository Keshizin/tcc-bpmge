#include <gewindow.h>

GEWindow::GEWindow()
{

}

int GEWindow::createWindow()
{
	return 1;
}

int GEWindow::destroyWindow()
{
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
