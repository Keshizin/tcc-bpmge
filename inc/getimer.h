#ifndef GAME_ENGINE_TIMER_H
#define GAME_ENGINE_TIMER_H

#include <getimehandler.h>

class GETimer
{
public:
	GETimer(GETimeHandler *timeHandler);

	void setTimer(unsigned long long stopTime);
	void start();
	int isDone();

private:
	unsigned long long stopTime;
	unsigned long long startTimer;
	GETimeHandler *timeHandler;
};

#endif