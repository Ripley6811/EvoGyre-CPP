#include "Texture.h"

Texture::Texture(string imagePath)
{
	textureID = SOIL_load_OGL_texture(imagePath.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (textureID == 0)
	{
		throw std::exception("Invalid path name");
	}
	int mipLevel = 0;
	glBindTexture(GL_TEXTURE_2D, textureID);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &textureWidth); 
	glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &textureHeight); 
}

void Texture::Render(const float & posx, const float & posy)
{
	Render(posx, posy, 0.f, 0.f, 0.f);
}

void Texture::Render(const float & posx, const float & posy, const float & rotation)
{
	Render(posx, posy, rotation, 0.f, 0.f);
}

void Texture::Render(const float & posx, const float & posy, const float & rotation, const float & scalex, const float & scaley)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	glTranslatef(posx, posy, 0);
	glRotatef(rotation, 0, 0, 1);
	glScalef(scalex, scaley, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0); glVertex2i(-textureWidth / 2, -textureHeight / 2);
		glTexCoord2f(1, 0); glVertex2i(textureWidth / 2, -textureHeight / 2);
		glTexCoord2f(1, 1); glVertex2i(textureWidth / 2, textureHeight / 2);
		glTexCoord2f(0, 1); glVertex2i(-textureWidth / 2, textureHeight / 2);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
