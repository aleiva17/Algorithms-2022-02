#pragma once
#include "Entidad.h"

class Bonus : public Entidad {
public:
	Bonus(int x, int y, int col) : Entidad(x, y, col, 0, 4, 1) { }
	~Bonus() { }

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		w = bmp->Width / maxCol;
		h = bmp->Height / maxRow;
		Rectangle porcion = Rectangle(col * w, row * h, w, h);

		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	}
};