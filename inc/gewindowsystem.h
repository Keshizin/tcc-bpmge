/*
	Game Engine Window System Class

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_WINDOW_SYSTEM_CLASS_H
#define GAME_ENGINE_WINDOW_SYSTEM_CLASS_H

#include <string>
#include <geapiwrapper.h>

// ----------------------------------------------------------------------------
//  Game engine window styles
// ----------------------------------------------------------------------------
#define GE_WIN_SPLASH               0x01
#define GE_WIN_DEFAULT              0x02
#define GE_WIN_DEFAULT_NO_SYS       0x03
#define GE_WIN_WINDOWED_FULLSCREEN  0x04
#define GE_WIN_COMPLETE             0x05

// ----------------------------------------------------------------------------
//  GEWindow class
// ----------------------------------------------------------------------------
class GEWindowSystem
{
public:
	GEWindowSystem();
	GEWindowSystem(GEApiWrapper *apiWrapper);
	~GEWindowSystem();

	// public methods
	int createWindow();
	int destroyWindow();
	int showWindow();
	// int createWindowWithoutRegister();

	// setters
	void setName(std::string name);
	void setWidth(int width);
	void setHeight(int height);
	void setStyle(int style);
	void setX(int x);
	void setY(int y);
	void setApiWrapper(GEApiWrapper *apiWrapper);

	// getters
	std::string getName();
	int getWidth();
	int getHeight();
	int getStyle();
	int getX();
	int getY();
	GEApiWrapper *getApiWrapper();

private:
	std::string name;
	int width;
	int height;
	int x;
	int y;
	unsigned int style;
	GEApiWrapper *apiWrapper;
};

#endif 