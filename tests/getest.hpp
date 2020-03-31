#ifndef GAME_ENGINE_H_TEST
#define GAME_ENGINE_H_TEST

#include <ge.h>

class TestEventHandler : public GEEventHandler
{
public:
	void frameEvent();
};

int testInstanceGameEngine();
int testMainLoop();

#endif