#include <getimer.h>

GETimer::GETimer(GETimeHandler *timeHandler)
{
	this->timeHandler = timeHandler;
}

void GETimer::setTimer(unsigned long long limit)
{
	this->limit = limit;
}

void GETimer::start()
{
	startTimer = timeHandler->getInternalTimer();
}

int GETimer::isDone()
{
	if(timeHandler->getInternalTimer() - startTimer >= limit)
		return 1;
	else
		return 0;
}
