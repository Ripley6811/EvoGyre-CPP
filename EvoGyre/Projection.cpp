#include "Projection.h"

static const float D2R = 0.0174532925f;

Vector3 GAME_PROJECTION::mapPointToDisplay(const Vector3& vec)
{
	// Depth is a percentage of the length of the cone.
	float depth = vanishingPower(vec.x / SETTING::MAP_SIZE_X);
	// Position along the length of the cone.
	float _x = SETTING::PROJECTION_RADIUS * depth;
	// Rotate point around center based on y.
	float new_x = cos(vec.y * D2R) * _x;
	float new_y = sin(vec.y * D2R) * _x;
	// Shift cone center to display center.
	Vector3 new_v = Vector3(new_x + SETTING::GAME_CENTER_X, new_y + SETTING::GAME_CENTER_Y, depth);
	transposeCenter(new_v);
	return new_v;
}

float GAME_PROJECTION::vanishingPower(const float& x)
{
	return pow(x, SETTING::VANISHING_STRETCH);
}

void GAME_PROJECTION::transposeCenter(Vector3& pt)
{
	Vector3 scaledV = vanishingPoint.setLength( SETTING::CENTER_DISPLACEMENT );
	scaledV = scaledV.scl(1.f - std::pow(pt.z, 1.f / SETTING::FUNNEL_CURVE));
	pt.x += scaledV.x;
	pt.y += scaledV.y;
}

void GAME_PROJECTION::SetVanishingPoint(float _rot)
{
	GAME_PROJECTION::vanishingPoint.x = (float) cos(_rot * D2R);
	GAME_PROJECTION::vanishingPoint.y = (float) sin(_rot * D2R);
}