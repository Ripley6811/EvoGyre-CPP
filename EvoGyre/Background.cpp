#include "Background.h"
#include "Projection.h"

#include <random>

Background::Background(string path) : Background(path, 0, 0) {}

Background::Background(string path, float _x, float _y) :
	Sprite(path), x(_x), y(_y)
{
	// Stars
	for (Vector3& star : fixedStars)
	{
		star.x = (float)(rand() % (int)SETTING::DISPLAY_SIZE_X);
		star.y = (float)(rand() % (int)SETTING::DISPLAY_SIZE_X);
	}
	for (Vector3& star : shootingStars)
	{
		star.x = (float)(rand() % (int)SETTING::MAP_SIZE_X);
		star.y = (float)(rand() % (int)SETTING::MAP_SIZE_Y_360);
	}

	// Planet
	Sprite::SetScale(0.5f);
}

void Background::Update()
{
	// Rotate stars
	for (Vector3& star : fixedStars)
	{

	}
	for (Vector3& star : shootingStars)
	{
		star.x += SETTING::SHOOTING_STAR_SPEED;
		if (star.x > SETTING::MAP_SIZE_X)
		{
			star.x = 0;
			star.y = (float)(rand() % (int)SETTING::MAP_SIZE_Y_360);
		}
	}

	Sprite::SetPosition(GAME_PROJECTION::mapPointToDisplay(Vector3(x, y, 0)));
}

void Background::Render()
{
	{ // Draw Stars
		glLoadIdentity();
		glPointSize(1);
		glBegin(GL_POINTS);
		// random r between 0.0 and 0.5
		//float r = static_cast <float> (rand()) / static_cast <float> (2 * RAND_MAX);
		float r = 0.4f;
		for (Vector3& star : fixedStars)
		{
			r += 0.05;
			if (r > 1.f) r = 0.4f;
			glColor4f(r, r, 0.8, 0.8);
			glVertex3f(star.x, star.y, 0);
		}
		Vector3* projected_star;
		for (Vector3& star : shootingStars)
		{
			projected_star = &GAME_PROJECTION::mapPointToDisplay(Vector3(star.x, star.y, 0));

			glColor4f(1, 1, 1, star.x / SETTING::MAP_SIZE_X);
			glVertex3f(projected_star->x, projected_star->y, 0);
		}
		glEnd();
	}

	// Draw planet
	//Sprite::Render();
}