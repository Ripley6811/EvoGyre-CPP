#include "Player.h"
#include "../Engine/Engine.h"
#include "../Engine/Input.h"

Player::Player(string path) : Spaceship(path) {}

Vector3 Player::ToDisplay()
{
	return GAME_PROJECTION::mapPointToDisplay(pos);
}

void Player::Update()
{
	if (Input::Key(GLFW_KEY_LEFT) || Input::Key(GLFW_KEY_A))
	{
		pos.y -= 1;
	}
	if (Input::Key(GLFW_KEY_RIGHT) || Input::Key(GLFW_KEY_D))
	{
		pos.y += 1;
	}
	//pos.y += 1; // 60 * Engine::GetDT();
	dspPos = GAME_PROJECTION::mapPointToDisplay(pos);
	//cout << 100 * Engine::GetDT() << endl;
}

void Player::Render()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	glTranslatef(SETTING::GAME_PLAY_SIZE / 2, SETTING::GAME_PLAY_SIZE / 2, 0);
	glTranslatef(dspPos.x, dspPos.y, 0);
	glRotatef(pos.y + 90, 0, 0, 1);
	glScalef(dspPos.z*1.5, dspPos.z, 1);

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