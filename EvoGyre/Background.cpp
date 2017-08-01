#include "Background.h"
#include "Projection.h"

#include <random>

Background::Background(string path) : Background(path, 0, 0) {}

Background::Background(string path, float _x, float _y) :
	Sprite(path), x(_x), y(_y)
{
	// Stars
	for (Vector3& star : stars)
	{
		star.x = (float)(rand() % (int)SETTING::DISPLAY_SIZE_X);
		star.y = (float)(rand() % (int)SETTING::DISPLAY_SIZE_X);
	}

	// Planet
	Sprite::SetScale(0.5f);
}

void Background::Update()
{
	Sprite::SetPosition(GAME_PROJECTION::mapPointToDisplay(Vector3(x, y, 0)));
}

void Background::Render()
{
	{ // Draw Stars
		glLoadIdentity();
		glPointSize(1);
		glBegin(GL_POINTS);
		glColor4f(1, 1, 1, 1);
		for (Vector3& star : stars)
		{
			glVertex3f(star.x, star.y, 0);
		}
		glEnd();
	}

	// Draw planet
	Sprite::Render();
}