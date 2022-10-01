#pragma once
#include "Entidad.h"
#include "Bala.h"
#include <vector>

class Jugador : public Entidad {
private:
	int vidas;
	int initX, initY;
	std::vector<Bala*> balas;
public:
	Jugador(int initX, int initY) {
		this->x = initX;
		this->y = initY;

		this->initX = initX;
		this->initY = initY;

		this->vidas = 3;

		this->dx = 0;
		this->dy = 0;

		this->h = 3;
		this->w = 5;
	}

	~Jugador() { 
		for (Bala* bala : this->balas) {
			delete bala;
		}
		this->balas.clear();
	}

	void dispararBala() {
		this->balas.push_back(new Bala(this->x, this->y, this->dx / 2, this->dy / 2));
	}

	void gestionarBalas(int width, int height) {
		for (Bala* bala : this->balas) {
			bala->borrar();
			bala->mover(width, height);
			bala->imprimir();
		}

		for (int i = 0; i < this->balas.size(); ++i) {
			if (this->balas[i]->getEstaActivo()) continue;
			this->balas[i]->borrar();
			this->balas.erase(this->balas.begin() + i);
			break;
		}
	}

	void imprimir() {
		System::Console::SetCursorPosition(this->x, this-> y);
		std::cout << "+ - +";
		System::Console::SetCursorPosition(this->x, this-> y + 1);
		std::cout << "| " << this->vidas << " |";
		System::Console::SetCursorPosition(this->x, this-> y + 2);
		std::cout << "+ - +";
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

	void mover(int width, int height) {
		if (this->x + this->dx >= 0 && this->x + this->w + this->dx < width) this->x += this->dx;
		if (this->y + this->dy >= 0 && this->y + this->h + this->dy < height) this->y += this->dy;
	}

	void quitarVida() {
		--this->vidas;
	}

	void resetPosition() {
		this->x = this->initX;
		this->y = this->initY;
	}

	int getVidas() {
		return this->vidas;
	}

	std::vector<Bala*>& getBalas() {
		return this->balas;
	}
};