#include "BulletManager.h"
#include "Constants.h"
#include "Projection.h"

#include <iostream>
using namespace std;


BulletManager::BulletManager()
{
}

void BulletManager::AddBullet(const Texture & _t, float x, float y, float vx, float vy)
{
	bullets.push_back(bullet(_t, x, y, vx, vy));
	cout << bullets.size() << endl;
}

void BulletManager::Update(const double dt)
{
	while (!bullets.empty() && !bullets.front().isActive)
	{
		bullets.erase(bullets.begin());
	}
	for (bullet & b : bullets)
	{
		b.lastx = b.x;
		b.lasty = b.y;
		b.x += b.vx * (float) dt;
		b.y += b.vy * (float) dt;
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
		b.texture.Render(dspPt.x, dspPt.y, theta, pow(depth, 2), pow(depth, 2));
	}
}