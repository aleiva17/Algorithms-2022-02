#pragma once
#include "Entidad.h"

public enum color { white, yellow, green, blue };

class Caballo : public Entidad {
private:
	bool isAPlayer;
	int initCol, initRow;
	color colorType;
public:
	Caballo() : Entidad(0, 0, 0, 0, 6, 8) {
		isAPlayer = true;
		this->changeColor(color::white);
	}

	Caballo(int x, int y, color colorType) : Entidad(x, y, 0, 0, 6, 8) {
		Random^ gen = gcnew Random();
		isAPlayer = false;
		this->changeColor(colorType);
		dx = 10 * (gen->Next(0, 2) ? 1 : -1);
		dy = 10 * (gen->Next(0, 2) ? 1 : -1);
	}
	
	~Caballo() { }

	void changeColor(color colorType) {
		this->colorType = colorType;
		switch (this->colorType) {
		case color::white:
			this->initCol = 0;
			this->initRow = 0;
			this->col = 0;
			this->row = 0;
			break;
		case color::yellow:
			this->initCol = 3;
			this->initRow = 0;
			this->col = 3;
			this->row = 0;
			break;
		case color::green:
			this->initCol = 0;
			this->initRow = 4;
			this->col = 0;
			this->row = 4;
			break;
		case color::blue:
			this->initCol = 3;
			this->initRow = 4;
			this->col = 3;
			this->row = 4;
		}
		this->desplazamiento(orientacion);
	}

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		w = bmp->Width / maxCol;
		h = bmp->Height / maxRow;
		Rectangle porcion = Rectangle(col * w, row * h, w, h);

		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
		if (isAPlayer) g->DrawRectangle(gcnew Pen(Color::Blue, 4), Rectangle(x, y, w, h));

		++col;
		if (col == initCol + 3) col = initCol;
	}

	void desplazamiento(direccion d) {
		dx = 0;
		dy = 0;
		orientacion = d;

		switch (d) {
		case direccion::up:
			dy = -10;
			row = initRow + 3;
			break;
		case direccion::down:
			dy = 10;
			row = initRow;
			break;
		case direccion::left:
			dx = -10;
			row = initRow + 1;
			break;
		case direccion::right:
			dx = 10;
			row = initRow + 2;
		}
	}

	void moverRebote(Graphics^ g) {
		if (x + dx < 0 || x + w + dx > g->VisibleClipBounds.Width) dx *= -1;
		if (y + dy < 0 || y + h + dy > g->VisibleClipBounds.Height) dy *= -1;
		x += dx;
		y += dy;
	}
};