#include "Player.h"
#include "../Engine/Engine.h"
#include "../Engine/Input.h"
#include "Constants.h"

Player::Player(string path) : Nav(), Sprite(path) {}
Player::Player(string path, float _x, float _y) :
	Nav(), Sprite(path)
{
	Nav::SetPos(Vector3(_x, _y, 0));
	Sprite::SetScale(Vector3(1.5, 1, 1));
	InitWeaponSystems();
}

void Player::InitWeaponSystems()
{
	Tac::AddWeaponSystem( weaponSystem(FILENAME::BLUELASER, 12.f, {
			weaponHardpoint(-7.f, 2.2f, -10.f, 0.1f),
			weaponHardpoint(-9.f, -2.2f, -10.f, -0.1f),
		}) );
	Tac::AddWeaponSystem( weaponSystem(FILENAME::BLUELASER, 12.f, {
			weaponHardpoint(-7.f, 2.2f, -10.f, 0.1f),
			weaponHardpoint(-9.f, -2.2f, -10.f, -0.1f),
			weaponHardpoint(-8.f, 2.2f, -10.f, 0.4f),
			weaponHardpoint(-8.f, -2.2f, -10.f, -0.4f),
		}) );
	Tac::AddWeaponSystem( weaponSystem(FILENAME::REDLASER, 9.6f, {
			weaponHardpoint(-7.f, 2.2f, -10.f, 0.2f),
			weaponHardpoint(-15.f, 0.0f, -10.f, 0.f),
			weaponHardpoint(-9.f, -2.2f, -10.f, -0.2f),
		}) );
	Tac::AddWeaponSystem( weaponSystem(FILENAME::REDLASER, 9.6f, {
			weaponHardpoint(-8.f, 2.2f, -10.f, 0.4f),
			weaponHardpoint(-9.f, 2.2f, -10.f, 0.2f),
			weaponHardpoint(-14.f, 0.0f, -10.f, 0.1f),
			weaponHardpoint(-16.f, 0.0f, -10.f, -0.1f),
			weaponHardpoint(-8.f, -2.2f, -10.f, -0.2f),
			weaponHardpoint(-9.f, -2.2f, -10.f, -0.4f),
		}) );
}

inline Vector3 Player::GetDisplayPos()
{
	return GAME_PROJECTION::mapPointToDisplay(Nav::pos);
}

void Player::Update(double dt)
{
	// Nav input commands
	Vector3 new_accel = Vector3(0, 0, 0);

	if (Input::Key(GLFW_KEY_LEFT) || Input::Key(GLFW_KEY_A))
	{
		new_accel.y -= SETTING::PLAYER_ACCELERATION;
	}
	if (Input::Key(GLFW_KEY_RIGHT) || Input::Key(GLFW_KEY_D))
	{
		new_accel.y += SETTING::PLAYER_ACCELERATION;
	}
	Nav::SetAccel(new_accel);

	// Tac input commands
	if (Input::Key(GLFW_KEY_UP) || Input::Key(GLFW_KEY_W)) Tac::FireWeapon(Nav::pos);


	Nav::Update(dt);
	Tac::Update(dt);

	// Send sprite display update
	Sprite::SetPosition(GetDisplayPos());
	Sprite::SetRotation(Nav::pos.y + 90);
}

void Player::Render()
{
	Tac::Render();
	Sprite::Render();
}