#pragma once
#include "Entidad.h"

class Raton : public Entidad {
private:
	bool activo;
public:
	Raton() : Entidad() {
		System::Random gen;
		int direccion[2] = { 1, -1 };

		this->dx = direccion[gen.Next(0, 2)] * 3;
		this->dy = direccion[gen.Next(0, 2)] * 3;
		
		this->w = 7;
		this->h = 1;
	}

	~Raton() { }

	void imprimir() {
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "--(_c'>";
	}

	void mover(int width, int height) {
		if (this->x + this->dx < 0 || this->x + this->w + this->dx > width) this->dx *= -1;
		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) this->dy *= -1;
		this->x += this->dx;
		this->y += this->dy;
	}

	void setActivo(bool estado) {
		this->activo = estado;
	}

	bool getActivo() {
		return this->activo;
	}
};