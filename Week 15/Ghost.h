#pragma once
#include "Entidad.h"

class Ghost : public Entidad {
	int initCol;
public:
	Ghost() {
		System::Random^ gen = gcnew System::Random();

		x = gen->Next(120, 481);
		y = gen->Next(120, 481);

		dx = (gen->Next(0, 1) ? 1 : -1) * gen->Next(10, 21);
		dy = (gen->Next(0, 1) ? 1 : -1) * gen->Next(10, 21);

		initCol = gen->Next(0, 5) * 2;

		col = initCol;
		row = 0;
		maxCol = 14;
		maxRow = 4;

		delete gen;
	}

	~Ghost() { }

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		w = bmp->Width / maxCol;
		h = bmp->Height / maxRow;
		Rectangle porcion = Rectangle(col * w, row * h, w, h);

		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

		col++;
		if (col == initCol + 2) col = initCol;
	}

	void mover(Graphics^ g) {
		if (x + dx < 0 || x + w + dx >= g->VisibleClipBounds.Width) dx *= -1;
		if (y + dy < 0 || y + h + dy >= g->VisibleClipBounds.Height) dy *= -1;

		y += dy;
		x += dx;
	}
};