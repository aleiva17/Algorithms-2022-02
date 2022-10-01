#pragma once
#include <iostream>

class Entidad {
protected:
	int x, y;
	int h, w;
	int dx, dy;
public:
	Entidad() {
		this->x = 0;
		this->y = 0;
		this->h = 0;
		this->w = 0;
		this->dx = 0;
		this->dy = 0;
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
	
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(this->x, this->y, this->w, this->h);
	}
};