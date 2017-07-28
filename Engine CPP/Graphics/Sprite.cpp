#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite() : Sprite("", 0, 0) {}

Sprite::Sprite(string imagePath) : Sprite(imagePath, 0, 0) {}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
	pos = Vector3(_xPos, _yPos, 0);
	rot = 0;
	speed = 400;
	scale = Vector3(1);
	texture = imagePath != "" ? Texture(imagePath) : Texture();
	size = imagePath != "" ? Vector3(texture.GetWidth(), texture.GetHeight(), 1) : Vector3(0);
}

void Sprite::Update()
{
	
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2i(-texture.GetWidth() / 2, -texture.GetHeight() / 2);
	glTexCoord2f(1, 0); glVertex2i(texture.GetWidth() / 2, -texture.GetHeight() / 2);
	glTexCoord2f(1, 1); glVertex2i(texture.GetWidth() / 2, texture.GetHeight() / 2);
	glTexCoord2f(0, 1); glVertex2i(-texture.GetWidth() / 2, texture.GetHeight() / 2);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

void Sprite::MoveTo(Vector3 v)
{
	pos = v;
}

void Sprite::MoveBy(Vector3 v)
{
	pos = pos + (v * Engine::GetDT());
}

void Sprite::MoveLeft()
{
	pos.x -= speed * Engine::GetDT();
}

void Sprite::MoveRight()
{
	pos.x += speed * Engine::GetDT();
}

void Sprite::MoveUp()
{
	pos.y += speed * Engine::GetDT();
}

void Sprite::MoveDown()
{
	pos.y -= speed * Engine::GetDT();
}

void Sprite::SetRotTo(float r)
{
	rot = r;
}

void Sprite::SetRotBy(float r)
{
	rot += r * Engine::GetDT();
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

Vector3 * Sprite::GetPos()
{
	return &pos;
}

float * Sprite::GetRot()
{
	return &rot;
}

Vector3 * Sprite::GetScale()
{
	return &scale;
}

Vector3 * Sprite::GetSize()
{
	return &size;
}
