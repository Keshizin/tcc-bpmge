#include <iostream>

#include <gewinapiwrapper.h>
#include <gewindow.h>

// #include <GL/gl.h>



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

int GEWinApiWrapper::initializeWindow()
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
	windowClass.lpszClassName = LPCSTR(windowClassName.c_str());

	if(!RegisterClassEx(&windowClass))
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to register a class window: " << error << "\n" << std::endl;
		return 0;
	}

	return 1;
}

int GEWinApiWrapper::createWindow(int xPostion, int yPostion, int width, int height, std::string name, unsigned int style) 
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
		LPCSTR(windowClassName.c_str()),
		LPCSTR(name.c_str()),
		dwStyle,
		xPostion,
		yPostion,
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

		int ret = UnregisterClass(LPCSTR(windowClassName.c_str()), GetModuleHandle(NULL));

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

	// ret = wglMakeCurrent(NULL, NULL);

	// if(ret == FALSE)
	// {
	// 	DWORD error = GetLastError();
	// 	std::cout << "(!) ERROR - It was not possible to release the rendering context: " << error << "\n" << std::endl;
	// 	error = 0;
	// }

	// ret = wglDeleteContext(hRC);

	// if(ret == FALSE)
	// {
	// 	DWORD error = GetLastError();
	// 	std::cout << "(!) ERROR - It was not possible to delete the rendering context: " << error << "\n" << std::endl;
	// 	error = 0;
	// }

	// ret = ReleaseDC(hWindow, hDC);

	// if(!ret)
	// {
	// 	DWORD error = GetLastError();
	// 	std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
	// 	error = 0;
	// }

	ret = DestroyWindow(hWindow);

	if(ret == 0)
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to destroy a window application: " << error << "\n" << std::endl;
		err = 0;
	}

	ret = UnregisterClass(LPCSTR(windowClassName.c_str()), GetModuleHandle(NULL));

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

	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if(msg.message == WM_QUIT)
		{
			eventHandler->finishAfterEvent();
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

// int GEWinApiWrapper::initializeRenderingSystem(GERenderingSystem *renderingSystem)
// {
// 	int ret;
// 	DWORD dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;

// 	static PIXELFORMATDESCRIPTOR pfd =
// 	{
// 		sizeof(PIXELFORMATDESCRIPTOR),
// 		1,
// 		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
// 		PFD_TYPE_RGBA,
// 		32, // cColorBits
// 		0, // cRedBits
// 		0, // cRedShift
// 		0, // cGreenBits
// 		0, // cGreenShift
// 		0, // cBlueBits
// 		0, // cBlueShift
// 		0, // cAlphaBits
// 		0, // cAlphaShift
// 		0, // cAccumBits
// 		0, // cAccumRedBits
// 		0, // cAccumGreenBits
// 		0, // cAccumBlueBits
// 		0, // cAccumAlphaBits
// 		32, // cDepthBits
// 		0, // cStencilBits
// 		0, // cAuxBuffers
// 		PFD_MAIN_PLANE, // iLayerType
// 		0, // bReserved
// 		0, // dwLayerMask
// 		0, // dwVisibleMask
// 		0 // dwDamageMask
// 	};

// 	hDC = GetDC(hWindow);

// 	if(hDC == NULL)
// 	{
// 		DWORD error = GetLastError();
// 		std::cout << "(!) ERROR - It was not possible to get device context: " << error << "\n" << std::endl;
// 		return 0;
// 	}

// 	GLuint PixelFormat = ChoosePixelFormat(hDC, &pfd);

// 	if(!PixelFormat)
// 	{
// 		DWORD error = GetLastError();
// 		std::cout << "(!) ERROR - It was not possible to choose an pixel format: " << error << "\n" << std::endl;

// 		ret = ReleaseDC(hWindow, hDC);

// 		if(!ret)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
// 		}

// 		ret = DestroyWindow(hWindow);

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
// 		}

// 		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
// 		}

// 		return 0;
// 	}

// 	ret = SetPixelFormat(hDC, PixelFormat, &pfd);

// 	if(ret == FALSE)
// 	{
// 		DWORD error = GetLastError();
// 		std::cout << "(!) ERROR - It was not possible to set the format pixel: " << error << "\n" << std::endl;

// 		ret = ReleaseDC(hWindow, hDC);

// 		if(!ret)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
// 		}

// 		ret = DestroyWindow(hWindow);

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
// 		}

// 		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
// 		}

// 		return 0;
// 	}

// 	hRC = wglCreateContext(hDC);

// 	if(hRC == NULL)
// 	{
// 		DWORD error = GetLastError();
// 		std::cout << "(!) ERROR - It was not possible to create the rendering context: " << error << "\n" << std::endl;

// 		ret = ReleaseDC(hWindow, hDC);

// 		if(!ret)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
// 		}

// 		ret = DestroyWindow(hWindow);

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
// 		}

// 		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
// 		}

// 		return 0;
// 	}

// 	ret = wglMakeCurrent(hDC, hRC);

// 	if(ret == FALSE)
// 	{
// 		DWORD error = GetLastError();
// 		std::cout << "(!) ERROR - It was not possible to make current the rendering context: " << error << "\n" << std::endl;

// 		ret = wglDeleteContext(hRC);

// 		if(ret == FALSE)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to delete the rendering context: " << error << "\n" << std::endl;
// 		}

// 		ret = ReleaseDC(hWindow, hDC);

// 		if(!ret)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to release the device context: " << error << "\n" << std::endl;
// 		}

// 		ret = DestroyWindow(hWindow);

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to destroy the window: " << error << "\n" << std::endl;
// 		}

// 		ret = UnregisterClass(LPCSTR("GLWNDCLASS"), GetModuleHandle(NULL));

// 		if(ret == 0)
// 		{
// 			DWORD error = GetLastError();
// 			std::cout << "(!) ERROR - It was not possible to unregister the window class: " << error << "\n" << std::endl;
// 		}

// 		return 0;
// 	}

// 	return 1;
// }

// int GEWinApiWrapper::swapBuffers()
// {
// 	BOOL ret = SwapBuffers(hDC);

// 	if(ret == TRUE)
// 		return 1;
// 	else
// 	{
// 		DWORD error = GetLastError();
// 		std::cout << "(!) ERROR - It was not possible to swap the buffers: " << error << "\n" << std::endl;
// 		return 0;
// 	}
// }

void GEWinApiWrapper::setWindowClassName(std::string windowClassName)
{
	this->windowClassName = windowClassName;
}

std::string GEWinApiWrapper::getWindowClassName()
{
	return windowClassName;
}

LRESULT CALLBACK GEWinApiWrapper::windowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		// ----------------------------------------------------------------------
		//    WINDOW MESSAGES
		// ----------------------------------------------------------------------
		case WM_CREATE:
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_MOVE:
			break;

		case WM_SIZE:
			eventHandler->resizeWindowEvent(LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_CLOSE:
			eventHandler->finishBeforeEvent();
			break;

		// case WM_ACTIVATE:
		// 	break;

		// case WM_SHOWWINDOW:
		// 	break;

		// ----------------------------------------------------------------------
		//    Mouse Messages
		// ----------------------------------------------------------------------
		case WM_LBUTTONDOWN:
			eventHandler->mouseEvent(0, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_LBUTTONUP:
			eventHandler->mouseEvent(0, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MBUTTONDOWN:
			eventHandler->mouseEvent(1, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MBUTTONUP:
			eventHandler->mouseEvent(1, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_RBUTTONDOWN:
			eventHandler->mouseEvent(2, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_RBUTTONUP:
			eventHandler->mouseEvent(2, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MOUSEMOVE:
			eventHandler->mouseMotionEvent(LOWORD(lParam), HIWORD(lParam));
			break;

		// ----------------------------------------------------------------------
		//    Keyboard Messages
		// ----------------------------------------------------------------------
		case WM_SYSKEYDOWN:
			eventHandler->keyboardSpecialEvent(wParam, 1);
			break;

		case WM_SYSKEYUP:
			eventHandler->keyboardSpecialEvent(wParam, 0);
			break;

		case WM_KEYDOWN:
			eventHandler->keyboardEvent(wParam, 1);
			break;

		case WM_KEYUP:
			eventHandler->keyboardEvent(wParam, 0);
			break;

		default:
			break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);	
}