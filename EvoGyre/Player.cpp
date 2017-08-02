#include "Player.h"
#include "../Engine/Engine.h"
#include "../Engine/Input.h"

Player::Player(string path) : Spaceship(), Sprite(path) {}
Player::Player(string path, float _x, float _y) :
	Spaceship(), Sprite(path), bulletManager()
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
		Spaceship::pos.y -= 2;
	}
	if (Input::Key(GLFW_KEY_RIGHT) || Input::Key(GLFW_KEY_D))
	{
		Spaceship::pos.y += 2;
	}
	if (Spaceship::pos.y > 360) Spaceship::pos.y -= 360;
	if (Spaceship::pos.y < 0) Spaceship::pos.y += 360;
	
	if (Spaceship::pos.y < 160 && Spaceship::pos.y > 90) Spaceship::pos.y += 2;
	if (Spaceship::pos.y > 20 && Spaceship::pos.y < 90) Spaceship::pos.y -= 2;
	
	if (Input::Key(GLFW_KEY_UP) || Input::Key(GLFW_KEY_W))
	{
		bulletManager.AddBullet(0, Spaceship::pos.x, Spaceship::pos.y, -5.f, 0.f);
	}

	bulletManager.Update();

	// Send sprite display update
	Sprite::SetPosition(GetDisplayPos());
	Sprite::SetRotation(Spaceship::pos.y + 90);
}

void Player::Render()
{
	bulletManager.Render();
	Sprite::Render();
}