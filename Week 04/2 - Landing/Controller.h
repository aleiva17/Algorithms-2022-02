#pragma once
#include "Avion.h"

class Controller {
private:
	Avion** aviones;
	int n;
	int width, height;
public:
	Controller(int n, int width, int height) {
		this->n = n;
		this->width = width;
		this->height = height;
		this->generarAviones();
	}

	~Controller() {
		for (int i = 0; i < this->n; ++i) {
			delete this->aviones[i];
		}
		delete[] this->aviones;
	}

	void generarAviones() {
		this->aviones = new Avion * [this->n];
		for (int i = 0; i < this->n; ++i) {
			this->aviones[i] = new Avion(this->width, this->height);
			_sleep(100);
		}
	}

	void borrarAviones() {
		for (int i = 0; i < this->n; ++i) {
			this->aviones[i]->borrar();
		}
	}

	void moverAviones() {
		for (int i = 0; i < this->n; ++i) {
			if (this->aviones[i]->yaAterrizo()) continue;
			this->aviones[i]->mover(this->width, this->height);
		}
	}

	void imprimirAviones() {
		for (int i = 0; i < this->n; ++i) {
			this->aviones[i]->imprimir();
		}
	}

	void runApp() {
		this->borrarAviones();
		this->moverAviones();
		this->imprimirAviones();
	}
};
