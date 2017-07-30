#include "Player.h"
#include "../Engine/Engine.h"
#include "../Engine/Input.h"

Player::Player(string path) : Spaceship(), Sprite(path) {}
Player::Player(string path, float _x, float _y) : 
	Spaceship(), Sprite(path) 
{
	SetPos(Vector3(_x, _y, 0));
}

Vector3 Player::ToDisplay()
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
	//pos.y += 1; // 60 * Engine::GetDT();
	this->Sprite::SetPosition(GAME_PROJECTION::mapPointToDisplay(this->Spaceship::GetPos()));
	//cout << 100 * Engine::GetDT() << endl;
}