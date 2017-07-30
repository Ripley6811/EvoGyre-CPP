#include "Input.h"

bool Input::keys[GLFW_KEY_LAST] = { 0 };
bool Input::keysDown[GLFW_KEY_LAST] = { 0 };
bool Input::keysUp[GLFW_KEY_LAST] = { 0 };

double Input::x = 0;
double Input::y = 0;

bool Input::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Input::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Input::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key < 0)
	{
		return;
	}

	if (action != GLFW_RELEASE && keys[key] == false)
	{
		keysDown[key] = true;
		keysUp[key] = false;
	}

	if (action == GLFW_RELEASE && keys[key] == true)
	{
		keysDown[key] = false;
		keysUp[key] = true;
	}

	keys[key] = action != GLFW_RELEASE;
}

bool Input::KeyDown(int key)
{
	bool x = keysDown[key];
	keysDown[key] = false;
	return x;
}

bool Input::KeyUp(int key)
{
	bool x = keysUp[key];
	keysUp[key] = false;
	return x;
}

bool Input::Key(int key)
{
	return keys[key];
}

void Input::MousePosCallback(GLFWwindow* window, double _x, double _y)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button < 0)
	{
		return;
	}

	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	if (action != GLFW_RELEASE && buttons[button] == true)
	{
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}

double Input::GetMouseX()
{
	return x;
}

double Input::GetMouseY()
{
	return y;
}

bool Input::ButtonDown(int button)
{
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;
}

bool Input::ButtonUp(int button)
{
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}

bool Input::Button(int button)
{
	return buttons[button];
}