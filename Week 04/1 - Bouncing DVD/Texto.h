#pragma once
#include <iostream>
#include <string>

class Texto {
private:
	std::string valor;
	int x, y;
	int w, h;
	int dx, dy;
	int color;
public:
	Texto(std::string valor, int width, int height) {
		System::Random gen;

		this->valor = valor;

		this->w = this->valor.size();
		this->h = 1;

		this->x = (width - this->w) / 2;
		this->y = (height - this->h) / 2;

		int dir[2] = { -1, 1 };
		this->dx = dir[gen.Next(0, 2)];
		this->dy = dir[gen.Next(0, 2)];

		// this->dx = (gen.Next(0, 2) ? 1 : -1);
		// this->dy = (gen.Next(0, 2) ? 1 : -1);

		this->color = gen.Next(1, 16);
	}

	~Texto() { }

	void imprimir() {
		System::Console::ForegroundColor = (System::ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << this->valor;
	}

	void borrar() {
		for (int i = 0; i < this->w; ++i) {
			System::Console::SetCursorPosition(this->x + i, this->y);
			std::cout << ' ';
		}
	}

	void mover(int width, int height) {
		if (this->x + this->dx < 0 || this->x + this->w + this->dx > width){
			this->dx *= -1;
			this->cambiarColor();
		}

		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) {
			this->dy *= -1;
			this->cambiarColor();
		}

		this->x += this->dx;
		this->y += this->dy;
	}

	void cambiarColor() {
		++this->color;
		if (this->color == 16) this->color = 1;
	}
};