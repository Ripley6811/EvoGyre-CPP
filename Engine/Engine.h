#ifndef CENGINE
#define CENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")  // Make sure running in x86 mode.

#include <iostream>
using namespace std;



class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static double GetDT();

	Engine();
	~Engine();

	bool Initialize(char* windowTitle);
	bool Initialize(char* windowTitle, const int& width, const int& height);
	
	// Update triggers the input keys and button polling
	void Update();
	void BeginRender();
	void EndRender();
	
private:
	static GLFWwindow* window;

	static const double FPS_LIMIT;
	static double dt;
	static double lastTime;
};

#endif // !ENGINE
