#pragma once
#include "Entidad.h"

class Pacman : public Entidad {
	int lives;
	int points;
	int initCol;
	bool isInBonus;
public:
	Pacman(int lives) : Entidad(0, 0, 10, 0, 14, 4) {
		this->lives = lives;
		initCol = 10;
		points = 0;
		isInBonus = false;
	}

	~Pacman() { }

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		w = bmp->Width / maxCol;
		h = bmp->Height / maxRow;
		Rectangle porcion = Rectangle(col * w, row * h, w, h);

		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

		col++;
		if (col == initCol + 2) col = initCol;
	}

	void desplazamiento(direccion d) {
		dx = 0;
		dy = 0;
		orientacion = d;

		switch (d) {
		case direccion::up:
			dy = -10 * (isInBonus ? 2 : 1);
			row = 3;
			break;
		case direccion::down:
			dy = 10 * (isInBonus ? 2 : 1);
			row = 1;
			break;
		case direccion::left:
			dx = -10 * (isInBonus ? 2 : 1);
			row = 2;
			break;
		case direccion::right:
			dx = 10 * (isInBonus ? 2 : 1);
			row = 0;
		}
	}

	void respawn() {
		x = 0;
		y = 0;
	}

	void increasePoints() {
		++points;
	}

	void decreaseLives() {
		--lives;
		if (lives == 0) active = false;
	}

	void setIsInBonus(bool state) {
		isInBonus = state;
		desplazamiento(orientacion);
	}

	int getLives() {
		return lives;
	}
	
	int getPoints() {
		return points;
	}

	bool getIsInBonus() {
		return isInBonus;
	}
};