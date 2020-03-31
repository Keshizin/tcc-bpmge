#include <getimehandler.h>

void GETimeHandler::setFrameTime(unsigned long long frameTime)
{
	this->frameTime = frameTime;
}

unsigned long long GETimeHandler::getFrameTime()
{
	return frameTime;
}