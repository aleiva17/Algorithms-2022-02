#include "Controller.h"
#include <conio.h>

int main() {
	const int WIDTH = 60;
	const int HEIGHT = 40;
	const int CANTIDAD_RATONES = 4;
	const std::string MENSAJE_VICTORIA = "FELICIDADES, GANASTE!";

	char t;
	bool light = true;
	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	Controller* game = new Controller(WIDTH, HEIGHT, CANTIDAD_RATONES);

	while (!game->isGameOver()) {
		if (_kbhit()) {
			t = _getch();
			game->gestionTecla(toupper(t));
			_flushall();
		}

		game->runGame();
		_sleep(150);
	}

	system("cls");

	while (true) {
		if (_kbhit()) break;
		System::Console::ForegroundColor = (System::ConsoleColor)(light ? 14 : 6);
		System::Console::SetCursorPosition((WIDTH - MENSAJE_VICTORIA.length()) / 2, HEIGHT / 2);
		std::cout << MENSAJE_VICTORIA;
		light = !light;
		_sleep(250);
	}

	delete game;
	return 0;
}