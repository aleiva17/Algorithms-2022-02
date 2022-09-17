#pragma once
#include "Nave.h"

class Alfa : public Nave {
private:
	int color;
public:
	Alfa() : Nave(3, 19, 5) {
		this->x = 0;
		this->y = 0;
		this->color = 14;
	}

	~Alfa() { }

	/*
       _.---._ 
        .' '.
 _.-~===========~-._
 (_________________) 
      \_______/ 
	*/
	void imprimir() {
		System::Console::ForegroundColor = (System::ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "      _.---._";
		System::Console::SetCursorPosition(this->x, this->y + 1);
		std::cout << "       .' '.";
		System::Console::SetCursorPosition(this->x, this->y + 2);
		std::cout << "_.-~===========~-._";
		System::Console::SetCursorPosition(this->x, this->y + 3);
		std::cout << "(_________________)";
		System::Console::SetCursorPosition(this->x, this->y + 4);
		std::cout << "     \\_______/";
	}
};