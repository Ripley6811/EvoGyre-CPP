#ifndef _SPRITE
#define _SPRITE

#include "GLFW/glfw3.h"
#include "Vector3.h"
#include "soil.h"
#include "Texture.h"

#include <iostream>
#include <string>
using namespace std;

/**
 * This class holds a texture and positioning data for display.
 * This is intended to be inherited or used in other classes.
 */
class Sprite : public Texture
{
public:
	Sprite(string imagePath);
	Sprite(string imagePath, float _xPos, float _yPos);
	
	void SetPosition(Vector3 v);
	void SetPosition(float _xPos, float _yPos);
	void SetRotation(float r);
	void SetScale(Vector3 v);
	void SetScale(float x);  // All set to x

	virtual void Update() = 0;
	virtual void Render();

private:
	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;
};

#endif