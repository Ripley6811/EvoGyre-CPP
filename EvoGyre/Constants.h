#ifndef _CONSTANTS
#define _CONSTANTS

#include <string>
using namespace std;


namespace TEXT
{
	static const string GAME_TITLE = "EvoGyre";
	static const string BACK_STORY =
		"In the year 2143, we lost Ganymede to an alien invasion. "
		"It had held a colony of over 30,000 humans and was unprepared for war. Now, 22 years later, "
		"we will take Ganymede back and solidify our dominion over the Solar System! With recent discoveries in tranverse photolithic "
		"shielding and improved armaments, those invaders don't "
		"stand a chance!";
	static const string KEY_CONTROLS =
		"Space or W  --  Fire lasers\n"
		"Left/Right Arrow  --  Strafe left/right (rotate)\n"
		"Down Arrow  --  Toggle fixed or rotating ship\n"
		"\n"
		"Collect blue and red tiles to strengthen shields and improve weapons.";
	static const string TOUCH_CONTROLS =
		"Lasers fire continuously\n"
		"Bottom blue arrows  --  Strafe left/right (rotate)\n"
		"Top right icon --  Toggle fixed or rotating ship\n"
		"\n"
		"Collect blue and red tiles to strengthen shields and improve weapons.";
}

namespace FILENAME
{
	static const string PLAYER = "Assets/Art/playerB.png";
}

namespace SETTING
{
	static const int PLAYER_HEALTH = 100;
	static const float PLAYER_START_ANGLE = 290;
	static const float SHIELD_RADIUS = 20;
	static const float SHIELD_WIDTH_MULTIPLIER = 1.3f;

	static const int FUNNEL_CURVE = 3;
	static const float VANISHING_STRETCH = 3;
	static const int NUMBER_OF_STARS = 512;
	static const float PROJECTION_RADIUS = 280;
	static const float MAP_SIZE_X = 3 * 360;
	static const float MAP_SIZE_Y_360 = 360;  // Do not change this
	static const float GAME_PLAY_SIZE = 600;
}

#endif // !_CONSTANTS