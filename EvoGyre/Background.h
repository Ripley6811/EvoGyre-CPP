#ifndef _BACKGROUND
#define _BACKGROUND

#include "../Engine/Sprite.h"
#include "Constants.h"

#include <string>
using namespace std;

typedef float degree;

/**
 * Maintains the planet and galaxy background.
 */
class Background : public Sprite
{
public:
	Background(string path);
	Background(string path, float _x, float _y);
	~Background() {}

	void Update() override;
	void Render(const degree& game_rotation);

private:
	float x;
	float y;
	Vector3 fixedStars[SETTING::NUMBER_OF_FIXED_STARS];
	Vector3 shootingStars[SETTING::NUMBER_OF_SHOOTING_STARS];
};

#endif