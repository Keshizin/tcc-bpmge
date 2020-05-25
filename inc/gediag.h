#ifndef GAME_ENGINE_DIAG_H
#define GAME_ENGINE_DIAG_H

#include <getimer.h>

#define DIAG_SIZE 10

class GEDiag
{
public:
	GEDiag(GETimeHandler *timeHandler);
	~GEDiag();
	
	void start(unsigned long long frequency);
	void update();
	void print();

	// Getters and Setters
	void setFramesPerSecond(unsigned long long framesPerSecond);
	unsigned long long getFramesPerSecond();

private:
	int store_index;
	unsigned long long store_fps[DIAG_SIZE];
	unsigned long long framesPerSecond;
	GETimer *timer;
};

#endif