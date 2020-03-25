#include <gewinapiwrapper.h>

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
		DWORD error = GetLastError();
		//std::cout << "(!) Nao foi possivel registrar uma Window Class: " << error << "\n" << std::endl;
		return 0;
	}

	return 1;
}

int GEWinApiWrapper::initializeRenderingSystem()
{
	return 1;
}

int GEWinApiWrapper::createWindow(int width, int height, std::string name)
{
	return 1;
}

int GEWinApiWrapper::destroyWindow()
{
	return 1;
}

int GEWinApiWrapper::showWindow()
{
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
