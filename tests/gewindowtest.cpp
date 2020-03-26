#include "gewindowtest.hpp"

#include <gewindow.h>
#include <iostream>
#include <gewinapiwrapper.h>

int testInstanceWindow()
{
	GEApiWrapper *apiWrapper = new GEApiWrapper();
	GEWindow test(apiWrapper);

	// Teste GETTERS and SETTERS
	test.setName("Test - CASE #1");
	test.setWidth(800);
	test.setHeight(600);
	test.setStyle(1);
	test.setXPosition(10);
	test.setYPosition(20);

	if(test.getName().compare("Test - CASE #1"))
	{
		std::cout << "> Wrong name: " << test.getName() << std::endl;
		return 0;
	}

	if(!(test.getWidth() == 800))
	{
		std::cout << "> Wrong width: " << test.getWidth() << std::endl;
		return 0;
	}

	if(!(test.getHeight() == 600))
	{
		std::cout << "> Wrong height: " << test.getHeight() << std::endl;
		return 0;
	}

	if(!(test.getStyle() == 1))
	{
		std::cout << "> Wrong style: " << test.getStyle() << std::endl;
		return 0;
	}

	if(!(test.getXPosition() == 10))
	{
		std::cout << "> Wrong x position: " << test.getXPosition() << std::endl;
		return 0;
	}

	if(!(test.getYPosition() == 20))
	{
		std::cout << "> Wrong y position: " << test.getYPosition() << std::endl;
		return 0;
	}

	delete apiWrapper;
	return 1;
}

int testCreateWindow()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	winApiWrapper->setWindowClassName("TESTWINDOWCLASS");
	GEApiWrapper *apiWrapper = winApiWrapper;
	
	GEWindow test(apiWrapper);
	test.setName("Test - CASE #2");
	test.setWidth(1400);
	test.setHeight(750);
	test.setStyle(1);
	test.setXPosition(5);
	test.setYPosition(5);

	int ret = test.createWindow();

	delete winApiWrapper;

	if(ret)
		return 1;
	else
		return 0;
}