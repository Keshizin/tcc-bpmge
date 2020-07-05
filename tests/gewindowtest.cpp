#include "gewindowtest.hpp"

#include <iostream>
#include <gewindowsystem.h>
#include <gewinapiwrapper.h>

int testInstanceWindow()
{
	GEWindowSystem windowSystem;
	GEApiWrapper apiWrapper;

	if(!windowSystem.getName().empty())
		return 0;

	if(windowSystem.getWidth() != 640)
		return 0;

	if(windowSystem.getHeight() != 480)
		return 0;

	if(windowSystem.getX() != 0)
		return 0;

	if(windowSystem.getY() != 0)
		return 0;

	if(windowSystem.getStyle() != GE_WIN_DEFAULT)
		return 0;

	if(windowSystem.getApiWrapper() != 0)
		return 0;

	// Setting new values
	windowSystem.setName("WINDOW SYSTEM TEST #1");
	windowSystem.setWidth(1920);
	windowSystem.setHeight(1080);
	windowSystem.setX(10);
	windowSystem.setY(15);
	windowSystem.setStyle(GE_WIN_COMPLETE);
	windowSystem.setApiWrapper(&apiWrapper);

	if(windowSystem.getName() != "WINDOW SYSTEM TEST #1")
		return 0;

	if(windowSystem.getWidth() != 1920)
		return 0;

	if(windowSystem.getHeight() != 1080)
		return 0;

	if(windowSystem.getX() != 10)
		return 0;

	if(windowSystem.getY() != 15)
		return 0;

	if(windowSystem.getStyle() != GE_WIN_COMPLETE)
		return 0;

	if(windowSystem.getApiWrapper() != &apiWrapper)
		return 0;

	return 1;
}

int testCreateWindow()
{
	GEEventHandler eventHandler;
	GEWinApiWrapper winApiWrapper;
	winApiWrapper.setGlobalEventHandler(&eventHandler);
	GEWindowSystem windowSystem(&winApiWrapper);

	// Vai retornar erro porque apiWrapper não foi configurada
	// if(windowSystem.createWindow() != 0)
	// 	return 0;

	if(!windowSystem.createWindow())
		return 0;

	// Vai retornar ao tentar criar uma segunda com o mesmo nome de WindowClass
	// if(windowSystem.createWindow())
	// 	return 0;

	if(!windowSystem.destroyWindow())
		return 0;

	return 1;
}

int testDestroyWindow()
{
	GEWindowSystem windowSystem;

	// Destruir uma janela de aplicação sem ter criado uma
	// if(windowSystem.destroyWindow())
	// {
	// 	return 0;
	// }

	GEEventHandler eventHandler;
	GEWinApiWrapper winApiWrapper;
	winApiWrapper.setGlobalEventHandler(&eventHandler);
	windowSystem.setApiWrapper(&winApiWrapper);

	if(!windowSystem.createWindow())
	{
		return 0;
	}

	if(!windowSystem.destroyWindow())
	{
		return 0;
	}

	return 1;
}

int testShowWindow()
{
	GEEventHandler eventHandler;
	GEWinApiWrapper winApiWrapper;
	winApiWrapper.setGlobalEventHandler(&eventHandler);
	GEWindowSystem windowSystem(&winApiWrapper);

	if(windowSystem.showWindow())
		return 0;

	if(!windowSystem.createWindow())
		return 0;

	if(!windowSystem.showWindow())
		return 0;

	if(!windowSystem.showWindow())
		return 0;

	if(!windowSystem.destroyWindow())
		return 0;

	if(windowSystem.showWindow())
		return 0;

	return 1;
}