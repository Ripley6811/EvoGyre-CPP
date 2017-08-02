#include "BulletManager.h"
#include "Constants.h"
#include "Projection.h"

#include <iostream>
using namespace std;

BulletManager::BulletManager()
{
	names = { FILENAME::BLUELASER, FILENAME::REDLASER };
	textures.reserve(names.size());
	cout << "FILENAMES size:" << names.size() << endl;
	for (string filename : names)
	{
		cout << filename << endl;
		textures.push_back(Texture(filename));
	}
}

void BulletManager::AddBullet(int level, float x, float y, float vx, float vy)
{
	bullets.push_back(bullet(level, x, y, vx, vy));
}

void BulletManager::Update()
{
	while (!bullets.empty() && !bullets.front().isActive)
	{
		bullets.erase(bullets.begin());
	}
	for (bullet & b : bullets)
	{
		b.lastx = b.x;
		b.lasty = b.y;
		b.x += b.vx;
		b.y += b.vy;
		if (b.y < 0.f) b.y += 360.f;
		if (b.y >= 360.f) b.y -= 360.f;
		if (b.x < SETTING::MAP_SIZE_X * 0.1f)
		{
			b.isActive = false;
		}
	}
}

void BulletManager::Render()
{
	for (bullet & b : bullets)
	{
		if (!b.isActive) continue;
		Vector3 dspPt = GAME_PROJECTION::mapPointToDisplay(Vector3(b.x, b.y, 0.f));
		Vector3 dspPtv = GAME_PROJECTION::mapPointToDisplay(Vector3(b.x-b.vx, b.y-b.vy, 0.f));
		float theta = 90.f + atan2(dspPt.y - dspPtv.y, dspPt.x - dspPtv.x) * 180.f / 3.14159f;
		float depth = b.x / SETTING::MAP_SIZE_X;
		textures[b.level].Render(dspPt.x, dspPt.y, theta, pow(0.5f * depth, 1), pow(depth, 1));
	}
}