#include <iostream>
#include <string>

#include "gewindowtest.hpp"
#include "geevthandlertest.hpp"

int main(int argc, char **argv)
{
	std::string projectName = "BPM Game Engine";

	std::cout << "Teste de Unidade para " << projectName << "\n" << std::endl;

	if(testWindow())
		std::cout << "> TESTE | GEWindow Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> TESTE | GEWindow Class | FAIL\n" << std::endl;

	// EVENT HANDLER TEST
	if(eventHandlerTest())
		std::cout << "> TESTE | EVENT HANDLER | SUCCESS\n" << std::endl;
	else
		std::cout << "> TESTE | EVENT HANDLER | FAIL\n" << std::endl;

	return 0;
}