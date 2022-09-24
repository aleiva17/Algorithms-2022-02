#pragma once
#include "Entidad.h"

class Gato : public Entidad {
private:
	int cantRatonesAtrapados;
	int color;
public:
	Gato() : Entidad() {
		this->cantRatonesAtrapados = 0;
		this->w = 7;
		this->h = 3;
		this->color = 1;
	}

	~Gato() { }

	void imprimir() {
		System::Console::ForegroundColor = (System::ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << " /\\_/\\";
		System::Console::SetCursorPosition(this->x, this->y + 1);
		std::cout << "( o.o )";
		System::Console::SetCursorPosition(this->x, this->y + 2);
		std::cout << " > ^ <";
		System::Console::ForegroundColor = System::ConsoleColor::White;
	}

	void cambiarDireccion(char t) {
		switch (t) {
		case 'W': // UP
			this->dx = 0;
			this->dy = -2;
			break;
		case 'S': // DOWN
			this->dx = 0;
			this->dy = 2;
			break;
		case 'A': // LEFT
			this->dx = -2;
			this->dy = 0;
			break;
		case 'D': // RIGHT
			this->dx = 2;
			this->dy = 0;
		}
	}

	void cambiarColor() {
		++this->color;
		if (this->color > 15) this->color = 1;
	}

	void mover(int width, int height) {
		if (this->x + this->dx < 0 || this->x + this->w + this->dx > width) this->dx = 0;
		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) this->dy = 0;
		this->x += this->dx;
		this->y += this->dy;
	}

	void agregarRatonCapturado() {
		++this->cantRatonesAtrapados;
	}

	int getCantRatonesAtrapados() {
		return this->cantRatonesAtrapados;
	}
};