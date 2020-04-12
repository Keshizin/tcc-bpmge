#include "gewindowtest.hpp"

#include <iostream>

#include <gewindow.h>

int testInstanceWindow()
{
	GEWindow testWindow;

	// Teste GETTERS and SETTERS
	testWindow.setName("TEST - CASE #1");
	testWindow.setWidth(800);
	testWindow.setHeight(600);
	testWindow.setStyle(1);
	testWindow.setXPosition(10);
	testWindow.setYPosition(20);

	if(testWindow.getName().compare("TEST - CASE #1"))
	{
		std::cout << "> Wrong name: " << testWindow.getName() << std::endl;
		return 0;
	}

	if(!(testWindow.getWidth() == 800))
	{
		std::cout << "> Wrong width: " << testWindow.getWidth() << std::endl;
		return 0;
	}

	if(!(testWindow.getHeight() == 600))
	{
		std::cout << "> Wrong height: " << testWindow.getHeight() << std::endl;
		return 0;
	}

	if(!(testWindow.getStyle() == 1))
	{
		std::cout << "> Wrong style: " << testWindow.getStyle() << std::endl;
		return 0;
	}

	if(!(testWindow.getXPosition() == 10))
	{
		std::cout << "> Wrong x position: " << testWindow.getXPosition() << std::endl;
		return 0;
	}

	if(!(testWindow.getYPosition() == 20))
	{
		std::cout << "> Wrong y position: " << testWindow.getYPosition() << std::endl;
		return 0;
	}

	return 1;
}

int testCreateWindow()
{
	GEWindow testWindow;

	// Criar uma janela de aplicação sem configurar os atributos da janela
	if(!testWindow.createWindow())
	{
		return 0;
	}

	// Criar uma segunda janela de aplicação com o mesmo nome de WindowClass
	// Deve apresentar um erro
	if(testWindow.createWindow())
	{
		return 0;
	}

	if(!testWindow.destroyWindow())
	{
		return 0;
	}

	return 1;
}

int testDestroyWindow()
{
	GEWindow testWindow;

	// Destruir uma janela de aplicação sem ter criado uma
	// Deve retornar um erro
	if(testWindow.destroyWindow())
	{
		return 0;
	}

	if(!testWindow.createWindow())
	{
		return 0;
	}

	// Destruir uma janela de aplicação após ter criado uma
	if(!testWindow.destroyWindow())
	{
		return 0;
	}

	return 1;
}

int isDone = 0;
GEApiWrapper *apiWrapperPtr;

void WindowTestEventHandler::finishAfterEvent()
{
	isDone = 1;
}

void WindowTestEventHandler::finishBeforeEvent()
{
	apiWrapperPtr->destroyWindow();
}


int testShowWindow()
{
	GEWindow testWindow;

	WindowTestEventHandler *windowTestEventHandler = new WindowTestEventHandler();
	testWindow.getApiWrapper()->setEventHandler(windowTestEventHandler);

	// Tentativa de exibir uma janela sem ter criada antes
	// Deve ocorrer um erro
	if(!testWindow.showWindow())
	{
		return 0;
	}

	testWindow.setName("TESTE SHOW WINDOW - 1");

	if(!testWindow.createWindow())
	{
		delete windowTestEventHandler;
		return 0;
	}

	testWindow.showWindow();
	apiWrapperPtr = testWindow.getApiWrapper();

	while(!isDone)
	{
		testWindow.getApiWrapper()->handleSystemMessages();
	}

	isDone = 0;
	testWindow.setName("TESTE SHOW WINDOW - 2");

	if(!testWindow.createWindow())
	{
		delete windowTestEventHandler;
		return 0;
	}

	testWindow.showWindow();

	while(!isDone)
	{
		testWindow.getApiWrapper()->handleSystemMessages();
	}

	delete windowTestEventHandler;
	return 1;
}