#ifndef _GAME_PROJECTION
#define _GAME_PROJECTION

#include "Constants.h"
#include "../Engine/Vector3.h"

#include <cmath>
using namespace std;

namespace GAME_PROJECTION
{
	Vector3 mapPointToDisplay(const Vector3& vec);

	float vanishingPower(const float& x);
}
#endif // !_GAME_PROJECTION

