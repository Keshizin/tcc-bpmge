#ifndef GAME_ENGINE_RENDERING_SYSTEM_H
#define GAME_ENGINE_RENDERING_SYSTEM_H

class GERenderingSystem
{
public:
	void setRenderingSystem();
	void renderFrame();

	// Getters and Setters
	void setDoubleBufferMode(int bufferMode);
	int isDoubleBufferMode();

	void setViewportWidth(int viewportWidth);
	int getViewportWidth();

	void setViewportHeight(int viewportHeight);
	int getViewportHeight();

private:
	int doubleBufferMode; // IS DOUBLE BUFFERED MODE
	int viewportWidth;
	int viewportHeight;

	// int renderAPI; // OPENGL, VULKAN, DIRECTX
	// int pixelType; // RGBA or Color Index
	// int colorBits; // number of color bitplanes in each color buffer
	// int depthBuffer; // ACTIVATED or NOT
	// int depthBits;
	// int stencilBits;
	// int accumulationBits;
};

#endif