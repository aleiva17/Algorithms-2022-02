#pragma once
#include "Nave.h"

class Gamma : public Nave {
private:
	int color;
public:
	Gamma(int width) : Nave(2, 19, 10) {
		this->x = width - this->w;
		this->y = 0;
		this->color = 11;
	}

	~Gamma() { }

	void imprimir() {
		System::Console::ForegroundColor = (System::ConsoleColor)this->color;
		System::Console::SetCursorPosition(x, y);
		std::cout << "         .";
		System::Console::SetCursorPosition(x, y + 1);
		std::cout << "         |";
		System::Console::SetCursorPosition(x, y + 2);
		std::cout << "      .-\" ^ \"-.";
		System::Console::SetCursorPosition(x, y + 3);
		std::cout << "     /_....._\\";
		System::Console::SetCursorPosition(x, y + 4);
		std::cout << " .-\"`         `\"-.";
		System::Console::SetCursorPosition(x, y + 5);
		std::cout << "(  ooo  ooo  ooo  )";
		System::Console::SetCursorPosition(x, y + 6);
		std::cout << " '-.,_________,.-'";
		System::Console::SetCursorPosition(x, y + 7);
		std::cout << "     /       \\";
		System::Console::SetCursorPosition(x, y + 8);
		std::cout << "   _/         \\_";
		System::Console::SetCursorPosition(x, y + 9);
		std::cout << "  `\"`         `\"`";
	}
};