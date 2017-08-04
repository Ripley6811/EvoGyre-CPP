#ifndef _TACTICAL
#define _TACTICAL

#include "../Engine/Vector3.h"
#include "../EvoGyre/Weapons.h"
#include "../EvoGyre/BulletManager.h"

#include <string>
using namespace std;

/**
 * Tactical management class. Weapons and shields.
 */
class Tac
{
public:
	Tac();
	Tac(float _hull, float _shield);
	~Tac() {}

	void shield_damage(int amount);
	void shield_repair(int amount);
	void hull_damage(int amount);
	void hull_repair(int amount);

	void SetWeaponSelection(int newSelection);
	void SetShield(float val);
	float GetShield();
	void SetHull(float val);
	float GetHull();

	// The order layouts are added correspond to 'weaponSelection'.
	int AddWeaponSystem(weaponSystem x);

	// Returns false if weapon is still in cooldown phase.
	bool FireWeapon(const Vector3 & pos);

	// True if weapon ready. Delta-time used for cooldown timer.
	bool Update(double dt);

	void Render();

protected:

private:
	float hull;
	float shield;
	// Weapon is ready to fire when cooldown is zero.
	float weaponCooldown;
	// Corresponds to added weapon systems.
	int weaponSelection;
	vector<weaponSystem> weaponSystems;
	BulletManager bulletManager;
};
#endif // !_TACTICAL