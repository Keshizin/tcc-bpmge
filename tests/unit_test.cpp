#include <iostream>
#include <string>

#include "gewindowtest.hpp"
#include "geapiwrappertest.hpp"
#include "geevthandlertest.hpp"
#include "gerenderingsystemtest.hpp"
#include "getest.hpp"

int main(int argc, char **argv)
{
	std::string projectName = "BPM Game Engine";
	std::cout << "Teste de Unidade para " << projectName << std::endl;

	// Case test #1 | Instanciar um objeto da classe GEWindow e configurar todos os seus atributos.
	if(testInstanceWindow())
		std::cout << "> CASE #1 | GEWindow Class: SUCCESS" << std::endl;
	else
		std::cout << "> CASE #1 | GEWindow Class: FAIL" << std::endl;

	// Case test #2 | Criar uma janela de aplicação
	if(testCreateWindow())
		std::cout << "> CASE #2 | GEWindow Class: SUCCESS" << std::endl;
	else
		std::cout << "> CASE #2 | GEWindow Class: FAIL" << std::endl;

	// Case test #3 | Destruir uma janela de aplicação
	if(testDestroyWindow())
		std::cout << "> CASE #3 | GEWindow Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #3 | GEWindow Class: FAIL\n" << std::endl;

	// Case teste #4 | Handles Microsoft Windows Messages
	if(testWinApiWrapper())
		std::cout << "> CASE #4 | GEApiWrapper: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #4 | GEApiWrapper: FAIL\n" << std::endl;

	// Case test #5 | Exibir uma janela de aplicação na tela
	if(testShowWindow())
		std::cout << "> CASE #5 | GEWindow Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #5 | GEWindow Class: FAIL\n" << std::endl;

	// Case test #6 | Testar todos os estilos de janela disponíveis
	if(testWindowStyles())
		std::cout << "> CASE #6 | GEWindow Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #6 | GEWindow Class: FAIL\n" << std::endl;

	// Case test #7 | Definir funções de eventos globais
	if(eventHandlerTest())
		std::cout << "> CASE #7 | GEEventHandler Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #7 | GEEventHandler Class: FAIL\n" << std::endl;

	// Case test #8 | Capturar eventos de mouse
	if(testWinMouseEvent())
		std::cout << "> CASE #8 | GEApiWrapper Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #8 | GEApiWrapper Class: FAIL\n" << std::endl;

	// Case test #9 | Capturar eventos do teclado
	if(testWinKeyboardEvent())
		std::cout << "> CASE #9 | GEApiWrapper Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #9 | GEApiWrapper Class: FAIL\n" << std::endl;

	// Case test #10 | Inicializar o sistema de renderização
	if(testRenderingSystem())
		std::cout << "> CASE #10 | GERenderingSystem Class: SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #10 | GERenderingSystem Class: FAIL\n" << std::endl;

	// Case test #11 | Instanciar um objeto Game Engine
	if(testInstanceGameEngine())
		std::cout << "> CASE #11 | GameEngine Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #11 | GameEngine Class | FAIL\n" << std::endl;

	// Case test #12 | Iniciar o loop principal da Game Engine
	if(testMainLoop())
		std::cout << "> CASE #12 | GameEngine Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #12 | GameEngine Class | FAIL\n" << std::endl;

	// Case test #13 | Teste da classe TimeHandler
	if(testTimeHandler())
		std::cout << "> CASE #13 | TimeHandler Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #13 | TimeHandler Class | FAIL\n" << std::endl;

	// Case test #14 | Teste do timer
	if(testTimer())
		std::cout << "> CASE #14 | Timer Class | SUCCESS\n" << std::endl;
	else
		std::cout << "> CASE #14 | Timer Class | FAIL\n" << std::endl;

	std::cout << "> (!) FIM DOS TESTES" << std::endl;
	return 0;
}