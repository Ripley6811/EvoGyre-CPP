#include "Background.h"
#include "Projection.h"

#include <random>
#include <cmath>

Background::Background(string path) : Background(path, 0, 0) {}

Background::Background(string path, float _x, float _y) :
	Sprite(path), x(_x), y(_y)
{
	// Stars
	for (Vector3& star : fixedStars)
	{
		star.x = SETTING::GAME_CENTER_Y * std::pow((float)rand() / (float)RAND_MAX, 0.5);
		star.y = (float)(rand() % (int)SETTING::MAP_SIZE_Y_360);
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

void Background::Render(const degree& game_rotation)
{
	{ // Draw Fixed Stars
		glLoadIdentity();
		glPointSize(1);
		glBegin(GL_POINTS);
		float r = 0.4f;  // For varying the star color
		for (Vector3& star : fixedStars)
		{
			degree theta = (game_rotation + star.y) * 0.0174532925f;
			Vector3 new_v = Vector3(cos(theta) * star.x, sin(theta) * star.x, 0);
			GAME_PROJECTION::transposeCenter(new_v);
			r += 0.05f;
			if (r > 1.f) r = 0.4f;
			glColor4f(r, r, 0.8f, 0.8f);
			glVertex3f(new_v.x + SETTING::GAME_CENTER_X, new_v.y + SETTING::GAME_CENTER_Y, 0);
		}
		glEnd();
	}

	// Draw planet
	Sprite::SetRotation(game_rotation);
	Sprite::Render();

	{ // Draw Moving Stars (or particles)
		glLoadIdentity();
		glPointSize(1);
		glBegin(GL_POINTS);
		Vector3* projected_star;
		for (Vector3& star : shootingStars)
		{
			projected_star = &GAME_PROJECTION::mapPointToDisplay(Vector3(star.x, star.y, 0));

			glColor4f(0.6f, 0.6f, 0.6f, star.x / SETTING::MAP_SIZE_X);
			glVertex3f(projected_star->x, projected_star->y, 0);
		}
		glEnd();
	}

}