#include "Engine.h"
#include "Input.h"

const double Engine::FPS_LIMIT = 1.0 / 60.0;
int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;
double Engine::dt = 0;
double Engine::lastTime;
bool Engine::pause = false;

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(char* windowTitle) {
	return Initialize(windowTitle, SCREEN_WIDTH, SCREEN_HEIGHT);
}

bool Engine::Initialize(char* windowTitle, const int& win_width, const int& win_height)
{
	if (!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(win_width, win_height, windowTitle, NULL, NULL);
	if (!window)
	{
		cout << "Error creating window" << endl;
		return false;
	}
	// TODO: add glfwTerminate() and glfwDestroyWindow(window) somewhere

	// GLFW Setup
	glfwMakeContextCurrent(window);  // Must have OpenGL context to use OpenGL API
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1); //Swap every frame

	glfwSetCursorPosCallback(window, Input::MousePosCallback);
	glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);
	glfwSetKeyCallback(window, Input::KeyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	// GL Setup
	// viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  // Applies the projection
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	// Alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = glfwGetTime();

	return true;
}

void Engine::Update()
{
	double now = glfwGetTime();
	dt = now - lastTime;
	lastTime = now;
	glfwPollEvents();  //Capture mouse motion etc.
}

void Engine::BeginRender()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender()
{
	glfwSwapBuffers(window);
}

bool Engine::IsPaused()
{
	return pause;
}

void Engine::SetPause(bool _pause)
{
	pause = _pause;
}

double Engine::GetDT()
{
	return dt;
}