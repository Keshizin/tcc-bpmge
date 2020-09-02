#include <iostream>
#include <iomanip>

// #include "gewindowsystemtest.hpp"
// #include "geapiwrappertest.hpp"
// #include "geevthandlertest.hpp"
// #include "gerenderingsystemtest.hpp"

#define WIDTH 35
// #include "getest.hpp"

int main(int argc, char **argv)
{
	int ID = 0;
	
	std::cout
	<< "> Welcome to BPM Game Engine Unit Test\n"
		<< std::boolalpha << std::left
		<< "\n> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "Instanciando GEWindowSystem" << " | " << instanceGEWindowSystemTest()
		<< "\n> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "Instanciando GEApiWrapper" << " | " << instanceGEApiWrapperTest() << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "instance apiwrapper test " << " | " << static_cast<bool>(testInstanceApiWrapper()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "instance winapiwrapper test " << " | " << static_cast<bool>(testInstanceWinApiWrapper()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "winapiwrapper polymorphism test " << " | " << static_cast<bool>(testApiWrapperPoly()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "create window test " << " | " << static_cast<bool>(testCreateWindow()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "destroy window test " << " | " << static_cast<bool>(testDestroyWindow()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "show window test " << " | " << static_cast<bool>(testShowWindow()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "user envent handler test " << " | " << static_cast<bool>(testUserEventHandler()) << std::endl;
	// // std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "mouse event test " << " | " << static_cast<bool>(testMouseEvent()) << std::endl;
	// // std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "keyboard event test " << " | " << static_cast<bool>(testKeyboardEvent()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "instance rendering system test " << " | " << static_cast<bool>(testInstanceRenderingSystem()) << std::endl;
	// std::cout << "> ID #" << std::setw(2) << ++ID << " | " << std::setw(WIDTH) << "rendering system test " << " | " << static_cast<bool>(testRenderingSystem()) << std::endl;


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