#include "Player.h"
#include "../Engine/Engine.h"
#include "../Engine/Input.h"

Player::Player(string path) : Spaceship(), Sprite(path) {}
Player::Player(string path, float _x, float _y) : 
	Spaceship(), Sprite(path) 
{
	Spaceship::SetPos(Vector3(_x, _y, 0));
	Sprite::SetScale(Vector3(1.5, 1, 1));
}

inline Vector3 Player::GetDisplayPos()
{
	return GAME_PROJECTION::mapPointToDisplay(Spaceship::pos);
}

void Player::Update()
{
	if (Input::Key(GLFW_KEY_LEFT) || Input::Key(GLFW_KEY_A))
	{
		Spaceship::pos.y -= 1;
	}
	if (Input::Key(GLFW_KEY_RIGHT) || Input::Key(GLFW_KEY_D))
	{
		Spaceship::pos.y += 1;
	}

	if (Spaceship::pos.y < 270 - 45)
	{
		Spaceship::pos.y += 1;
	}

	if (Spaceship::pos.y > 270 + 45)
	{
		Spaceship::pos.y -= 1;
	}

	// Send sprite display update
	Sprite::SetPosition(GetDisplayPos());
	Sprite::SetRotation(Spaceship::pos.y + 90);
}