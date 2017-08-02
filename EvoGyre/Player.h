#ifndef _PLAYER
#define _PLAYER

#include "../Interface/Spaceship.h"
#include "Projection.h"
#include "BulletManager.h"

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

	void Update() override;
	void Render();

	BulletManager bulletManager;

private:

};

#endif