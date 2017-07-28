#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	// First two constructors delegate to the third.
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xPos, float _yPos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void SetRotTo(float r);
	void SetRotBy(float r);

	void SetScale(float x);
	void SetScale(Vector3 v);

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;
	float speed;
	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;
};

#endif