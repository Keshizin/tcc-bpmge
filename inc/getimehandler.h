#ifndef GAME_ENGINE_TIME_HANDLER_H
#define GAME_ENGINE_TIME_HANDLER_H

class GETimeHandler
{
public:
	void setFrameTime(unsigned long long frameTime);
	unsigned long long getFrameTime();
	void setInternalTimer(unsigned long long internalTimer);
	void updateInternalTimer();
	unsigned long long getInternalTimer();

private:
	unsigned long long frameTime;
	unsigned long long internalTimer;
};

#endif