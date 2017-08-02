#ifndef _BULLETMANAGER
#define _BULLETMANAGER

#include "../Engine/Texture.h"

#include <vector>
#include <string>

struct bullet {
	float x;
	float y;
	float vx;
	float vy;
	float lastx;
	float lasty;
	int level;
	bool isActive;
	bullet(int _level, float _x, float _y, float _vx, float _vy)
		: x(_x), y(_y), vx(_vx), vy(_vy), level(_level), isActive(true)
	{
	}
};

/**
 * Manages all bullets on screen.
 */
class BulletManager
{
public:
	BulletManager();
	~BulletManager() {};

	void AddBullet(int level, float x, float y, float vx, float vy);

	void Update();
	void Render();

private:
	vector<string> names;
	vector<Texture> textures;
	vector<bullet> bullets;
};

#endif // !_BULLETMANAGER
