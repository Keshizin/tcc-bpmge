/*
	Game Engine Win32 API Wrapper
	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <iostream>

#include <gewinapiwrapper.h>
#include <gewindowsystem.h>

#include <GL/gl.h>
#include <GLEXT/wglext.h>

#define WINDOWCLASSNAME LPCSTR("GEWINDOWCLASS")

// ----------------------------------------------------------------------------
//  Global definitions
// ----------------------------------------------------------------------------
GEEventHandler *globalEventHandler = 0;

// ----------------------------------------------------------------------------
//  GEWinApiWrapper constructors and destructors
// ----------------------------------------------------------------------------
GEWinApiWrapper::GEWinApiWrapper()
{
	hWindow = NULL;
	hDC = NULL;
	hRC = NULL;
}

GEWinApiWrapper::~GEWinApiWrapper()
{
	globalEventHandler = 0;
}

// ----------------------------------------------------------------------------
//  GEWinApiWrapper methdos definition
// ----------------------------------------------------------------------------
unsigned long long GEWinApiWrapper::getHighResolutionTimerCounter()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return time.QuadPart;
}

unsigned long long GEWinApiWrapper::getHighResolutionTimerFrequency()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return frequency.QuadPart;
}

int GEWinApiWrapper::registerWindow()
{
	WNDCLASSEX windowClass;

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_DBLCLKS | CS_HREDRAW | CS_OWNDC | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
	// windowClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SKELETON));
	// windowClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SKELETON_SM)); 
	windowClass.hIcon = 0;
	windowClass.hIconSm = 0;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = 0;
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = WINDOWCLASSNAME;

	if(!RegisterClassEx(&windowClass))
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to register a class window: " << error << "\n" << std::endl;
		return 0;
	}

	return 1;
}

int GEWinApiWrapper::createWindow(int x, int y, int width, int height, std::string name, unsigned int style) 
{
	RECT windowSize;
	windowSize.left = (LONG)0;
	windowSize.right = (LONG)width;
	windowSize.top = (LONG)0;
	windowSize.bottom = (LONG)height;

	DWORD dwExStyle = WS_EX_APPWINDOW;
	DWORD dwStyle = 0;

	switch(style)
	{
		case GE_WIN_SPLASH:
			dwStyle = WS_POPUP | WS_BORDER;
			break;

		case GE_WIN_DEFAULT_NO_SYS:
			dwStyle = WS_POPUP | WS_BORDER | WS_CAPTION;
			break;

		case GE_WIN_WINDOWED_FULLSCREEN:
			dwStyle = WS_POPUP | WS_BORDER | WS_MAXIMIZE;
			break;

		case GE_WIN_COMPLETE:
			dwStyle = WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX;
			break;

		case GE_WIN_DEFAULT:
		default:
			dwStyle = WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU;
			break;
	}

	AdjustWindowRectEx(&windowSize, dwStyle, FALSE, dwExStyle);

	hWindow = CreateWindowEx(
		dwExStyle,
		LPCSTR("GEWINDOWCLASS"),
		LPCSTR(name.c_str()),
		dwStyle,
		x,
		y,
		windowSize.right - windowSize.left,
		windowSize.bottom - windowSize.top,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);

	if(hWindow != NULL)
		return 1;
	else
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to create the window: " << error << "\n" << std::endl;

		int ret = UnregisterClass(WINDOWCLASSNAME, GetModuleHandle(NULL));

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to unregister a class window: " << error << "\n" << std::endl;
		}

		return 0;
	}
}

int GEWinApiWrapper::destroyWindow()
{
	int ret;
	int err = 1;

	if(hRC != NULL)
	{
		ret = wglMakeCurrent(NULL, NULL);

		if(ret == FALSE)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to release the rendering context: " << error << "\n" << std::endl;
			error = 0;
		}

		ret = wglDeleteContext(hRC);

		if(ret == FALSE)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to delete the rendering context: " << error << "\n" << std::endl;
			error = 0;
		}

		hRC = NULL;
	}

	if(hDC != NULL)
	{
		ret = ReleaseDC(hWindow, hDC);

		if(!ret)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
			error = 0;
		}

		hDC = NULL;
	}

	ret = DestroyWindow(hWindow);

	if(ret == 0)
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to destroy a window application: " << error << "\n" << std::endl;
		err = 0;
	}

	hWindow = NULL;

	ret = UnregisterClass(WINDOWCLASSNAME, GetModuleHandle(NULL));

	if(ret == 0)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to unregister a class window: " << error << "\n" << std::endl;
		err = 0;
	}

	return err;
}

int GEWinApiWrapper::showWindow()
{
	if(hWindow)
	{
		ShowWindow(hWindow, SW_SHOW);
		return 1;
	}

	return 0;
}

void GEWinApiWrapper::handleSystemMessages()
{
	MSG msg;

	#ifdef GEDEBUG
	if(!globalEventHandler)
	{
		std::cout << "(!) ERROR | GEWinApiWrapper::handleSystemMessages() | global event handler not configured!" << std::endl;
		exit(1);
	}
	#endif

	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if(msg.message == WM_QUIT)
		{
			globalEventHandler->finishAfterEvent();
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void GEWinApiWrapper::setGlobalEventHandler(GEEventHandler *eventHandler)
{
	globalEventHandler = eventHandler;
}

int GEWinApiWrapper::initializeRenderingSystem()
{
	int ret;

	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32, // cColorBits
		0, // cRedBits
		0, // cRedShift
		0, // cGreenBits
		0, // cGreenShift
		0, // cBlueBits
		0, // cBlueShift
		0, // cAlphaBits
		0, // cAlphaShift
		0, // cAccumBits
		0, // cAccumRedBits
		0, // cAccumGreenBits
		0, // cAccumBlueBits
		0, // cAccumAlphaBits
		32, // cDepthBits
		0, // cStencilBits
		0, // cAuxBuffers
		PFD_MAIN_PLANE, // iLayerType
		0, // bReserved
		0, // dwLayerMask
		0, // dwVisibleMask
		0 // dwDamageMask
	};

	hDC = GetDC(hWindow);

	if(hDC == NULL)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to get device context: " << error << "\n" << std::endl;
		return 0;
	}

	GLuint PixelFormat = ChoosePixelFormat(hDC, &pfd);

	if(!PixelFormat)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to choose an pixel format: " << error << "\n" << std::endl;

		ret = ReleaseDC(hWindow, hDC);

		if(!ret)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
		}

		ret = DestroyWindow(hWindow);

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
		}

		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
		}

		return 0;
	}

	ret = SetPixelFormat(hDC, PixelFormat, &pfd);

	if(ret == FALSE)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to set the format pixel: " << error << "\n" << std::endl;

		ret = ReleaseDC(hWindow, hDC);

		if(!ret)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
		}

		ret = DestroyWindow(hWindow);

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
		}

		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
		}

		return 0;
	}

	hRC = wglCreateContext(hDC);

	if(hRC == NULL)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to create the rendering context: " << error << "\n" << std::endl;

		ret = ReleaseDC(hWindow, hDC);

		if(!ret)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
		}

		ret = DestroyWindow(hWindow);

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
		}

		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
		}

		return 0;
	}

	ret = wglMakeCurrent(hDC, hRC);

	if(ret == FALSE)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to make current the rendering context: " << error << "\n" << std::endl;

		ret = wglDeleteContext(hRC);

		if(ret == FALSE)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to delete the rendering context: " << error << "\n" << std::endl;
		}

		ret = ReleaseDC(hWindow, hDC);

		if(!ret)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
		}

		ret = DestroyWindow(hWindow);

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
		}

		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

		if(ret == 0)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
		}

		return 0;
	}

	return 1;
}

int GEWinApiWrapper::swapBuffers()
{
	if(hDC)
	{
		BOOL ret = SwapBuffers(hDC);

		if(ret != TRUE)
		{
			DWORD error = GetLastError();
			std::cout << "(!) ERROR - It was not possible to swap the buffers: " << error << "\n" << std::endl;
			return 0;
		}

		return 1;
	}
	
	return 0;
}

int GEWinApiWrapper::setVSync(int vsync)
{
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) wglGetProcAddress("wglSwapIntervalEXT");

	if (wglSwapIntervalEXT)
	{
	    wglSwapIntervalEXT(vsync);
		return 1;
	}
	else
		return 0;
}

// ----------------------------------------------------------------------------
//  GLOBAL FUNCTIONS DEFINITION
// ----------------------------------------------------------------------------
LRESULT CALLBACK windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	#ifdef GEDEBUG
	if(!globalEventHandler)
	{
		std::cout << "(!) ERROR | windowProcedure() | global event handler is not configured!" << std::endl;
		exit(1);
	}
	#endif

	switch(uMsg)
	{
		// ********************************************************************
		//  WINDOW MESSAGES
		// ********************************************************************
		case WM_CREATE:
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_MOVE:
			break;

		case WM_SIZE:
			globalEventHandler->resizeWindowEvent(LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_CLOSE:
			globalEventHandler->finishBeforeEvent();
			break;

		case WM_ACTIVATE:
			if(wParam == WA_ACTIVE)
				globalEventHandler->resumeEvent();
			else if(wParam == WA_CLICKACTIVE)
				globalEventHandler->resumeEvent();
			else if(wParam == WA_INACTIVE)
				globalEventHandler->pauseEvent();

			break;

		case WM_SHOWWINDOW:
			break;

		// ********************************************************************
		//  MOUSE MESSAGES
		// ********************************************************************
		case WM_LBUTTONDOWN:
			globalEventHandler->mouseEvent(0, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_LBUTTONUP:
			globalEventHandler->mouseEvent(0, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MBUTTONDOWN:
			globalEventHandler->mouseEvent(1, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MBUTTONUP:
			globalEventHandler->mouseEvent(1, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_RBUTTONDOWN:
			globalEventHandler->mouseEvent(2, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_RBUTTONUP:
			globalEventHandler->mouseEvent(2, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MOUSEMOVE:
			globalEventHandler->mouseMotionEvent(LOWORD(lParam), HIWORD(lParam));
			break;

		// ********************************************************************
		//  KEYBOARD MESSAGES
		// ********************************************************************
		case WM_SYSKEYDOWN:
			globalEventHandler->keyboardSpecialEvent(wParam, 1);
			break;

		case WM_SYSKEYUP:
			globalEventHandler->keyboardSpecialEvent(wParam, 0);
			break;

		case WM_KEYDOWN:
			globalEventHandler->keyboardEvent(wParam, 1);
			break;

		case WM_KEYUP:
			globalEventHandler->keyboardEvent(wParam, 0);
			break;

		default:
			break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);	
}