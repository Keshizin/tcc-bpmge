#ifndef GAME_ENGINE_EVENT_HANDLER_TEST
#define GAME_ENGINE_EVENT_HANDLER_TEST

#include <geevthandler.h>

class UserEventHandler : public GEEventHandler
{
public:
	void frameEvent();
	void mouseEvent(int button, int state, int x, int y);
	void mouseMotionEvent(int x, int y);
	void resizeWindow(int width, int height);
};

int eventHandlerTest();

#endif