#pragma once
#include "Entidad.h"

class Player : public Entidad {
	int initCol;
	int initX, initY;
	int lives;
	int points;
	bool isInBonus;
public:
	Player(int lives) : Entidad(0, 0, 10, 0, 14, 4) {
		initCol = 10;
		initX = 0;
		initY = 0;
		points = 0;
		isInBonus = false;
		this->lives = lives;
	}

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
		x = initX;
		y = initY;
	}

	void decreaseLives() {
		--lives;
		if (lives <= 0) active = false;
	}

	void increasePoints() {
		++points;
	}

	void setIsInBonus(bool state) {
		isInBonus = state;
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
