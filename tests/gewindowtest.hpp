#ifndef GAME_ENGINE_WINDOW_TEST
#define GAME_ENGINE_WINDOW_TEST

#include <geevthandler.h>

class WindowTestEventHandler : public GEEventHandler
{
public:
	void finishAfterEvent();
	void finishBeforeEvent();
};

int testInstanceWindow();
int testCreateWindow();
int testDestroyWindow();
int testShowWindow();

#endif