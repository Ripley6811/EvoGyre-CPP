#ifndef TWITCH_TEXTURE
#define TWITCH_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"
#pragma comment(lib, "C:/Users/Jay/Documents/Visual Studio 2017/Projects/GameAttempt1/GameAttempt1/Engine/Graphics/SOIL/projects/VC9/Debug/SOIL.lib")

#include <iostream>
#include <string>
using namespace std;

class Texture
{
public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();

private:
	bool GetTextureParams();
	int id;
	int width;
	int height;

};


#endif