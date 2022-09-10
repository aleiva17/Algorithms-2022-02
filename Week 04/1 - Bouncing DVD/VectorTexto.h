#pragma once
#include "Texto.h"

class VectorTexto {
private:
	Texto** textos;
	int cant;
public:
	VectorTexto() {
		this->textos = nullptr;
		this->cant = 0;
	}

	~VectorTexto() {
		for (int i = 0; i < this->cant; ++i) {
			delete this->textos[i];
		}
		delete[] this->textos;
	}

	void agregarTexto(Texto* txt) {
		Texto** temp = new Texto * [this->cant + 1];

		for (int i = 0; i < this->cant; ++i) {
			temp[i] = this->textos[i];
		}

		temp[this->cant] = txt;

		delete[] this->textos;
		this->textos = temp;

		++this->cant;
	}

	void eliminarTexto() {
		if (this->cant == 0) return;

		this->textos[this->cant - 1]->borrar();
		Texto** temp = new Texto * [this->cant - 1];

		for (int i = 0; i < this->cant - 1; ++i) {
			temp[i] = this->textos[i];
		}
		
		delete[] this->textos;
		this->textos = temp;

		--this->cant;
	}

	void mostrarTextos(int width, int height) {
		for (int i = 0; i < this->cant; ++i) {
			this->textos[i]->borrar();
			this->textos[i]->mover(width, height);
			this->textos[i]->imprimir();
		}
	}
};
