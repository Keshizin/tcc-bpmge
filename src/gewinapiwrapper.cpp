#include <gewinapiwrapper.h>
#include <iostream>

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

int GEWinApiWrapper::createWindow(int xPostion, int yPostion, int width, int height, std::string name)
{
	RECT windowSize;
	windowSize.left = (LONG)0;
	windowSize.right = (LONG)width;
	windowSize.top = (LONG)0;
	windowSize.bottom = (LONG)height;

	DWORD dwExStyle = WS_EX_APPWINDOW;
	DWORD dwStyle = WS_OVERLAPPEDWINDOW;

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
	int error = 1;

	ret = DestroyWindow(hWindow);

	if(ret == 0)
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to destroy a window application: " << error << "\n" << std::endl;
		return 0;
	}

	ret = UnregisterClass(LPCSTR(windowClassName.c_str()), GetModuleHandle(NULL));

	if(ret == 0)
	{
		DWORD error = GetLastError();
		std::cout << "(!) ERROR - It was not possible to unregister a class window: " << error << "\n" << std::endl;
		error = 0;
	}

	return error;
}

void GEWinApiWrapper::handleSystemMessages()
{
	MSG msg;

	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if(msg.message == WM_QUIT)
		{
			eventHandler->finishEvent();
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}





















int GEWinApiWrapper::initializeRenderingSystem()
{
	return 1;
}

int GEWinApiWrapper::showWindow()
{
	if(hWindow)
		ShowWindow(hWindow, SW_SHOW);

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
		// --------------------------------------------------------------------
		//    Application Messages
		// --------------------------------------------------------------------
		// case WM_QUIT:
		// 	break;

		// ----------------------------------------------------------------------
		//    Window Messages
		// ----------------------------------------------------------------------
		// case WM_CREATE:
		// 	break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_MOVE:
			break;

		case WM_SIZE:
			break;

		case WM_CLOSE:
			break;

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
