#include <gewinapiwrapper.h>
#include <iostream>
#include <gewindow.h>

int GEWinApiWrapper::initializeWindow()
{
	WNDCLASSEX windowClass;

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_DBLCLKS | CS_HREDRAW | CS_OWNDC | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hIcon = 0;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = 0;
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = LPCSTR(windowClassName.c_str());
	windowClass.hIconSm = 0;

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

int GEWinApiWrapper::showWindow()
{
	if(hWindow)
	{
		ShowWindow(hWindow, SW_SHOW);
		return 1;
	}

	return 0;
}





















int GEWinApiWrapper::initializeRenderingSystem()
{
	return 1;
}

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

		// case WM_LBUTTONDBLCLK:
		// case WM_NCLBUTTONDOWN:
		// case WM_NCLBUTTONUP:
		// case WM_NCLBUTTONDBLCLK:
		// 	break;

		case WM_MBUTTONDOWN:
			eventHandler->mouseEvent(1, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_MBUTTONUP:
			eventHandler->mouseEvent(1, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		// case WM_MBUTTONDBLCLK:
		// case WM_NCMBUTTONDOWN:
		// case WM_NCMBUTTONUP:
		// case WM_NCMBUTTONDBLCLK:
		// 	break;

		case WM_RBUTTONDOWN:
			eventHandler->mouseEvent(1, 1, LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_RBUTTONUP:
			eventHandler->mouseEvent(1, 0, LOWORD(lParam), HIWORD(lParam));
			break;

		// case WM_RBUTTONDBLCLK:
		// case WM_NCRBUTTONDOWN:
		// case WM_NCRBUTTONUP:
		// case WM_NCRBUTTONDBLCLK:
		// 	break;

		case WM_MOUSEMOVE:
			eventHandler->mouseMotionEvent(LOWORD(lParam), HIWORD(lParam));
			break;

		// case WM_MOUSEHOVER:
		// case WM_NCMOUSEHOVER:
		// case WM_MOUSELEAVE:
		// case WM_NCMOUSELEAVE:
		// case WM_MOUSEWHEEL:
		// case WM_MOUSEACTIVATE:
		// 	break;

		default:
			break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);	
}
