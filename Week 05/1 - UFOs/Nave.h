#pragma once
#include <iostream>

class Nave {
protected:
	int x, y;
	int dx, dy;
	int w, h;
public:
	Nave(int dy, int w, int h) {
		this->x = 0;
		this->y = 0;
		this->dx = 0;
		this->dy = dy;
		this->w = w;
		this->h = h;
	}

	~Nave() { }

	void borrar() {
		for (int i = this->x; i < this->x + this->w; ++i) {
			for (int j = this->y; j < this->y + this->h; ++j) {
				System::Console::SetCursorPosition(i, j);
				std::cout << ' ';
			}
		}
	}

	void mover(int width, int height) {
		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) this->dy *= -1;

		this->y += this->dy;
	}
};