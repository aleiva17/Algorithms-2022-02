#pragma once
#include <vector>
#include "Alfa.h"
#include "Beta.h"
#include "Gamma.h"

class Controller {
private:
	int width, height;
	std::vector<Beta*> betas;
	std::vector<Alfa*> alfas;
	std::vector<Gamma*> gammas;
public:
	Controller(int width, int height) { 
		this->width = width;
		this->height = height;
	}

	~Controller() {
		for (Beta* beta : this->betas) {
			delete beta;
		}
		for (Alfa* alfa : this->alfas) {
			delete alfa;
		}
		for (Gamma* gamma : this->gammas) {
			delete gamma;
		}
		this->betas.clear();
		this->alfas.clear();
		this->gammas.clear();
	}

	void agregarNaveAlfa() {
		this->alfas.push_back(new Alfa());
		if (this->alfas.size() / 2 != this->betas.size()) this->agregarNaveBeta();
	}

	void agregarNaveBeta() {
		this->betas.push_back(new Beta(this->width));
		if (this->betas.size() / 2 != this->gammas.size()) this->agregarNaveGamma();
	}

	void agregarNaveGamma() {
		this->gammas.push_back(new Gamma(this->width));
	}

	void mostrarAnimacion() {
		for (Alfa* alfa : this->alfas) {
			alfa->borrar();
			alfa->mover(width, height);
			alfa->imprimir();
		}
		for (Beta* beta : this->betas) {
			beta->borrar();
			beta->mover(width, height);
			beta->imprimir();
		}
		for (Gamma* gamma: this->gammas) {
			gamma->borrar();
			gamma->mover(width, height);
			gamma->imprimir();
		}
	}

	bool hemosSidoInvadidos() {
		return (this->gammas.size() + this->alfas.size() + this->betas.size()) >= 20;
	}
};