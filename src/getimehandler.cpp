#include <getimehandler.h>

void GETimeHandler::setFrameTime(unsigned long long frameTime)
{
	this->frameTime = frameTime;
}

unsigned long long GETimeHandler::getFrameTime()
{
	return frameTime;
}

void GETimeHandler::setTimer(unsigned long long timer)
{
	this->timer = timer;
}

void GETimeHandler::updateTimer()
{
	this->timer += frameTime;
}

unsigned long long GETimeHandler::getTimer()
{
	return timer;
}