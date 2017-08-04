#include "Engine\Engine.h"
#include "EvoGyre\Player.h"
#include "EvoGyre\Background.h"
#include "EvoGyre\Constants.h"

typedef float degree;

int main()
{
	static degree game_rotation = 0;
	static degree player_rotation = 270;

	cout << "Running EvoGyre..." << endl;
	cout << TEXT::KEY_CONTROLS << endl;

	Engine engine;

	engine.Initialize("EvoGyre!", (int) SETTING::DISPLAY_SIZE_X, (int) SETTING::DISPLAY_SIZE_X);

	Player player(FILENAME::PLAYER, 1000, player_rotation);
	Background background(FILENAME::PLANET);

	while (true)
	{
		engine.Update();
		double dt = 60.0 * engine.GetDT();  // Around 1.0

		if (!engine.IsPaused())
		{
			player.Update(dt);
			player_rotation = player.GetPos().y;
			GAME_PROJECTION::SetVanishingPoint(player_rotation + 180.f);
			background.Update(dt);
		}

		engine.BeginRender();
		{ // RENDER ALL ITEMS
			background.Render(game_rotation);
			player.Render();
		}
		engine.EndRender();
	}

	return 0;
}