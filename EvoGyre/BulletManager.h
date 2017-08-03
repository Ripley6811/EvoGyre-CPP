#ifndef _BULLETMANAGER
#define _BULLETMANAGER

#include "../Engine/Texture.h"

#include <vector>
#include <string>

/**
 * Manages all bullets on screen.
 */
class BulletManager
{
public:
	BulletManager();
	~BulletManager() {};

	void AddBullet(const Texture & _t, float x, float y, float vx, float vy);

	void Update();
	void Render();

private:
	struct bullet {
		float x;
		float y;
		float vx;
		float vy;
		float lastx;
		float lasty;
		Texture texture;
		bool isActive;
		bullet(const Texture & _t, float _x, float _y, float _vx, float _vy)
			: x(_x), y(_y), vx(_vx), vy(_vy), texture(_t), isActive(true)
		{
		}
	};
	vector<bullet> bullets;
};

#endif // !_BULLETMANAGER
