#include <iostream>
#include <conio.h>
#include "Controller.h"

int main() {
	const int WIDTH = 80;
	const int HEIGHT = 40;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	char t;
	Controller* game = new Controller(4, WIDTH, HEIGHT);

	while (!game->getTermino()) {
		if (_kbhit()) {
			t = _getch();
			game->gestionarTecla(toupper(t));
			_flushall();
		}

		game->gestionarJuego();
		_sleep(150);
	}

	system("cls");
	
	System::Console::SetCursorPosition((WIDTH - 7) / 2, HEIGHT / 2);
	if (game->getGane()) {
		System::Console::ForegroundColor = System::ConsoleColor::Green;
		std::cout << "GANASTE";
	}
	else {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "PERDISTE";
	}
	
	system("pause>0");
	return 0;
}