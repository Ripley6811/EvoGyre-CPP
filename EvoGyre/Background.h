#ifndef _BACKGROUND
#define _BACKGROUND

#include "../Engine/Sprite.h"
#include <string>
using namespace std;

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

private:
	float x;
	float y;
};

#endif