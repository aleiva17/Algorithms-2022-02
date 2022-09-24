#pragma once
#include <iostream>

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int w, h;
public:
	Entidad() {
		this->x = 0;
		this->y = 0;
		this->dx = 0;
		this->dy = 0;
		this->w = 0;
		this->h = 0;
	}

	~Entidad() { }

	void borrar() {
		for (int i = this->x; i < this->x + this->w; ++i) {
			for (int j = this->y; j < this->y + this->h; ++j) {
				System::Console::SetCursorPosition(i, j);
				std::cout << ' ';
			}
		}
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	int getW() {
		return this->w;
	}

	int getH() {
		return this->h;
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(this->x, this->y, this->w, this->h);
	}
};