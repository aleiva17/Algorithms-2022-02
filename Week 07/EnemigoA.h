#pragma once
#include "Enemigo.h"

class EnemigoA : public Enemigo {
public:
	EnemigoA(int width, int height) : Enemigo(1) {
		System::Random gen;

		this->color = System::ConsoleColor::Cyan;
		
		this->w = 7;
		this->h = 1;

		this->x = gen.Next(0, width - this->w);
		this->y = gen.Next(0, height - this->h);
	}


	~EnemigoA() { }

	// [ = = ]
	void imprimir() {
		System::Console::ForegroundColor = this->color;
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "[ = = ]";
		System::Console::ForegroundColor = System::ConsoleColor::White;
	}
};