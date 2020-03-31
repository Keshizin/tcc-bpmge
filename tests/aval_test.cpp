#include <windows.h>
#include <iostream>

#include <gewinapiwrapper.h>

#define SIZE 10

void pure();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Avaliação #1
	pure();
	return 1;
}

void pure()
{
	int isRunning;

	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	LARGE_INTEGER frameTime;
	LARGE_INTEGER frequency;
	LARGE_INTEGER timer;

	unsigned long long store_frameTime[SIZE] = {0};
	unsigned long long store_numberOfFrames[SIZE] = {0};

	unsigned long long numberOfFrames = 0;
	int seconds = 0;
	

	std::cout << "Hello BPM Game Engine!" << std::endl;

	timer.QuadPart = 0;
	frameTime.QuadPart = 0;

	std::cout << "> start main loop..." << std::endl;

	QueryPerformanceCounter(&endTime);

	while(isRunning)
	{
		QueryPerformanceCounter(&startTime);

		// ********************************************************************
		// GAME LOOP EXECUTION HERE
		// ********************************************************************
		timer.QuadPart += frameTime.QuadPart;
		QueryPerformanceFrequency(&frequency);

		if(timer.QuadPart >= frequency.QuadPart)
		{
			store_frameTime[seconds] = frameTime.QuadPart;
			store_numberOfFrames[seconds] = numberOfFrames;

			numberOfFrames = 0;
			timer.QuadPart = 0;
			timer.QuadPart = 0;

			seconds++;

			if(seconds == SIZE)
				isRunning = 0;
		}

		// ********************************************************************
		// GAME LOOP EXECUTION HERE
		// ********************************************************************

		// armazenando o tempo restante do quadro anterior
		frameTime.QuadPart = startTime.QuadPart - endTime.QuadPart; 
		QueryPerformanceCounter(&endTime);
		frameTime.QuadPart += endTime.QuadPart - startTime.QuadPart;
		numberOfFrames++;
	}

	std::cout << "> end main loop..." << std::endl;

	std::cout << "Bye BPM Game Engine!" << std::endl;	
}