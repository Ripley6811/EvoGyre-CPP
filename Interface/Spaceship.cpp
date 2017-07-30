#include "Spaceship.h"
#include <iostream>
using namespace std;

void Spaceship::shield_damage(int amount)
{
}

void Spaceship::shield_repair(int amount)
{
}

void Spaceship::hull_damage(int amount)
{
}

void Spaceship::hull_repair(int amount)
{
}

void Spaceship::SetTexture(string path)
{
	texture_id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	cout << texture_id << endl;
	if (!GetTextureParams())
	{
		cout << "Error loading image" << endl;
	}
}

bool Spaceship::GetTextureParams()
{

	if (texture_id > 0)
	{
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &texture_width); //iv for int not float
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &texture_height); //iv for int not float
		cout << texture_height << endl;
		return true;
	}
	return false;
}

void Spaceship::Update()
{

}

void Spaceship::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	
	glTranslatef(pos.x, pos.y, 0);
	//glRotatef(rot, 0, 0, 1);
	//glScalef(scale.x, scale.y, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2i(-texture_width / 2, -texture_height / 2);
	glTexCoord2f(1, 0); glVertex2i(texture_width / 2, -texture_height / 2);
	glTexCoord2f(1, 1); glVertex2i(texture_width / 2, texture_height / 2);
	glTexCoord2f(0, 1); glVertex2i(-texture_width / 2, texture_height / 2);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}