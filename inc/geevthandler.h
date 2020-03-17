#ifndef GAME_ENGINE_EVENT_HANDLER_CLASS_H
#define GAME_ENGINE_EVENT_HANDLER_CLASS_H

class GEEventHandler
{
public:
	virtual void drawFrame() {};
	virtual void mouseEvent(int button, int state, int x, int y) {};
	virtual void mouseMotionEvent(int x, int y) {};
	virtual void resizeWindow(int width, int height) {};
};

#endif