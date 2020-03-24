#include "gewindowtest.hpp"
#include <gewindow.h>
#include <iostream>

int testInstanceWindow()
{
	GEApiWrapper *apiWrapper = new GEApiWrapper();
	GEWindow test(apiWrapper);

	// Teste GETTERS and SETTERS
	test.setName("teste window");
	test.setWidth(800);
	test.setHeight(600);
	test.setStyle(1);
	test.setXPosition(10);
	test.setYPosition(20);

	if(test.getName().compare("teste window"))
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