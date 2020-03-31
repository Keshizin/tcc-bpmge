#include <windows.h>
#include <iostream>

#include <gewinapiwrapper.h>

#define SIZE 10

void pure();
void withWinApiWrapper();

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// {
// 	// Avaliação #1
// 	pure();
// 	return 1;
// }

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

	for(int i = 0; i < SIZE; i++)
	{
		std::cout << "--- frame time: " << store_frameTime[i] << std::endl;
		std::cout << "--- FPS: " << store_numberOfFrames[i] << std::endl;
	}

	std::cout << "Bye BPM Game Engine!" << std::endl;	
}

void withWinApiWrapper()
{
	int isRunning;

	GEWinApiWrapper winApiWrapper;

	unsigned long long startTime;
	unsigned long long endTime;
	unsigned long long frameTime = 0;
	unsigned long long frequency;
	unsigned long long timer = 0;
	
	unsigned long long store_startTime[SIZE] = {0};
	unsigned long long store_endTime[SIZE] = {0};
	unsigned long long store_frameTime[SIZE] = {0};
	unsigned long long store_numberOfFrames[SIZE] = {0};

	unsigned long long numberOfFrames = 0;
	int seconds = 0;
	
	std::cout << "Hello BPM Game Engine!" << std::endl;
	std::cout << "> start main loop..." << std::endl;

	endTime = winApiWrapper.getHighResolutionTimerCounter();

	while(isRunning)
	{
		startTime = winApiWrapper.getHighResolutionTimerCounter();

		// ********************************************************************
		// GAME LOOP EXECUTION HERE
		// ********************************************************************
		timer += frameTime;
		frequency = winApiWrapper.getHighResolutionTimerFrequency();

		if(timer >= frequency)
		{
			store_frameTime[seconds] = frameTime;
			store_numberOfFrames[seconds] = numberOfFrames;

			numberOfFrames = 0;
			timer = 0;

			seconds++;

			if(seconds == SIZE)
				isRunning = 0;
		}

		numberOfFrames++;
		// ********************************************************************
		// GAME LOOP EXECUTION HERE
		// ********************************************************************
		frameTime = startTime - endTime; // armazenando o tempo restante do quadro anterior
		endTime = winApiWrapper.getHighResolutionTimerCounter();
		frameTime += endTime - startTime;
	}

	std::cout << "> end main loop..." << std::endl;

	for(int i = 0; i < SIZE; i++)
	{
		std::cout << "--- frame time: " << store_frameTime[i] << std::endl;
		std::cout << "--- FPS: " << store_numberOfFrames[i] << std::endl;
	}

	std::cout << "Bye BPM Game Engine!" << std::endl; 	
}