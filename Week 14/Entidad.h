#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;

public enum direccion { up, down, left, right, none };

class Entidad {
protected:
	int x, y, dx, dy, w, h;
	int row, col, maxRow, maxCol;
	direccion orientacion;
	bool active;
public:
	Entidad();
	Entidad(int x, int y, int col, int row, int maxCol, int maxRow);
	Entidad(int col, int row, int maxCol, int maxRow);
	~Entidad();

	virtual void mostrar(Graphics^ g, Bitmap^ bmp);
	virtual void mover(Graphics^ g);
	virtual void desplazamiento(direccion d);

	void setX(int x);
	void setY(int y);
	void setDx(int dx);
	void setDy(int dy);
	void setW(int w);
	void setH(int h);
	void setRow(int r);
	void setCol(int c);
	void setMaxRow(int r);
	void setMaxCol(int c);
	void setActive(bool state);
	void setOrientacion(direccion d);

	int getX();
	int getY();
	int getDx();
	int getDy();
	int getW();
	int getH();
	int getRow();
	int getCol();
	int getMaxRow();
	int getMaxCol();
	bool getActive();
	direccion getOrientacion();
	Rectangle getArea();
	Rectangle getNextArea();
};

Entidad::Entidad() {
	dx = 0;
	dy = 0;
	active = true;
	orientacion = direccion::none;
}

Entidad::Entidad(int x, int y, int col, int row, int maxCol, int maxRow) {
	this->x = x;
	this->y = y;
	this->col = col;
	this->row = row;
	this->maxCol = maxCol;
	this->maxRow = maxRow;

	orientacion = direccion::none;
	dx = 0;
	dy = 0;
	active = true;
}

Entidad::Entidad(int col, int row, int maxCol, int maxRow) {
	this->col = col;
	this->row = row;
	this->maxCol = maxCol;
	this->maxRow = maxRow;

	orientacion = direccion::none;
	dx = 0;
	dy = 0;
	active = true;
}

Entidad::~Entidad() { }

void Entidad::mostrar(Graphics^ g, Bitmap^ bmp) {
	w = bmp->Width / maxCol;
	h = bmp->Height / maxRow;
	Rectangle porcion = Rectangle(col * w, row * h, w, h);

	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	col++;
	if (col == maxCol) col = 0;
}

void Entidad::mover(Graphics^ g) {
	if (x + dx >= 0 && x + w + dx < g->VisibleClipBounds.Width) x += dx;
	if (y + dy >= 0 && y + h + dy < g->VisibleClipBounds.Height) y += dy;
}

void Entidad::desplazamiento(direccion d) {
	dx = 0;
	dy = 0;
	orientacion = d;

	switch (d) {
	case direccion::up:
		dy = -10;
		row = 3;
		break;
	case direccion::down:
		dy = 10;
		row = 0;
		break;
	case direccion::left:
		dx = -10;
		row = 1;
		break;
	case direccion::right:
		dx = 10;
		row = 2;
	}
}

void Entidad::setX(int x) {
	this->x = x;
}

void Entidad::setY(int y) {
	this->y = y;
}

void Entidad::setDx(int dx) {
	this->dx = dx;
}

void Entidad::setDy(int dy) {
	this->dy = dy;
}

void Entidad::setW(int w) {
	this->w = w;
}

void Entidad::setH(int h) {
	this->h = h;
}

void Entidad::setRow(int r) {
	row = r;
}

void Entidad::setCol(int c) {
	col = c;
}

void Entidad::setMaxRow(int r) {
	maxRow = r;
}

void Entidad::setMaxCol(int c) {
	maxCol = c;
}

void Entidad::setActive(bool state) {
	active = state;
}

void Entidad::setOrientacion(direccion d) {
	orientacion = d;
}

int Entidad::getX() {
	return x;
}

int Entidad::getY() {
	return y;
}

int Entidad::getDx() {
	return dx;
}

int Entidad::getDy() {
	return dy;
}

int Entidad::getW() {
	return w;
}

int Entidad::getH() {
	return h;
}

int Entidad::getRow() {
	return row;
}

int Entidad::getCol() {
	return col;
}

int Entidad::getMaxRow() {
	return maxRow;
}

int Entidad::getMaxCol() {
	return maxCol;
}

bool Entidad::getActive() {
	return active;
}

direccion Entidad::getOrientacion() {
	return orientacion;
}

Rectangle Entidad::getArea() {
	return Rectangle(x, y, w, h);
}

Rectangle Entidad::getNextArea() {
	return Rectangle(x + dx, y + dy, w, h);
}