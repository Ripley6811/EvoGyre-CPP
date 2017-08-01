#include "Projection.h"

Vector3 GAME_PROJECTION::mapPointToDisplay(const Vector3& vec)
{
	// Depth is a percentage of the length of the cone.
	float depth = vanishingPower(vec.x / SETTING::MAP_SIZE_X);
	// Position along the length of the cone.
	float _x = SETTING::PROJECTION_RADIUS * depth;
	// Rotate point around center based on y.
	float new_x = cos(vec.y * 0.0174532925) * _x;
	float new_y = sin(vec.y * 0.0174532925) * _x;
	// Shift cone center to display center.
	new_x += SETTING::DISPLAY_SIZE_X * 0.5;
	new_y += SETTING::DISPLAY_SIZE_X * 0.75;
	return Vector3(new_x, new_y, depth);
}

float GAME_PROJECTION::vanishingPower(const float& x)
{
	return pow(x, SETTING::VANISHING_STRETCH);
}
