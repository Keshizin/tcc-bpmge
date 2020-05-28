#ifndef GAME_ENGINE_RENDERING_SYSTEM_H
#define GAME_ENGINE_RENDERING_SYSTEM_H

#include <geapiwrapper.h>

#define GE_BKG_COLOR_WHITE 1
#define GE_BKG_COLOR_BLACK 2
#define GE_BKG_COLOR_RED   3
#define GE_BKG_COLOR_GREEN 4
#define GE_BKG_COLOR_BLUE  5
#define GE_BKG_COLOR_UBUNTU_PURPLE 6

#define GE_RENDERING_SYSTEM_2D 1
#define GE_RENDERING_SYSTEM_3D 2

class GERenderingSystem
{
public:
	GERenderingSystem(GEApiWrapper *apiWrapper);

	int initialize();
	void setRenderingSystem();

	void renderFrame();

	// Getters and Setters
	void setViewportWidth(int viewportWidth);
	int getViewportWidth();

	void setViewportHeight(int viewportHeight);
	int getViewportHeight();

	void setBackgroundColor(int backgroundColor);
	int getBackgroundColor();

private:
	int renderingMode;

	int viewportWidth;
	int viewportHeight;
	int backgroundColor;

	GEApiWrapper *apiWrapper;

	// int renderAPI; // OPENGL, VULKAN, DIRECTX
	// int pixelType; // RGBA or Color Index
	// int colorBits; // number of color bitplanes in each color buffer
	// int depthBuffer; // ACTIVATED or NOT
	// int depthBits;
	// int stencilBits;
	// int accumulationBits;
};

#endif