#include "Tactical.h"

#include <iostream>
using namespace std;

Tac::Tac() : Tac(0.0f, 0.0f) {}

Tac::Tac(float _hull, float _shield) 
	: hull(_hull), shield(_shield), 
	weaponSelection(3), weaponCooldown(0), bulletManager()
{
}

int Tac::AddWeaponSystem(weaponSystem x)
{
	weaponSystems.push_back(x);
	return weaponSystems.size();
}

void Tac::shield_damage(int amount)
{
}

void Tac::shield_repair(int amount)
{
}

void Tac::hull_damage(int amount)
{
}

void Tac::hull_repair(int amount)
{
}

void Tac::SetWeaponSelection(int newSelection)
{
	weaponSelection = newSelection;
}

void Tac::SetShield(float val) { shield = val; }

float Tac::GetShield() { return shield; }

void Tac::SetHull(float val) { hull = val; }

float Tac::GetHull() { return hull; }

bool Tac::Update(double dt)
{
	bool weaponReady = true;
	bulletManager.Update(dt);

	if (Tac::weaponCooldown > 0.f)
	{
		Tac::weaponCooldown -= (float) dt;
		weaponReady = false;
	}

	return weaponReady;
}

void Tac::Render()
{
	bulletManager.Render();
	// TODO: Render shields
}

bool Tac::FireWeapon(const Vector3 & pos)
{
	if (weaponCooldown > 0.f) return false;
	float cx;
	float cy;
	const weaponSystem & x = weaponSystems[weaponSelection];
	for (const weaponHardpoint & hp : x.hardpoints)
	{
		cx = pos.x + hp.ox;
		cy = pos.y + hp.oy;
		bulletManager.AddBullet(x.texture, cx, cy, hp.vx, hp.vy);
	}
	weaponCooldown = x.rate;
	return true;
}