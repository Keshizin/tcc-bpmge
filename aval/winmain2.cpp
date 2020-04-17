// g++ winmain2.cpp -I../inc ../obj/gewinapiwrapper.o ../obj/geapiwrapper.o -lopengl32 -lglu32 -lgdi32  -Wall

#include <windows.h>
#include <iostream>
#include <gewinapiwrapper.h>

#define SIZE 10

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GEWinApiWrapper winApiWrapper;

	unsigned long long startTime = 0;
	unsigned long long endTime = 0;
	unsigned long long frameTime = 0;
	unsigned long long frequency = 0;
	unsigned long long timer = 0;
	unsigned long long frameTimeTotal = 0;

	long long unsigned storeMaxFrameTime[SIZE] = {0};
	long long unsigned storeMinFrameTime[SIZE] = {0};
	unsigned long long storeFrameTime[SIZE] = {0};
	unsigned long long storeNumberOfFrames[SIZE] = {0};
	double storeAverageFrameTime[SIZE] = {0};

	unsigned long long numberOfFrames = 0;
	int seconds = 0;
	int isRunning = 1;

	for(int i = 0; i < SIZE; i++)
		storeMinFrameTime[i] = 999999;

	std::cout << "BPM Game Engine Evaluation - COM OVERHEAD DE WINAPI\n" << std::endl;
	std::cout << "> starting main loop..." << std::endl;

	endTime = winApiWrapper.getHighResolutionTimerCounter();

	while(isRunning)
	{
		startTime = winApiWrapper.getHighResolutionTimerCounter();
		// ********************************************************************
		// GAME LOOP EXECUTION HERE
		// ********************************************************************
		timer += frameTime;
		frameTimeTotal += frameTime;

		if(frameTime > storeMaxFrameTime[seconds])
			storeMaxFrameTime[seconds] = frameTime;

		if(frameTime < storeMinFrameTime[seconds])
			storeMinFrameTime[seconds] = frameTime;

		frequency = winApiWrapper.getHighResolutionTimerFrequency();

		if(timer >= frequency)
		{
			storeAverageFrameTime[seconds] = frameTimeTotal / static_cast<double>(numberOfFrames);
			frameTimeTotal = 0;

			storeFrameTime[seconds] = frameTime;
			storeNumberOfFrames[seconds] = numberOfFrames;

			numberOfFrames = 0;
			timer = 0;
			seconds++;

			if(seconds == SIZE)
				isRunning = 0;
		}

		// ********************************************************************
		// GAME LOOP EXECUTION HERE
		// ********************************************************************
		// armazenando o tempo restante do quadro anterior
		frameTime = startTime - endTime; 
		endTime = winApiWrapper.getHighResolutionTimerCounter();
		frameTime += endTime - startTime;
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