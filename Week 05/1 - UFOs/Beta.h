#pragma once
#include "Nave.h"

class Beta : public Nave {
private:
	int color;
public:
	Beta(int width) : Nave(4, 11, 3) {
		this->x = (width - this->w) / 2;
		this->y = 0;
		this->color = 12;
	}

	~Beta() { }

	/*
		 .---.
	 _/__~0_\_ 
	(_________) 
	*/
	void imprimir() {
		System::Console::ForegroundColor = (System::ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "   .---.";
		System::Console::SetCursorPosition(this->x, this->y + 1);
		std::cout << " _/__~0_\\_";
		System::Console::SetCursorPosition(this->x, this->y + 2);
		std::cout << "(_________)";
	}
};