#include "Navigation.h"
#include "../EvoGyre/Constants.h"

#include <iostream>
using namespace std;

Nav::Nav() {}

void Nav::SetPos(Vector3 _pos) { pos = _pos; }

Vector3 Nav::GetPos() { return pos; }

Vector3 Nav::GetVel() { return vel; }

void Nav::SetAccel(Vector3 _accel) { accel = _accel; }

Vector3 Nav::Update(double dt)
{
	// Update velocity
	vel.x += accel.x;
	vel.y += accel.y;
	// Constrain velocity
	vel.x = vel.x < SETTING::PLAYER_MAX_VELOCITY ? vel.x : SETTING::PLAYER_MAX_VELOCITY;
	vel.x = vel.x > -SETTING::PLAYER_MAX_VELOCITY ? vel.x : -SETTING::PLAYER_MAX_VELOCITY;
	vel.y = vel.y < SETTING::PLAYER_MAX_VELOCITY ? vel.y : SETTING::PLAYER_MAX_VELOCITY;
	vel.y = vel.y > -SETTING::PLAYER_MAX_VELOCITY ? vel.y : -SETTING::PLAYER_MAX_VELOCITY;
	// Friction slowdown
	vel.x *= SETTING::PLAYER_MOTION_FRICTION;
	vel.y *= SETTING::PLAYER_MOTION_FRICTION;
	// Update position
	pos.x += vel.x * (float) dt;
	pos.y += vel.y * (float) dt;
	// Stay within bounds.
	if (pos.y > 360) pos.y -= 360;
	if (pos.y < 0) pos.y += 360;
	return pos;
}