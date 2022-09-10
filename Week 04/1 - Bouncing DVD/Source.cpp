#include <iostream>
#include <conio.h>
#include "Controller.h"

int main() {
	const int WIDTH = 60;
	const int HEIGHT = 20;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	Controller* app = new Controller("DVD", WIDTH, HEIGHT);

	while (true) {
		if (_kbhit()) {
			char t = _getch();
			t = toupper(t);

			if (t == 'E') break;
			
			app->gestionarTecla(t);
			_flushall();
		}

		app->runApp();
		_sleep(150);
	}

	delete app;
	return 0;
}