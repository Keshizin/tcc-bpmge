#ifndef GAME_ENGINE_TIMER_H
#define GAME_ENGINE_TIMER_H

#include <getimehandler.h>

class GETimer
{
public:
	GETimer(GETimeHandler *timeHandler);

	void setTimer(unsigned long long limit);
	void start();
	int isDone();

private:
	unsigned long long limit;
	unsigned long long startTimer;
	GETimeHandler *timeHandler;
};

#endif