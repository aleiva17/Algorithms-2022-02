#pragma once
#include "Enemigo.h"

class EnemigoB : public Enemigo {
public:
	EnemigoB(int width, int height) : Enemigo(2) {
		System::Random gen;

		this->color = System::ConsoleColor::Green;

		this->w = 7;
		this->h = 2;

		int dir[2] = { -1, 1 };
		this->dx = dir[gen.Next(0, 2)] * 2;
		this->dy = dir[gen.Next(0, 2)] * 2;

		this->x = gen.Next(0, width - this->w);
		this->y = gen.Next(0, height - this->h);
	}
	
	~EnemigoB() { }

	// | - - |
	// | - - |
	void imprimir() {
		System::Console::ForegroundColor = this->color;
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "| - - |";
		System::Console::SetCursorPosition(this->x, this->y + 1);
		std::cout << "| - - |";
		System::Console::ForegroundColor = System::ConsoleColor::White;
	}

	void mover(int width, int height) {
		if (this->x + this->dx < 0 || this->x + this->dx + this->w > width) this->dx *= -1;
		if (this->y + this->dy < 0 || this->y + this->dy + this->h > height) this->dy *= -1;
	
		this->x += this->dx;
		this->y += this->dy;
	}
};