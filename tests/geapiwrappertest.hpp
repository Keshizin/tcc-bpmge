#ifndef GAME_ENGINE_API_WRAPPER_H_TEST
#define GAME_ENGINE_API_WRAPPER_H_TEST

#include <geeventhandler.h>

class ApiWrapperTestEventHandler : public GEEventHandler
{
public:
	void mouseEvent(int button, int state, int x, int y);
	void mouseMotionEvent(int x, int y);
	void keyboardEvent(unsigned char key, int state);
	void keyboardSpecialEvent(unsigned char key, int state);
	void finishAfterEvent();
	void finishBeforeEvent();
};

int testWinApiWrapper();
int testWinMouseEvent();
int testWinKeyboardEvent();

#endif