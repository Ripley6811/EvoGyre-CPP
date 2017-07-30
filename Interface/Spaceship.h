#ifndef _SPACESHIP
#define _SPACESHIP

#include "../Engine/Vector3.h"
#include "GLFW/glfw3.h"
#include "soil.h"

#include <string>
using namespace std;

class Spaceship
{
public:
	Spaceship(string path) : hull(0), shield(0), texture_id(-1) { SetTexture(path); }
	Spaceship(float _hull, float _shield) : hull(_hull), shield(_shield) {}
	Spaceship(string path, float _hull, float _shield) : hull(_hull), shield(_shield) 
	{
		SetTexture(path);
	}
	~Spaceship() {}

	void SetTexture(string path);
	void shield_damage(int amount);
	void shield_repair(int amount);
	void hull_damage(int amount);
	void hull_repair(int amount);
	bool GetTextureParams();

	void SetPos(Vector3 _pos) { pos = _pos; }
	Vector3 GetPos() { return pos; }
	void SetShield(float val) { shield = val; }
	float GetShield() { return shield; }
	void SetHull(float val) { hull = val; }
	float GetHull() { return hull; }

	void Update();
	void Render();

	Vector3 pos;
	float hull;
	float shield;
	int texture_id;
	int texture_width;
	int texture_height;
};

#endif // !_SPACESHIP_INTERFACE

