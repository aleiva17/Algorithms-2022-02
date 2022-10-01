#pragma once
#include "Entidad.h"

class Bala : public Entidad {
private:
	bool yaReboto, estaActivo;
public:
	Bala(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;

		this->dx = dx;
		this->dy = dy;
		
		this->w = 1;
		this->h = 1;

		this->yaReboto = false;
		this->estaActivo = true;
	}

	~Bala() { }

	void imprimir() {
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << 'O';
	}

	void mover(int width, int height) {
		
		if (this->x + this->dx < 0 || this->x + this->dx > width) {
			if (this->yaReboto) {
				this->estaActivo = false;
			}
			else {
				this->yaReboto = true;
				this->dx *= -1;
			}
		}

		if (this->y + this->dy < 0 || this->y + this->dy > height) {
			if (this->yaReboto) {
				this->estaActivo = false;
			}
			else {
				this->yaReboto = true;
				this->dy *= -1;
			}
		}

		if (this->estaActivo) {
			this->x += this->dx;
			this->y += this->dy;
		}
	}

	void setEstaActivo(bool estado) {
		this->estaActivo = estado;
	}

	bool getEstaActivo() {
		return this->estaActivo;
	}
};