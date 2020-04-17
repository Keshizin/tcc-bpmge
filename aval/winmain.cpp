// g++ winmain.cpp -Wall

#include <windows.h>
#include <iostream>

#define SIZE 10

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	LARGE_INTEGER frameTime;
	LARGE_INTEGER frequency;
	LARGE_INTEGER timer;
	LARGE_INTEGER frameTimeTotal;
	frameTimeTotal.QuadPart = 0;

	long long storeMaxFrameTime[SIZE] = {0};
	long long storeMinFrameTime[SIZE] = {0};
	unsigned long long storeFrameTime[SIZE] = {0};
	unsigned long long storeNumberOfFrames[SIZE] = {0};
	double storeAverageFrameTime[SIZE] = {0};

	unsigned long long numberOfFrames = 0;
	int seconds = 0;
	int isRunning = 1;

	frameTime.QuadPart = 0;

	for(int i = 0; i < SIZE; i++)
		storeMinFrameTime[i] = 999999;

	std::cout << "BPM Game Engine Evaluation - NO OVERHEAD\n" << std::endl;
	std::cout << "> starting main loop..." << std::endl;

	QueryPerformanceCounter(&endTime);

	while(isRunning)
	{
		QueryPerformanceCounter(&startTime);

		// ********************************************************************
		// START - GAME LOOP EXECUTION HERE
		// ********************************************************************
		timer.QuadPart += frameTime.QuadPart;
		frameTimeTotal.QuadPart += frameTime.QuadPart;

		if(frameTime.QuadPart > storeMaxFrameTime[seconds])
			storeMaxFrameTime[seconds] = frameTime.QuadPart;

		if(frameTime.QuadPart < storeMinFrameTime[seconds])
			storeMinFrameTime[seconds] = frameTime.QuadPart;

		QueryPerformanceFrequency(&frequency);

		if(timer.QuadPart >= frequency.QuadPart)
		{
			storeAverageFrameTime[seconds] = frameTimeTotal.QuadPart / static_cast<double>(numberOfFrames);
			frameTimeTotal.QuadPart = 0;

			storeFrameTime[seconds] = frameTime.QuadPart;
			storeNumberOfFrames[seconds] = numberOfFrames;

			numberOfFrames = 0;
			timer.QuadPart = 0;
			seconds++;

			if(seconds == SIZE)
				isRunning = 0;
		}

		// ********************************************************************
		// END - GAME LOOP EXECUTION HERE
		// ********************************************************************
		// armazenando o tempo restante do quadro anterior
		frameTime.QuadPart = startTime.QuadPart - endTime.QuadPart; 
		QueryPerformanceCounter(&endTime);
		frameTime.QuadPart += endTime.QuadPart - startTime.QuadPart;
		numberOfFrames++;
	}

	std::cout << "> end of main loop..." << std::endl;
	std::cout << "> RESULTS:" << std::endl;

	for(int i = 0; i < SIZE; i++)
	{
		std::cout << "\tframe time: " << storeFrameTime[i] << std::endl;
		std::cout << "\tmax frame time: " << storeMaxFrameTime[i] << std::endl;
		std::cout << "\tmin frame time: " << storeMinFrameTime[i] << std::endl;
		std::cout << "\taverage frame time: " << storeAverageFrameTime[i] << std::endl;
		std::cout << "\tframes per second: " << storeNumberOfFrames[i] << "\n" << std::endl;
	}

	return 1;
}