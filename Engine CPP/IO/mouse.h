#ifndef TWITCH_MOUSE
#define TWITCH_MOUSE

#include <GLFW/glfw3.h>

// Create a static mouse class because there will only be one mouse.
class Mouse
{
public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static double GetMouseX();
	static double GetMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button);

private:
	static double x;
	static double y;

	// Array of booleans for keys to show up or down
	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];
};

#endif
