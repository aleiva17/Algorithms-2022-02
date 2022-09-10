#pragma once
#include "VectorTexto.h"

class Controller {
private:
	VectorTexto* textos;
	int width, height;
public:
	Controller(std::string valor, int width, int height) {
		this->textos = new VectorTexto();
		this->width = width;
		this->height = height;
	}

	~Controller() {
		delete this->textos;
	}

	void gestionarTecla(char t) {
		if (t == 'A') {
			this->textos->agregarTexto(new Texto("DVD", this->width, this->height));
		}
		else if (t == 'B') {
			this->textos->eliminarTexto();
		}
	}

	void runApp() {
		this->textos->mostrarTextos(this->width, this->height);
	}
};