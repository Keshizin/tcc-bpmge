#include <getimer.h>

GETimer::GETimer(GETimeHandler *timeHandler)
{
	this->timeHandler = timeHandler;
}

void GETimer::setTimer(unsigned long long stopTime)
{
	this->stopTime = stopTime;
}

void GETimer::start()
{
	startTimer = timeHandler->getInternalTimer();
}

int GETimer::isDone()
{
	if(timeHandler->getInternalTimer() - startTimer >= stopTime)
		return 1;
	else
		return 0;
}
