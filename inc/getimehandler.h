#ifndef GAME_ENGINE_TIME_HANDLER_H
#define GAME_ENGINE_TIME_HANDLER_H

class GETimeHandler
{
public:
	// GETTERS AND SETTERS
	void setFrameTime(unsigned long long frameTime);
	unsigned long long getFrameTime();

	void setTimer(unsigned long long timer);
	void updateTimer();
	unsigned long long getTimer();

private:
	unsigned long long frameTime;
	unsigned long long timer;
};

#endif