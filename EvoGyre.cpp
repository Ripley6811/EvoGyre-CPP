#include "Engine\Engine.h"
#include "Engine\Input.h"
#include "EvoGyre\Player.h"
#include "EvoGyre\Background.h"
#include "EvoGyre\Constants.h"

int main()
{
	cout << "Running EvoGyre..." << endl;
	cout << TEXT::KEY_CONTROLS << endl;

	Engine engine;

	engine.Initialize("EvoGyre!", (int) SETTING::DISPLAY_SIZE_X, (int) SETTING::DISPLAY_SIZE_X);

	Player player(FILENAME::PLAYER, 1000, 270);
	Background background(FILENAME::PLANET);

	while (true)
	{
		engine.Update();

		if (!engine.IsPaused())
		{
			player.Update();
			background.Update();
		}

		engine.BeginRender();
		{
			player.Render();
			background.Render();
		}
		engine.EndRender();
	}

	return 0;
}