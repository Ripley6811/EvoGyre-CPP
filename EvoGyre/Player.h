#ifndef _PLAYER
#define _PLAYER

#include "../Spaceship/Navigation.h"
#include "../Spaceship/Tactical.h"
#include "Projection.h"
#include "Weapons.h"

#include <iostream>
#include <string>
using namespace std;


class Player : public Nav, public Tac, public Sprite
{
public:
	Player(string path);
	Player(string path, float _x, float _y);
	~Player() {}

	Vector3 GetDisplayPos();
	void InitWeaponSystems();

	void Update(double dt);
	void Render();
	
private:

};

#endif