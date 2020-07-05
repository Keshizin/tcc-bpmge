/*
	Game Engine Timer

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#include <getimer.h>

// ----------------------------------------------------------------------------
//  GETimer constructor and destructor
// ----------------------------------------------------------------------------
GETimer::GETimer(GETimeHandler *timeHandler)
{
	this->timeHandler = timeHandler;
}

// ----------------------------------------------------------------------------
//  GETimer methods definition
// ----------------------------------------------------------------------------
void GETimer::setTimer(unsigned long long stopTime)
{
	this->stopTime = stopTime;
}

void GETimer::start()
{
	startTimer = timeHandler->getInternalTimer();
}

int GETimer::isDone()
{
	if(timeHandler->getInternalTimer() - startTimer >= stopTime)
		return 1;
	else
		return 0;
}