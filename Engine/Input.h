#ifndef _INPUT
#define _INPUT

#include <GLFW/glfw3.h>

class Input
{
public:
	// KEYBOARD
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool KeyDown(int key);
	static bool KeyUp(int key);
	static bool Key(int key);  // Continuous when held down

	// MOUSE
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static double GetMouseX();
	static double GetMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button);

private:
	// KEYBOARD keys
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];


	// MOUSE position and buttons
	static double x;
	static double y;
	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];

};

#endif