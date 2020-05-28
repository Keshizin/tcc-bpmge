#include <getimehandler.h>

// ----------------------------------------------------------------------------
//  CLASS METHODS DEFINITION
// ----------------------------------------------------------------------------

void GETimeHandler::setFrameTime(unsigned long long frameTime)
{
	this->frameTime = frameTime;
}

unsigned long long GETimeHandler::getFrameTime()
{
	return frameTime;
}

void GETimeHandler::setInternalTimer(unsigned long long internalTimer)
{
	this->internalTimer = internalTimer;
}

void GETimeHandler::updateInternalTimer()
{
	this->internalTimer += frameTime;
}

unsigned long long GETimeHandler::getInternalTimer()
{
	return internalTimer;
}