/*
	Game Engine Core

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <gewindowsystem.h>
#include <getimehandler.h>
#include <gediag.h>
#include <gerenderingsystem.h>

// ----------------------------------------------------------------------------
//  Game Engine runtime status
// ----------------------------------------------------------------------------
#define GE_RUNNING 0x01
#define GE_STOPPED 0x02
#define GE_PAUSED  0x03

// ----------------------------------------------------------------------------
//  Game Engine class
// ----------------------------------------------------------------------------
class GameEngine
{
public:
	// constructors and destructors
	GameEngine(GEEventHandler *eventHandler);
	~GameEngine();

	// public methods
	void startMainLoop();
	void stopMainLoop();
	void pauseGameLoop();
	void resumeGameLoop();

	// getters and setters
	GEWindowSystem *getGameWindow();
	GERenderingSystem *getRenderingSystem();
	GETimeHandler *getTimeHandler();
	GEDiag *getDiag();

private:
	int runningStatus;
	
	GEEventHandler *eventHandler;
	GEApiWrapper *apiWrapper;
	GEWindowSystem *gameWindow;
	GETimeHandler *timeHandler;
	GEDiag *diag;
	GERenderingSystem *renderingSystem;
};

#endif