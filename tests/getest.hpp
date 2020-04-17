#ifndef GAME_ENGINE_H_TEST
#define GAME_ENGINE_H_TEST

#include <ge.h>

class TestGEEventHandler : public GEEventHandler
{
public:
	void frameEvent();
	void mouseEvent(int button, int state, int x, int y);
	void mouseMotionEvent(int x, int y);
	void keyboardEvent(unsigned char key, int state);
	void keyboardSpecialEvent(unsigned char key, int state);
	void resizeWindowEvent(int width, int height);
	void finishAfterEvent();
	void finishBeforeEvent();
};

int testInstanceGameEngine();
int testMainLoop();
int testTimeHandler();

#endif