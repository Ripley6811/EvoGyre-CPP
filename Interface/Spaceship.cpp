#include "Spaceship.h"
#include <iostream>
using namespace std;

Spaceship::Spaceship() : Spaceship(0.0f, 0.0f) {}

Spaceship::Spaceship(float _hull, float _shield) : hull(_hull), shield(_shield)
{
	pos = Vector3(0, 0, 0);
}

void Spaceship::shield_damage(int amount)
{
}

void Spaceship::shield_repair(int amount)
{
}

void Spaceship::hull_damage(int amount)
{
}

void Spaceship::hull_repair(int amount)
{
}

void Spaceship::SetPos(Vector3 _pos) { pos = _pos; }

Vector3 Spaceship::GetPos() { return pos; }

void Spaceship::SetShield(float val) { shield = val; }

float Spaceship::GetShield() { return shield; }

void Spaceship::SetHull(float val) { hull = val; }

float Spaceship::GetHull() { return hull; }
