#pragma once
#include "Fuselaje.h"
#include "Alas.h"
#include "TrenAterrizaje.h"

class Avion {
private:
	Fuselaje* fuselaje;
	Alas* alas;
	TrenAterrizaje* tAterrizaje;

	int initX;
	int maxDiffX;
	int x, y;
	int dx, dy;
	int dxMax;
	int w, h;
	int ySuelo;
public:
	Avion(int width, int height) {
		System::Random gen;

		this->fuselaje = new Fuselaje();
		this->alas = new Alas();
		this->tAterrizaje = new TrenAterrizaje();

		this->w = 11;
		this->h = 3;

		this->initX = gen.Next(this->w, width - this->w);
		this->x = initX;
		this->y = 0;

		this->maxDiffX = 3;
		this->dy = 1;

		int dir[2] = { -1, 1 };
		this->dx = dir[gen.Next(0, 2)] * 3;

		this->ySuelo = height;
	}

	~Avion() {
		delete this->fuselaje, this->alas, this->tAterrizaje;
	}

	/*
		   __|__
		*___oOo___*
		    * *
	*/

	void imprimir() {
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "   ";
		this->fuselaje->imprimir();

		System::Console::SetCursorPosition(this->x, this->y + 1);
		this->alas->imprimir();

		System::Console::SetCursorPosition(this->x, this->y +	2);
		std::cout << "    ";
		this->tAterrizaje->imprimir();
	}

	void borrar() {
		System::Console::SetCursorPosition(this->x, this->y);
		std::cout << "   ";
		this->fuselaje->borrar();

		System::Console::SetCursorPosition(this->x, this->y + 1);
		this->alas->borrar();

		System::Console::SetCursorPosition(this->x, this->y + 2);
		std::cout << "    ";
		this->tAterrizaje->borrar();
	}

	void mover(int width, int height) {
		this->y += this->dy;

		int newX = this->x + this->dx;
		if (abs(newX - this->initX) >= this->maxDiffX) this->dx *= -1;

		this->x += this->dx;
	}

	bool yaAterrizo() {
		return this->y + this->dy >= this->ySuelo;
	}
};
