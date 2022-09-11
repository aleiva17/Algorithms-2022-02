#include <iostream>
#include <conio.h>
#include "Controller.h"

int main() {
	const int WIDTH = 80;
	const int HEIGHT = 20;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	int n;
	char t;

	do {
		std::cout << "Ingrese la cantidad de aviones (2 - 5): ";
		std::cin >> n;
	} while (n < 2 || n > 5);
	
	Controller* app = new Controller(n, WIDTH, HEIGHT);
	system("cls");

	while (true) {
		if (_kbhit()) {
			t = _getch();
			t = toupper(t);

			if (t == 'E') break;

			_flushall();
		}

		app->runApp();
		_sleep(150);
	}

	delete app;
	return 0;
}