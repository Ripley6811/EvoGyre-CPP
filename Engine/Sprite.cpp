#include "Sprite.h"

#include <stdexcept>


Sprite::Sprite(string imagePath) : Sprite(imagePath, 0, 0) {}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) : Texture(imagePath)
{
	pos = Vector3(_xPos, _yPos, 0);
	rot = 0;
	scale = Vector3(1);
	size = imagePath != "" ? Vector3(textureWidth, textureHeight, 1) : Vector3(0);
}

void Sprite::SetPosition(Vector3 v)
{
	pos = v;
}

void Sprite::SetPosition(float _xPos, float _yPos)
{
	pos = Vector3(_xPos, _yPos, 0);
}

void Sprite::SetRotation(float r)
{
	rot = r;
}

/**
* Scales both x and y equally.
*/
void Sprite::SetScale(float x)
{
	scale = Vector3(x);
}

void Sprite::SetScale(Vector3 v)
{
	scale = v;
}

void Sprite::Render()
{
	Texture::Render(pos.x, pos.y, rot, scale.x, scale.y);
}