#ifndef GAME_ENGINE_WINDOW_CLASS_H
#define GAME_ENGINE_WINDOW_CLASS_H

#include <string>

class GEWindow
{
public:
	GEWindow();

	int createWindow();
	int destroyWindow();

	void setName(std::string name);
	void setWidth(int width);
	void setHeight(int height);
	void setStyle(int style);
	void setXPosition(int xPosition);
	void setYPosition(int yPosition);

	std::string getName();
	int getWidth();
	int getHeight();
	int getStyle();
	int getXPosition();
	int getYPosition();

private:
	std::string name;
	int width;
	int height;
	int style;
	int xPosition;
	int yPosition;
};

#endif