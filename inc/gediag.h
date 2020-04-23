#ifndef GAME_ENGINE_DIAG_H
#define GAME_ENGINE_DIAG_H

#include <getimer.h>

class GEDiag
{
public:
	GEDiag(GETimeHandler *timeHandler);
	~GEDiag();
	
	void start(unsigned long long frequency);
	void update();

	// Getters and Setters
	void setFramesPerSecond(unsigned long long framesPerSecond);
	unsigned long long getFramesPerSecond();

private:
	unsigned long long framesPerSecond;
	GETimer *timer;
};

#endif