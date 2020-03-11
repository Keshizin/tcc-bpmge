#include <iostream>
#include <string>

#include <gewindow.h>

int testWindow();

int main(int argc, char **argv)
{
	std::string projectName = "BPM Game Engine";

	std::cout << "Teste de Unidade para " << projectName << "\n" << std::endl;

	if(testWindow())
		std::cout << "> TESTE | GEWindow Class | SUCCESS" << std::endl;
	else
		std::cout << "> TESTE | GEWindow Class | FAIL" << std::endl;

	return 0;
}

int testWindow()
{
	GEWindow test;

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

	return 1;
}