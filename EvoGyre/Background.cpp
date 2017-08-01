#include "Background.h"
#include "Projection.h"

Background::Background(string path) : Background(path, 0, 0) {}

Background::Background(string path, float _x, float _y) :
	Sprite(path), x(_x), y(_y)
{
	Sprite::SetScale(0.5f);
}

void Background::Update()
{

	Sprite::SetPosition(GAME_PROJECTION::mapPointToDisplay(Vector3(x, y, 0)));
}
