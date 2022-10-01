#pragma once
#include "Entidad.h"

class Enemigo : public Entidad {
protected:
	int id;
	System::ConsoleColor color;
	bool estaActivo;
public:
	Enemigo(int id) {
		this->id = id;
	}

	~Enemigo() { }

	int getId() {
		return this->id;
	}

	void setEstaActivo(bool estado) {
		this->estaActivo = estado;
	}

	bool getEstaActivo() {
		return this->estaActivo;
	}
};