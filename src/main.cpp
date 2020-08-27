/*
	Game Engine Template

	This file provide a template for a game created with BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/
#include <windows.h>
#include <iostream>

// ----------------------------------------------------------------------------
//  MAIN APPLICATION
// ----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::cout << "> HELLO BPM Game Engine" << std::endl;

	#ifdef GEDEBUG
	std::cout << "(!) DEBUG MODE ACTIVATED" << std::endl;
	#endif

	// START UP GAME ENGINE

	// SETTING UP WINDOW GAME

	// STARTING GAME LOOP

	// RELEASE GAME ENGINE

	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}