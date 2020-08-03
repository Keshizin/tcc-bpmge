/*
	Game Engine Template

	This file provide a template for a game created with BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#include <windows.h>
#include <iostream>

#include <ge.h>
#include <gemath.h>
#include <GL/wglext.h>

#include <gejniwrapper.h>

// ----------------------------------------------------------------------------
//  SYMBOLIC CONSTANTS
// ----------------------------------------------------------------------------
#define GAME_SCREEN_WIDTH  1920
#define GAME_SCREEN_HEIGHT 1080
#define GAME_SPLASH_WIDTH  640
#define GAME_SPLASH_HEIGHT 480

// ----------------------------------------------------------------------------
//  GLOBAL DEFINITION
// ----------------------------------------------------------------------------
GameEngine *gameEngine = 0;

class UserEventHandler : public GEEventHandler
{
	void frameEvent();
	void mouseEvent(int button, int state, int x, int y);
	void mouseMotionEvent(int x, int y);
	void keyboardEvent(unsigned char key, int state);
	void resizeWindowEvent(int width, int height);
	void finishAfterEvent();
	void finishBeforeEvent();
	void resumeEvent();
	void pauseEvent();
	void beforeMainLoopEvent();
};

#define X .525731112119133606
#define Z .850650808352039932

GLfloat vdata[12][3] = {
   { -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z },
   { 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X },
   { Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 }
};

GLuint tindices[20][3] = {
   { 1, 4, 0 }, { 4, 9, 0 }, { 4, 5, 9 }, { 8, 5, 4 }, { 1, 8, 4 },
   { 1, 10, 8 }, { 10, 3, 8 }, { 8, 3, 5 }, { 3, 2, 5 }, { 3, 7, 2 },
   { 3, 10, 7 }, { 10, 6, 7 }, { 6, 11, 7 }, { 6, 0, 11 }, { 6, 1, 0 },
   { 10, 1, 6 }, { 11, 0, 9 }, { 2, 11, 9 }, { 5, 2, 9 }, { 11, 2, 7 }
};

GLfloat color[] = {
   1.0f, 0.0f, 0.0f,
   0.0f, 1.0f, 0.0f,
   0.0f, 0.0f, 1.0f
};

long gDepth = 0;
long gAccum = 0;
GLfloat gAngle = 0.0f;

void drawTriangle(GLfloat *v1, GLfloat *v2, GLfloat *v3);

// ----------------------------------------------------------------------------
//  MAIN APPLICATION
// ----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::cout << "> HELLO BPM Game Engine" << std::endl;

	#ifdef DEBUG_MODE
	std::cout << "(!) DEBUG MODE ACTIVATED" << std::endl;
	#endif

	// ------------------------------------------------------------------------
	// INCLUIR O TRECHO DE CÓDIGO ABAIXO NO AMBIENTE DE TESTE DE UNIDADE
	// GEJNIWrapper jniWrapper;
	// jniWrapper.setJavaClassPath("-Djava.class.path=src\\java;");
	// if(jniWrapper.startJVM())
	// 	std::cout << "JVM success!" << std::endl;
	// else
	// 	std::cout << "JVM fail!" << std::endl;
	// if(jniWrapper.callJavaMethod("BPMNParser", "print"))
	// 	std::cout << "Java method call success!" << std::endl;

	// if(jniWrapper.destroyJVM())
	// 	std::cout << "JVM destroyed!" << std::endl;
	// else
	// 	std::cout << "JVM was not destroyed" << std::endl;
	// ------------------------------------------------------------------------

	// typedef BOOL(APIENTRY *PFNWGLSWAPINTERVALPROC)(int);
	// PFNWGLSWAPINTERVALPROC wglSwapIntervalEXT = NULL;

	// wglSwapIntervalEXT = (PFNWGLSWAPINTERVALPROC) wglGetProcAddress("wglSwapIntervalEXT");

	// if (wglSwapIntervalEXT) {
	//     wglSwapIntervalEXT(1);
	// }

	// UserEventHandler eventHandler;
	// gameEngine = new GameEngine(&eventHandler);

	// // SETTING UP WINDOW GAME
	// gameEngine->getGameWindow()->setName("BPM Game Engine DEMO - POLYGON SUBDIVIDE ALGORITHM!");
	// gameEngine->getGameWindow()->setWidth(GAME_SPLASH_WIDTH);
	// gameEngine->getGameWindow()->setHeight(GAME_SPLASH_HEIGHT);
	// gameEngine->getGameWindow()->setX(center(GAME_SCREEN_WIDTH, GAME_SPLASH_WIDTH));
	// gameEngine->getGameWindow()->setY(center(GAME_SCREEN_HEIGHT, GAME_SPLASH_HEIGHT));
	// gameEngine->getGameWindow()->setStyle(GE_WIN_COMPLETE);

	// if(!gameEngine->getGameWindow()->createWindow())
	// {
	// 	delete gameEngine;
	// 	return 0;
	// }

	// if(!gameEngine->getRenderingSystem()->initialize())
	// {
	// 	delete gameEngine;
	// 	return 0;
	// }

	// gameEngine->getGameWindow()->showWindow();
	// gameEngine->startMainLoop();

	// delete gameEngine;
	std::cout << "> BYE BPM Game Engine" << std::endl;
	return 1;
}

// ----------------------------------------------------------------------------
//  DEMO FUNCTIONS
// ----------------------------------------------------------------------------
void drawTriangle(GLfloat *v1, GLfloat *v2, GLfloat *v3)
{
   glBegin(GL_TRIANGLES);
   glColor3fv(&color[0]);
   glVertex3fv(v1);
   glColor3fv(&color[3]);
   glVertex3fv(v2);
   glColor3fv(&color[6]);
   glVertex3fv(v3);
   glEnd();
}

void subdivide(GLfloat *v1, GLfloat *v2, GLfloat *v3, long depth)
{
   GLfloat v12[3], v23[3], v31[3];

   if(!depth)
   {
      drawTriangle(v1, v2, v3);
      return;
   }

   for(int i = 0; i < 3; i++)
   {
      v12[i] = (v1[i] + v2[i]) / 2.0;
      v23[i] = (v2[i] + v3[i]) / 2.0;
      v31[i] = (v3[i] + v1[i]) / 2.0;
   }

   subdivide( v1, v12, v31, depth - 1);
   subdivide( v2, v23, v12, depth - 1);
   subdivide( v3, v31, v23, depth - 1);
   subdivide(v12, v23, v31, depth - 1);
}

// ----------------------------------------------------------------------------
//  USER EVENTS DEFINITION
// ----------------------------------------------------------------------------
void UserEventHandler::frameEvent()
{
	if(GetAsyncKeyState(0x31) < 0) ::gDepth = 1;
	if(GetAsyncKeyState(0x32) < 0) ::gDepth = 2;
	if(GetAsyncKeyState(0x33) < 0) ::gDepth = 3;
	if(GetAsyncKeyState(0x34) < 0) ::gDepth = 4;
	if(GetAsyncKeyState(VK_F1) < 0) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if(GetAsyncKeyState(VK_F2) < 0) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if(GetAsyncKeyState(VK_ESCAPE) < 0) gameEngine->stopMainLoop();

	::gAccum += gameEngine->getTimeHandler()->getFrameTime();

	::gAngle = (::gAngle > 360.0f ? 0.0f : ::gAngle + 1.0f);

	if(::gAccum > 250)
	{
		for(int i = 0; i < 10000000; i++);

		::gAccum -= 250;

		for(int i = 0; i < 9; i++)
			color[i] = (rand() % 255) / 255.0;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(::gAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(::gAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(::gAngle, 0.0f, 0.0f, 1.0f);

	for(int i = 0; i < 20; i++)
	{
		subdivide(&vdata[tindices[i][0]][0], &vdata[tindices[i][1]][0], &vdata[tindices[i][2]][0], ::gDepth);
	}
}

void UserEventHandler::mouseEvent(int button, int state, int x, int y)
{
}

void UserEventHandler::mouseMotionEvent(int x, int y)
{
}

void UserEventHandler::keyboardEvent(unsigned char key, int state)
{
}

void UserEventHandler::resizeWindowEvent(int width, int height)
{
	gameEngine->getGameWindow()->setWidth(width);
	gameEngine->getGameWindow()->setHeight(height);
	gameEngine->getRenderingSystem()->setViewport(0, 0, width, height);
	gameEngine->getRenderingSystem()->setProjection();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void UserEventHandler::finishAfterEvent()
{
	gameEngine->stopMainLoop();
}

void UserEventHandler::finishBeforeEvent()
{
	gameEngine->getGameWindow()->destroyWindow();
}

void UserEventHandler::resumeEvent()
{
	gameEngine->resumeGameLoop();
}

void UserEventHandler::pauseEvent()
{
	gameEngine->pauseGameLoop();
}

void UserEventHandler::beforeMainLoopEvent()
{
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClearColorHex(0x40, 0x40, 0x40, 0xFF);
	
	gameEngine->getRenderingSystem()->setRenderingContext(GE_CONTEXT_3D);
	gameEngine->getRenderingSystem()->setProjectionFOVY(45.0);
	gameEngine->getRenderingSystem()->setProjectionZNear(1.0);
	gameEngine->getRenderingSystem()->setProjectionZFar(1000.0);
	gameEngine->getRenderingSystem()->setViewport(0, 0);
	gameEngine->getRenderingSystem()->setProjection();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
}