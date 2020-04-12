#ifndef GAME_ENGINE_WINDOW_CLASS_H
#define GAME_ENGINE_WINDOW_CLASS_H

#include <geapiwrapper.h>
#include <string>

class GEWindow
{
public:
	GEWindow();
	~GEWindow();

	int createWindow();
	int destroyWindow();
	int showWindow();

	// Getters and Setters
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
	int xPosition;
	int yPosition;
	unsigned int style;

	GEApiWrapper *apiWrapper;
};

#endif