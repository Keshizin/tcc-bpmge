/*
	Game Engine Time Handler

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_TIME_HANDLER_H
#define GAME_ENGINE_TIME_HANDLER_H

class GETimeHandler
{
public:
	void setFrameTime(unsigned long long frameTime);
	unsigned long long getFrameTime();
	void setInternalTimer(unsigned long long internalTimer);
	void updateInternalTimer();
	unsigned long long getInternalTimer();

private:
	unsigned long long frameTime;
	unsigned long long internalTimer;
};

#endif