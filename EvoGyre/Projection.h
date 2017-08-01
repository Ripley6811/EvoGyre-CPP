#ifndef _GAME_PROJECTION
#define _GAME_PROJECTION

#include "Constants.h"
#include "../Engine/Vector3.h"

#include <cmath>
using namespace std;

namespace GAME_PROJECTION
{
	static Vector3 vanishingPoint(0, 1, 0);

	Vector3 mapPointToDisplay(const Vector3& vec);

	// Returns a new x value based on the strength of vanishing point curve.
	float vanishingPower(const float& x);

	// Shifts points based on distance to create curve effect.
	void transposeCenter(Vector3& pt);

	void SetVanishingPoint(float _rot);
}
#endif // !_GAME_PROJECTION

