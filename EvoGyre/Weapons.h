#ifndef _WEAPONS
#define _WEAPONS

#include "../Engine/Texture.h"
#include "Constants.h"

#include <vector>


enum weaponTypes {
	BLUE_LASER,
	RED_LASER,
	ROUND_LG,
	ROUND_SM,
	SHARP_LASER,
};

struct weaponHardpoint {
	float ox;  // Bullet start point relative (offset) to spaceship position.
	float oy;
	float vx;  // Bullet velocity in map coordinate system.
	float vy;
	weaponHardpoint(float _x, float _y, float _vx, float _vy)
		: ox(_x), oy(_y), vx(_vx), vy(_vy) {}
};

/**
 * Specifies firing rate and vector of hardpoints.
 */
struct weaponSystem {
	Texture texture;  // Weapon type enum value
	float rate;  // Rest time between shots
	vector<weaponHardpoint> hardpoints;
	weaponSystem(string filename, float _rate, vector<weaponHardpoint> _hardpoints)
		: texture(filename), rate(_rate), hardpoints(_hardpoints) {}
};

#endif // !_WEAPONS
