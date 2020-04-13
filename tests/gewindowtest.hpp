#ifndef GAME_ENGINE_WINDOW_TEST
#define GAME_ENGINE_WINDOW_TEST

#include <geevthandler.h>

class WindowTestEventHandler : public GEEventHandler
{
public:
	void keyboardEvent(unsigned char key, int state);
	void finishAfterEvent();
	void finishBeforeEvent();
};

int testInstanceWindow();
int testCreateWindow();
int testDestroyWindow();
int testShowWindow();
int testWindowStyles();

#endif