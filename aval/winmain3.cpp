// g++ winmain3.cpp -I../inc ../obj/getimer.o ../obj/gediag.o ../obj/ge.o ../obj/getimehandler.o ../obj/geapiwrapper.o ../obj/gewinapiwrapper.o -lopengl32 -lglu32 -lgdi32 -Wall

#include <windows.h>
#include <iostream>
#include <ge.h>

#define SIZE 10

GameEngine *singletonGameEngine = 0;

unsigned long long startTime = 0;
unsigned long long endTime = 0;
unsigned long long frameTime = 0;
unsigned long long frequency = 0;
unsigned long long timer = 0;
unsigned long long frameTimeTotal = 0;
unsigned long long numberOfFrames = 0;

int seconds = 0;

unsigned long long storeMaxFrameTime[SIZE] = {0};
unsigned long long storeMinFrameTime[SIZE] = {0};
unsigned long long storeFrameTime[SIZE] = {0};
unsigned long long storeNumberOfFrames[SIZE] = {0};
double storeAverageFrameTime[SIZE] = {0};

class TestGEEventHandler : public GEEventHandler
{
public:
	~TestGEEventHandler() {}

	void frameEvent()
	{
		frameTime = singletonGameEngine->getTimeHandler()->getFrameTime();
		timer += frameTime;
		frameTimeTotal += frameTime;

		if(frameTime > storeMaxFrameTime[seconds])
			storeMaxFrameTime[seconds] = frameTime;

		if(frameTime < storeMinFrameTime[seconds])
			storeMinFrameTime[seconds] = frameTime;

		if(timer >= singletonGameEngine->getApiWrapper()->getHighResolutionTimerFrequency())
		{
			storeAverageFrameTime[seconds] = frameTimeTotal / static_cast<double>(numberOfFrames);
			frameTimeTotal = 0;

			storeFrameTime[seconds] = frameTime;
			storeNumberOfFrames[seconds] = numberOfFrames;

			numberOfFrames = 0;
			timer = 0;
			seconds++;

			if(seconds == SIZE)
				singletonGameEngine->stopMainLoop();
		}

		numberOfFrames++;
	}

	void finishAfterEvent()
	{
		singletonGameEngine->stopMainLoop();
	}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	singletonGameEngine = new GameEngine();

	TestGEEventHandler *testGEEventHandler = new TestGEEventHandler();
	singletonGameEngine->setEventHandler(testGEEventHandler);

	for(int i = 0; i < SIZE; i++)
		storeMinFrameTime[i] = 999999;
	
	std::cout << "BPM Game Engine Evaluation - COM OVERHEAD DE GAME ENGINE\n" << std::endl;
	std::cout << "> starting main loop..." << std::endl;
	
	singletonGameEngine->startMainLoop();

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

	delete testGEEventHandler;
	delete singletonGameEngine;
	return 1;
}