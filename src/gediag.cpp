#include <gediag.h>
#include <iostream>

GEDiag::GEDiag(GETimeHandler *timeHandler)
{
	timer = new GETimer(timeHandler);
}

GEDiag::~GEDiag()
{
	delete timer;
}

void GEDiag::start(unsigned long long frequency)
{
	timer->setTimer(frequency);
	timer->start();
	store_index = 0;
	framesPerSecond = 0;
}

void GEDiag::update()
{
	framesPerSecond++;

	if(timer->isDone())
	{
		if(store_index < DIAG_SIZE)
		{
			store_fps[store_index++] = framesPerSecond;
		}

		timer->start();
		framesPerSecond = 0;
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