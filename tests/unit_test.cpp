#include <iostream>
#include <string>

#include "gewindowtest.hpp"
#include "geevthandlertest.hpp"

int main(int argc, char **argv)
{
	std::string projectName = "BPM Game Engine";

	std::cout << "Teste de Unidade para " << projectName << "\n" << std::endl;

	// Case test #1 | Instanciar um objeto da classe GEWindow
	if(testInstanceWindow())
		std::cout << "> CASE #1 | GEWindow Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #1 | GEWindow Class | FAIL\n" << std::endl;

	// Case test #2 | Criar uma janela de aplicação (Windows) com um objeto da classe GEWindow
	if(testCreateWindow())
		std::cout << "> CASE #2 | GEWindow Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #2 | GEWindow Class | FAIL\n" << std::endl;

	// EVENT HANDLER TEST
	if(eventHandlerTest())
		std::cout << "> TESTE | EVENT HANDLER | SUCCESS\n" << std::endl;
	else
		std::cout << "> TESTE | EVENT HANDLER | FAIL\n" << std::endl;

	return 0;
}