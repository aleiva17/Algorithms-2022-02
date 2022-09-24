#pragma once
#include "Raton.h"
#include <vector>

class VectorRatones {
private:
	std::vector<Raton*> ratones;
	int tiempoInicio;
public:
	VectorRatones(int n, int width, int height) {
		this->tiempoInicio = time(0);
		while (n--) {
			this->agregarRaton(width, height);
			_sleep(100);
		}
	}

	~VectorRatones() {
		for (Raton* rat : this->ratones) {
			delete rat;
		}
		this->ratones.clear();
	}

	void agregarRaton(int width, int height) {
		System::Random gen;
		Raton* rat = new Raton();
		rat->setX(gen.Next(0, width - rat->getW()));
		rat->setY(gen.Next(0, height - rat->getH()));
		this->ratones.push_back(rat);
	}
	
	void verificarTiempo(int width, int height) {
		if (difftime(time(0), this->tiempoInicio) < 2) return;
		this->agregarRaton(width, height);
		this->tiempoInicio = time(0);
	}

	void gestionRatones(int width, int height) {
		this->verificarTiempo(width, height);
		for (Raton* rat : this->ratones) {
			rat->borrar();
			rat->mover(width, height);
			rat->imprimir();
		}
		this->eliminarRatones();
	}

	void eliminarRatones() {
		for (int i = 0; i < this->ratones.size(); ++i) {
			if (this->ratones.at(i)->getActivo()) continue;
			this->ratones.at(i)->borrar();
			this->ratones.erase(this->ratones.begin() + i);
			break;
		}
	}

	std::vector<Raton*>& getRatones() {
		return this->ratones;
	}
};