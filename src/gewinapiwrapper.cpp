#include <gewinapiwrapper.h>
#include <iostream>

int GEWinApiWrapper::initializeWindow()
{
	WNDCLASSEX windowClass;

	if(windowClassName.empty())
		windowClassName = "customwindowclass";

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
		std::cout << "(!) Nao foi possivel registrar uma Window Class: " << error << "\n" << std::endl;
		return 0;
	}

	return 1;
}

int GEWinApiWrapper::initializeRenderingSystem()
{
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
		return 0;
}

int GEWinApiWrapper::destroyWindow()
{
	BOOL ret = DestroyWindow(hWindow);

	if(ret == 0)
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) Nao foi possivel destruir a janela: " << error << "\n" << std::endl;
		return 0;
	}

	ret = UnregisterClass(LPCSTR(windowClassName.c_str()), GetModuleHandle(NULL));

	if(ret == 0)
	{
		// (!) Gravar o erro no componente de LOG
		DWORD error = GetLastError();
		std::cout << "(!) Nao foi possivel desregistrar a janela: " << error << "\n" << std::endl;
		return 0;
	}

	return 1;
}

int GEWinApiWrapper::showWindow()
{
	if(hWindow)
		ShowWindow(hWindow, SW_SHOW);

	return 1;
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
	return DefWindowProc(hWnd, uMsg, wParam, lParam);	
}
