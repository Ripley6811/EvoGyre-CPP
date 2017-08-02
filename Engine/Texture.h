#ifndef _TEXTURE
#define _TEXTURE

#include "GLFW/glfw3.h"
#include "Vector3.h"
#include "soil.h"

#include <iostream>
#include <string>
using namespace std;

/**
* This class holds a texture and positioning data for display.
* This is intended to be inherited or used in other classes.
*/
class Texture
{
public:
	Texture(string imagePath);
	~Texture() {}

	void Render(const float& posx, const float& posy);
	void Render(const float& posx, const float& posy, const float& rotation);
	void Render(const float& posx, const float& posy, const float& rotation,
				const float& scalex, const float& scaley);

protected:
	int textureID;
	int textureWidth;
	int textureHeight;
};

#endif