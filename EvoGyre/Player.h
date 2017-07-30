#ifndef _PLAYER
#define _PLAYER

#include "../Interface/Spaceship.h"
#include "Projection.h"

#include <iostream>
using namespace std;

class Player : public Spaceship
{
public:
	Player(string path);
	~Player() {}

	Vector3 ToDisplay();

	void Update();
	void Render();

private:
	Vector3 dspPos;

};

#endif