/*
	Game Engine Diagnostics
	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <gediag.h>
#include <iostream>

// ----------------------------------------------------------------------------
//  GEDiag CLASS CONSTRUCTOR DEFINITION
// ----------------------------------------------------------------------------

GEDiag::GEDiag(GETimeHandler *timeHandler)
{
	timer = new GETimer(timeHandler);

	for(int i = 0; i < DIAG_SIZE; i++)
		store_fps[i] = 0;
}

GEDiag::~GEDiag()
{
	delete timer;
}

// ----------------------------------------------------------------------------
//  GEDiag CLASS METHODS DEFINITION
// ----------------------------------------------------------------------------

void GEDiag::start(unsigned long long frequency)
{
	timer->setTimer(frequency);
	timer->start();
	store_index = 0;
	framesCounter = 0;
}

void GEDiag::update()
{
	framesCounter++;

	if(timer->isDone())
	{
		framesPerSecond = framesCounter;

		if(store_index < DIAG_SIZE)
			store_fps[store_index++] = framesPerSecond;

		timer->start();
		framesCounter = 0;
	}
}

void GEDiag::print()
{
	std::cout
		<< "------------------------------------------------------------\n"
		<< " GAME ENGINE - D I A G N O S T I C S\n"
		<< "------------------------------------------------------------\n";

	for(int i = 0; i < DIAG_SIZE; i++)
	{		
		std::cout << "[INSTANCE " << i + 1 << "] FPS: " << store_fps[i] << std::endl;
	}

	std::cout << std::endl;
}

void GEDiag::setFramesPerSecond(unsigned long long framesPerSecond)
{
	this->framesPerSecond = framesPerSecond;
}

unsigned long long GEDiag::getFramesPerSecond()
{
	return framesPerSecond;
}