#include "Player.h"
#include "../Engine/Engine.h"
#include "../Engine/Input.h"
#include "Constants.h"

Player::Player(string path) : Spaceship(), Sprite(path) {}
Player::Player(string path, float _x, float _y) :
	Spaceship(), Sprite(path), bulletManager(), weaponLevel(1), weaponCooldown(0)
{
	Spaceship::SetPos(Vector3(_x, _y, 0));
	Sprite::SetScale(Vector3(1.5, 1, 1));
	InitWeaponSystems();
}

void Player::InitWeaponSystems()
{
	weaponSystems.push_back(
		weaponSystem(FILENAME::BLUELASER, 0.2f, {
			weaponHardpoint(-7.f, 2.2f, -10.f, 0.1f),
			weaponHardpoint(-9.f, -2.2f, -10.f, -0.1f),
		})
		);
	weaponSystems.push_back(
		weaponSystem(FILENAME::BLUELASER, 0.2f, {
			weaponHardpoint(-7.f, 2.2f, -10.f, 0.1f),
			weaponHardpoint(-9.f, -2.2f, -10.f, -0.1f),
			weaponHardpoint(-8.f, 2.2f, -10.f, 0.4f),
			weaponHardpoint(-8.f, -2.2f, -10.f, -0.4f),
		})
		);
}

inline Vector3 Player::GetDisplayPos()
{
	return GAME_PROJECTION::mapPointToDisplay(Spaceship::pos);
}

void Player::SetWeaponLevel(int newLevel)
{
	weaponLevel = newLevel;
}

void Player::FireWeapon()
{
	if (weaponCooldown > 0.f) return;
	float cx;
	float cy;
	const weaponSystem & x = weaponSystems[weaponLevel];
	for (const weaponHardpoint & hp : x.hardpoints)
	{
		cx = Spaceship::pos.x + hp.ox;
		cy = Spaceship::pos.y + hp.oy;
		bulletManager.AddBullet(x.texture, cx, cy, hp.vx, hp.vy);
	}
	weaponCooldown = x.rate;
}

void Player::Update()
{
	if (weaponCooldown > 0.f) weaponCooldown -= 0.025f;  // TODO: Change to delta time

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
	
	if (Input::Key(GLFW_KEY_UP) || Input::Key(GLFW_KEY_W)) FireWeapon();

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