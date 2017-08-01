#ifndef _SPACESHIP
#define _SPACESHIP

#include "../Engine/Vector3.h"
#include "../Engine/Sprite.h"

#include <string>
using namespace std;

/**
 * Base class for objects that move and take damage.
 */
class Spaceship
{
public:
	Spaceship();
	Spaceship(float _hull, float _shield);
	~Spaceship() {}

	void shield_damage(int amount);
	void shield_repair(int amount);
	void hull_damage(int amount);
	void hull_repair(int amount);

	void SetPos(Vector3 _pos);
	Vector3 GetPos();
	void SetShield(float val);
	float GetShield();
	void SetHull(float val);
	float GetHull();

protected:
	Vector3 pos;
	float hull;
	float shield;
};

#endif // !_SPACESHIP_INTERFACE

