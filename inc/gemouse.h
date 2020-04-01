#ifndef GAME_ENGINE_MOUSE_CLASS_H
#define GAME_ENGINE_MOUSE_CLASS_H

class GEMouse
{
public:
	// GETTERS AND SETTERS
	void setXPosition(int xPosition);
	void setYPosition(int yPosition);
	void setLButton(int lButton);
	void setMButton(int mButton);
	void setRButton(int rButton);
	void setLState(int lState);
	void setMState(int mState);
	void setRState(int rState);

	int getXPosition();
	int getYPosition();
	int getLButton();
	int getMButton();
	int getRButton();
	int getLState();
	int getMState();
	int getRState();

private:
	int xPosition;
	int yPosition;
	int buttons[3];
	int states[3];
};

#endif