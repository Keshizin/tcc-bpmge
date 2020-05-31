#include <windows.h>
#include <iostream>

#include <ge.h>
#include <GL/gl.h>

class UserEventHandler : public GEEventHandler
{
	void frameEvent();
// 	void mouseEvent(int button, int state, int x, int y);
// 	void mouseMotionEvent(int x, int y);
// 	void keyboardEvent(unsigned char key, int state);
// 	void keyboardSpecialEvent(unsigned char key, int state);
	void resizeWindowEvent(int width, int height);
	void finishAfterEvent();
	void finishBeforeEvent();
	void resumeEvent();
	void pauseEvent();
};

GameEngine *singletonGameEngine = 0;
GETimer *timer;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

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

void drawTriangle(GLfloat *v1, GLfloat *v2, GLfloat *v3)
{
   glBegin(GL_TRIANGLES);
   glColor3fv(&color[0]);
   //glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3fv(v1);
   glColor3fv(&color[3]);
   //glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3fv(v2);
   glColor3fv(&color[6]);
   //glColor3f(0.0f, 0.0f, 1.0f);
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

// int splashMode = 1;
// int _seconds = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	#ifdef DEBUG_MODE
	std::cout << "(!) DEBUG MODE ACTIVATED !!!!" << std::endl;
	#endif

	std::cout << "HELLO BPM Game Engine!" << std::endl;

	UserEventHandler userEventHandler;
	singletonGameEngine = new GameEngine(&userEventHandler);

	singletonGameEngine->getGameWindow()->setName("BPM Game Engine");
	singletonGameEngine->getGameWindow()->setWidth(WINDOW_WIDTH);
	singletonGameEngine->getGameWindow()->setHeight(WINDOW_HEIGHT);
	singletonGameEngine->getGameWindow()->setXPosition(960 - WINDOW_WIDTH / 2);
	singletonGameEngine->getGameWindow()->setYPosition(540 - WINDOW_HEIGHT / 2);
	// singletonGameEngine->getGameWindow()->setStyle(GE_WIN_DEFAULT);
	singletonGameEngine->getGameWindow()->setStyle(GE_WIN_WINDOWED_FULLSCREEN);

	if(!singletonGameEngine->getGameWindow()->createWindow())
	{
		delete singletonGameEngine;
		return 0;
	}

	if(!singletonGameEngine->getRenderingSystem()->initialize(WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		delete singletonGameEngine;
		return 0;
	}

	singletonGameEngine->getGameWindow()->showWindow();
	singletonGameEngine->getRenderingSystem()->setRenderingMode(GE_RENDERING_SYSTEM_3D);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	timer = new GETimer(singletonGameEngine->getTimeHandler());
	timer->setTimer(singletonGameEngine->getApiWrapper()->getHighResolutionTimerFrequency());
	timer->start();

	singletonGameEngine->startMainLoop();

	// splashMode = 0;

	// windowDemo->setWidth(1600);
	// windowDemo->setHeight(800);
	// windowDemo->setXPosition(960 - 800);
	// windowDemo->setYPosition(540 - 400);
	// windowDemo->setStyle(GE_WIN_DEFAULT);

	// if(!windowDemo->createWindow())
	// {
	// 	delete _timer;
	// 	delete demoEventHandler;
	// 	delete windowDemo;
	// 	delete singletonGameEngine;
	// 	return 0;
	// }

	// mainRenderingSystem->setBackgroundColor(GE_BKG_COLOR_WHITE);
	// mainRenderingSystem->setRenderingSystem();
	// windowDemo->showWindow();

	// _timer->setTimer(singletonGameEngine->getApiWrapper()->getHighResolutionTimerFrequency());
	// _timer->start();

	// singletonGameEngine->startMainLoop();

	std::cout << "BYE BPM Game Engine!" << std::endl;

	singletonGameEngine->getDiag()->print();

	// delete windowDemo;
	delete timer;
	delete singletonGameEngine;
	return 1;
}

void UserEventHandler::frameEvent()
{
	::gAccum += singletonGameEngine->getTimeHandler()->getFrameTime();
	::gAngle = (::gAngle > 360.0f ? 0.0f : ::gAngle + 1.0f);

	if(::gAccum > 250)
	{
		::gAccum -= 250;

		for(int i = 0; i < 9; i++)
			color[i] = (rand() % 255) / 255.0;
	}

	glClear(GL_COLOR_BUFFER_BIT);

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

// void DemoEventHandler::mouseEvent(int button, int state, int x, int y)
// {
// 	std::cout << "> mouse event | button: " << button << " | state: " << state << " | x: " << x << " | y: " << y << std::endl;
// }

// void DemoEventHandler::mouseMotionEvent(int x, int y)
// {
// 	// std::cout << "> mouse motion event | x: " << x << " | y: " << y << std::endl;
// }

// void DemoEventHandler::keyboardEvent(unsigned char key, int state)
// {
// 	std::cout << "> keyboard event | key: " << key << " | state: " << state << std::endl;
// }

// void DemoEventHandler::keyboardSpecialEvent(unsigned char key, int state)
// {
// 	std::cout << "> special keyboard event | key: " << key << " | state: " << state << std::endl;
// }

void UserEventHandler::resizeWindowEvent(int width, int height)
{
	singletonGameEngine->getRenderingSystem()->setViewport(width, height);
	singletonGameEngine->getRenderingSystem()->setProjection();
}

void UserEventHandler::finishAfterEvent()
{
	singletonGameEngine->stopMainLoop();
}

void UserEventHandler::finishBeforeEvent()
{
	singletonGameEngine->getGameWindow()->destroyWindow();
}

void UserEventHandler::resumeEvent()
{
	singletonGameEngine->resumeGameLoop();
}

void UserEventHandler::pauseEvent()
{
	singletonGameEngine->pauseGameLoop();
}