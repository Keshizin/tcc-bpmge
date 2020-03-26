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
	winApiWrapper->setWindowClassName("TEST1WINDOWCLASS");
	GEApiWrapper *apiWrapper = winApiWrapper;
	
	GEWindow test(apiWrapper);

	// Criar uma janela de aplicação sem configurar os atributos da janela
	if(!test.createWindow())
	{
		delete winApiWrapper;
		return 0;
	}

	// Criar uma segunda janela de aplicação com o mesmo nome de WindowClass - deve retornar um erro
	if(test.createWindow())
	{
		delete winApiWrapper;
		return 0;
	}

	winApiWrapper->setWindowClassName("TESTWINDOWCLASS");

	// Criar uma segunda janela de aplicação com diferente nome de WindowClass
	if(!test.createWindow())
	{
		delete winApiWrapper;
		return 0;
	}

	delete winApiWrapper;
	return 1;
}

int testDestroyWindow()
{
	GEWinApiWrapper *winApiWrapper = new GEWinApiWrapper();
	winApiWrapper->setWindowClassName("TEST2WINDOWCLASS");
	GEApiWrapper *apiWrapper = winApiWrapper;

	GEWindow test(apiWrapper);

	// Destruir uma janela de aplicação sem ter criado uma - deve retornar um erro
	if(test.destroyWindow())
	{
		return 0;
	}

	test.createWindow();

	// Destruir uma janela de aplicação após ter criado uma
	if(!test.destroyWindow())
	{
		return 0;
	}

	// Destruir novamente uma janela para ter certeza que a primeira janela foi destruida corretamente
	test.createWindow();

	if(!test.destroyWindow())
	{
		return 0;
	}

	delete winApiWrapper;
	return 1;
}