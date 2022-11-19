#pragma once
#include "Entidad.h"

class Ghost : public Entidad {
	int initCol;
public:
	Ghost(int x, int y, int initCol) : Entidad(x, y, initCol, 0, 14, 4) {
		Random^ gen = gcnew Random();
		this->initCol = initCol;
		
		dx = 10 * (gen->Next(0, 2) ? 1 : -1);
		dy = 10 * (gen->Next(0, 2) ? 1 : -1);

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
		x += dx;
		y += dy;
	}
};