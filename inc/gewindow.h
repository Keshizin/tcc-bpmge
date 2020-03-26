#ifndef GAME_ENGINE_WINDOW_CLASS_H
#define GAME_ENGINE_WINDOW_CLASS_H

#include <geapiwrapper.h>
#include <string>

class GEWindow
{
public:
	GEWindow(GEApiWrapper *apiWrapper);

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
	void setApiWrapper(GEApiWrapper *apiWrapper);

	std::string getName();
	int getWidth();
	int getHeight();
	int getStyle();
	int getXPosition();
	int getYPosition();
	GEApiWrapper *getApiWrapper();

private:
	std::string name;
	int width;
	int height;
	int style;
	int xPosition;
	int yPosition;

	GEApiWrapper *apiWrapper;
};

#endif