#ifndef _PLAYER
#define _PLAYER

#include "../Interface/Spaceship.h"
#include "Projection.h"
#include "BulletManager.h"
#include "Weapons.h"

#include <iostream>
#include <string>
using namespace std;


class Player : public Spaceship, public Sprite
{
public:
	Player(string path);
	Player(string path, float _x, float _y);
	~Player() {}

	Vector3 GetDisplayPos();
	void SetWeaponLevel(int newLevel);
	void InitWeaponSystems();
	void FireWeapon();

	void Update() override;
	void Render();

	BulletManager bulletManager;



private:
	float weaponCooldown;
	int weaponLevel;
	vector<weaponSystem> weaponSystems;
};

#endif