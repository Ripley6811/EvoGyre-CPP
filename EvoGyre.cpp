#include "Engine\Engine.h"
#include "Engine\Input.h"
#include "EvoGyre\Player.h"
#include "EvoGyre\Constants.h"

int main()
{
	cout << "Running EvoGyre..." << endl;
	cout << TEXT::KEY_CONTROLS << endl;

	Engine engine;

	engine.Initialize("EvoGyre!", (int) SETTING::GAME_PLAY_SIZE, (int) SETTING::GAME_PLAY_SIZE);

	Player player(FILENAME::PLAYER, 1000, 10);

	while (true)
	{
		engine.Update();
		cout << engine.GetDT() << endl;
		if (!engine.IsPaused())
		{
			player.Update();
		}

		engine.BeginRender();
		player.Render();


		engine.EndRender();
	}

	return 0;
}