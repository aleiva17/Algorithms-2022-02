#include <iostream>
#include <conio.h>
#include "Controller.h"

int main() {
	const int WIDTH = 60;
	const int HEIGHT = 40;
	
	char t;
	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	Controller* app = new Controller(WIDTH, HEIGHT);

	while (!app->hemosSidoInvadidos()) {
		if (_kbhit()) {
			t = _getch();
			if (toupper(t) == 'A') app->agregarNaveAlfa();
			_flushall();
		}

		app->mostrarAnimacion();
		_sleep(150);
	}

	system("cls");
	System::Console::SetCursorPosition((WIDTH - 21) / 2, HEIGHT / 2);
	std::cout << "HEMOS SIDO INVADIDOS!";

	delete app;
	system("pause>0");
	return 0;
}