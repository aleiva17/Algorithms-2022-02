#pragma once
#include "Entidad.h"

class Bonus : public Entidad {
public:
	Bonus() {
		System::Random^ gen = gcnew System::Random();
		
		active = true;

		x = gen->Next(120, 481);
		y = gen->Next(120, 481);

		col = gen->Next(0, 4);
		row = 0;
		maxCol = 4;
		maxRow = 1;

		delete gen;
	}

	~Bonus() { }

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		w = bmp->Width / maxCol;
		h = bmp->Height / maxRow;
		Rectangle porcion = Rectangle(col * w, row * h, w, h);

		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	}
};