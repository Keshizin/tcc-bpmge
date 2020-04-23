#include <gediag.h>
#include <iostream>

GEDiag::GEDiag(GETimeHandler *timeHandler)
{
	timer = new GETimer(timeHandler);
}

GEDiag::~GEDiag()
{
	delete timer;
}

void  GEDiag::start(unsigned long long frequency)
{
	timer->setTimer(frequency);
	timer->start();
	framesPerSecond = 0;
}

void GEDiag::update()
{
	framesPerSecond++;

	if(timer->isDone())
	{
		std::cout << "FPS: " << framesPerSecond << std::endl;
		timer->start();
		framesPerSecond = 0;
	}
}

void GEDiag::setFramesPerSecond(unsigned long long framesPerSecond)
{
	this->framesPerSecond = framesPerSecond;
}

unsigned long long GEDiag::getFramesPerSecond()
{
	return framesPerSecond;
}