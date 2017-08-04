#ifndef _NAVIGATION
#define _NAVIGATION

#include "../Engine/Vector3.h"
#include "../Engine/Sprite.h"

#include <string>
using namespace std;

/**
 * Navigation management class.
 */
class Nav
{
public:
	Nav();
	~Nav() {}

	void SetPos(Vector3 _pos);
	Vector3 GetPos();
	Vector3 GetVel();
	void SetAccel(Vector3 _accel);

	// Returns new map position after motion update.
	Vector3 Update(double dt);

protected:
	Vector3 vel;
	Vector3 pos;
	Vector3 accel;
};

#endif // !_NAVIGATION

