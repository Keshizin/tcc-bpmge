#ifndef GAME_ENGINE_WINDOW_TEST
#define GAME_ENGINE_WINDOW_TEST

#include <geevthandler.h>

class T1EventHandler : public GEEventHandler
{
public:
	void frameEvent();
	void finishEvent();
};

int testInstanceWindow();
int testCreateWindow();
int testDestroyWindow();
int testShowWindow();

#endif