#include "Sprite.h"

#include <stdexcept>


Sprite::Sprite(string imagePath) : Sprite(imagePath, 0, 0) {}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
	textureID = SOIL_load_OGL_texture(imagePath.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (textureID == 0)
	{
		throw std::exception("Invalid path name");
	}
	int mipLevel = 0;
	glBindTexture(GL_TEXTURE_2D, textureID);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &textureWidth); //iv for int not float
	glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &textureHeight); //iv for int not float
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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2i(-textureWidth / 2, -textureHeight / 2);
	glTexCoord2f(1, 0); glVertex2i(textureWidth / 2, -textureHeight / 2);
	glTexCoord2f(1, 1); glVertex2i(textureWidth / 2, textureHeight / 2);
	glTexCoord2f(0, 1); glVertex2i(-textureWidth / 2, textureHeight / 2);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}