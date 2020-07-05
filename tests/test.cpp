#include <iostream>
#include <iomanip>

#include "gewindowtest.hpp"
#include "geapiwrappertest.hpp"
#include "geevthandlertest.hpp"
#include "gerenderingsystemtest.hpp"

#define SETW_N 35
// #include "getest.hpp"

int main(int argc, char **argv)
{
	std::cout << "> Welcome to BPM Game Engine Unit Test\n" << std::endl;

	int ID = 0;
	std::cout << std::boolalpha << std::left;

	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "instance window test " << " | " << static_cast<bool>(testInstanceWindow()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "instance apiwrapper test " << " | " << static_cast<bool>(testInstanceApiWrapper()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "instance winapiwrapper test " << " | " << static_cast<bool>(testInstanceWinApiWrapper()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "winapiwrapper polymorphism test " << " | " << static_cast<bool>(testApiWrapperPoly()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "create window test " << " | " << static_cast<bool>(testCreateWindow()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "destroy window test " << " | " << static_cast<bool>(testDestroyWindow()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "show window test " << " | " << static_cast<bool>(testShowWindow()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "user envent handler test " << " | " << static_cast<bool>(testUserEventHandler()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "mouse event test " << " | " << static_cast<bool>(testMouseEvent()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "keyboard event test " << " | " << static_cast<bool>(testKeyboardEvent()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "instance rendering system test " << " | " << static_cast<bool>(testInstanceRenderingSystem()) << std::endl;
	std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(SETW_N) << "rendering system test " << " | " << static_cast<bool>(testRenderingSystem()) << std::endl;


	// // Case test #11 | Instanciar um objeto Game Engine
	// if(testInstanceGameEngine())
	// 	std::cout << "> CASE #11 | GameEngine Class | SUCCESS\n" << std::endl;
	// else
	// 	std::cout << "> CASE #11 | GameEngine Class | FAIL\n" << std::endl;

	// // Case test #12 | Iniciar o loop principal da Game Engine
	// if(testMainLoop())
	// 	std::cout << "> CASE #12 | GameEngine Class | SUCCESS\n" << std::endl;
	// else
	// 	std::cout << "> CASE #12 | GameEngine Class | FAIL\n" << std::endl;

	// // Case test #13 | Teste da classe TimeHandler
	// if(testTimeHandler())
	// 	std::cout << "> CASE #13 | TimeHandler Class | SUCCESS\n" << std::endl;
	// else
	// 	std::cout << "> CASE #13 | TimeHandler Class | FAIL\n" << std::endl;

	// // Case test #14 | Teste do timer
	// if(testTimer())
	// 	std::cout << "> CASE #14 | Timer Class | SUCCESS\n" << std::endl;
	// else
	// 	std::cout << "> CASE #14 | Timer Class | FAIL\n" << std::endl;

	// // Case test #15 | Teste do timer
	// if(testDiag())
	// 	std::cout << "> CASE #15 | Timer Diag | SUCCESS\n" << std::endl;
	// else
	// 	std::cout << "> CASE #15 | Timer Diag | FAIL\n" << std::endl;

	// std::cout << "> (!) FIM DOS TESTES" << std::endl;
	return 0;
}