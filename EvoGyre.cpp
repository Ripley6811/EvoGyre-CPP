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

	Player player(FILENAME::PLAYER);
	player.SetPos(Vector3(1000, 10, 0));

	while (true)
	{
		engine.Update();
		cout << engine.GetDT() << endl;
		player.Update();

		engine.BeginRender();
		player.Render();

		if (Input::Key(GLFW_KEY_F))
		{
			cout << "F PRESSED" << endl;
		}

		engine.EndRender();
	}

	return 0;
}