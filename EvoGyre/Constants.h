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
	static const string DIR = "Assets/Art/";
	static const string PLAYER = DIR + "playerB.png";
	static const string PLANET = "Assets/sprites/planets/lavender.png";

	// Bullets
	static const string BLUELASER = "Assets/sprites/shots/bluelaser.png";
	static const string REDLASER = "Assets/sprites/shots/redlaser.png";
	static const string ROUND_LG = "Assets/sprites/shots/round_lg.png";
	static const string ROUND_SM = "Assets/sprites/shots/round_sm.png";
	static const string SHARPLASER = "Assets/sprites/shots/sharp.png";
}

namespace SETTING
{
	static const int PLAYER_HEALTH = 100;
	static const float PLAYER_START_ANGLE = 290;
	static const float SHIELD_RADIUS = 20;
	static const float SHIELD_WIDTH_MULTIPLIER = 1.3f;
	static const float PLAYER_ACCELERATION = 0.3f;
	static const float PLAYER_MAX_VELOCITY = 2.f;
	static const float PLAYER_MOTION_FRICTION = 0.88f;

	static const int FUNNEL_CURVE = 3;
	static const float VANISHING_STRETCH = 3;
	static const int NUMBER_OF_FIXED_STARS = 256;
	static const int NUMBER_OF_SHOOTING_STARS = 128;
	static const float SHOOTING_STAR_SPEED = 6;
	static const float PROJECTION_RADIUS = 460;  // Was 280 when centered
	static const float MAP_SIZE_X = 1080;
	static const float MAP_SIZE_Y_360 = 360;  // Do not change this
	static const float DISPLAY_SIZE_X = 900;
	static const float DISPLAY_SIZE_Y = 900;
	static const float GAME_CENTER_X = DISPLAY_SIZE_X * 0.5f;
	static const float GAME_CENTER_Y = DISPLAY_SIZE_Y * 0.5f;
	static const float CENTER_DISPLACEMENT = 0.6f * PROJECTION_RADIUS;

}

namespace PLAYER_WEAPONS
{
	
}

#endif // !_CONSTANTS