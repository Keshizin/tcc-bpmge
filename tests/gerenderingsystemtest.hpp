#ifndef GAME_ENGINE_RENDERING_SYSTEM_H_TEST
#define GAME_ENGINE_RENDERING_SYSTEM_H_TEST

#include <geeventhandler.h>

class RenderingTestEventHandler : public GEEventHandler
{
public:
	void frameEvent();
	void resizeWindowEvent(int width, int height);
	void finishAfterEvent();
	void finishBeforeEvent();
};

int testRenderingSystem();

#endif