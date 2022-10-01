#pragma once
#include "EnemigoA.h"
#include "EnemigoB.h"
#include "Jugador.h"
#include <ctime>

class Controller {
private:
	Jugador* player;
	std::vector<Enemigo*> enemigos;

	int puntajeMaximo;
	time_t tiempoInicio;
	int width, height;
	bool termino, gane;
public:
	Controller(int puntajeMaximo, int width, int height) {
		this->tiempoInicio = time(0);
		this->width = width;
		this->height = height;
		this->termino = false;
		this->gane = false;
		this->puntajeMaximo = puntajeMaximo;
		
		this->player = new Jugador(this->width / 2, this->height - 3);
	}
	
	~Controller() {
		delete this->player;
		for (Enemigo* ene : this->enemigos) {
			delete ene;
		}
		this->enemigos.clear();
	}

	void gestionarTecla(char t) {
		if (t == 32) {
			this->player->dispararBala();
			return;
		}
		
		this->player->cambiarDireccion(t);
	}

	void agregarEnemigos() {
		if (difftime(time(0), this->tiempoInicio) < 7) return;

		this->enemigos.push_back(new EnemigoA(this->width, this->height));
		this->enemigos.push_back(new EnemigoB(this->width, this->height));

		this->tiempoInicio = time(0);
	}
	
	void gestionarJuego() {
		this->gestionEnemigos();
		this->gestionJugador();
		this->gestionColisiones();
		this->verificarEstadoDelJuego();
	}

	void gestionEnemigos() {
		this->agregarEnemigos();
		for (int i = 0; i < this->enemigos.size(); ++i) {
			if (this->enemigos[i]->getEstaActivo()) continue;
			this->enemigos[i]->borrar();
			this->enemigos.erase(this->enemigos.begin() + i);
			break;
		}
		for (Enemigo* ene : this->enemigos) {
			ene->borrar();

			if (ene->getId() == 1) {
				((EnemigoA*)ene)->imprimir();
			}
			else {
				((EnemigoB*)ene)->mover(this->width, this->height);
				((EnemigoB*)ene)->imprimir();
			}
		}
	}

	void gestionJugador() {
		this->player->gestionarBalas(this->width, this->height);

		this->player->borrar();
		this->player->mover(this->width, this->height);
		this->player->imprimir();
	}

	void gestionColisiones() {
		this->colisionBalasEnemigos();
		this->colisionEnemigoJugador();
	}
	
	void colisionEnemigoJugador() {
		for (Enemigo* ene : this->enemigos) {
			if (ene->getRectangle().IntersectsWith(this->player->getRectangle())) {
				this->player->quitarVida();
				this->player->borrar();
				this->player->resetPosition();
				break;
			}
		}
	}

	void colisionBalasEnemigos() {
		for (Bala* bala : this->player->getBalas()) {
			for (Enemigo* ene : this->enemigos) {
				if (bala->getRectangle().IntersectsWith(ene->getRectangle())) {
					bala->setEstaActivo(false);
					ene->setEstaActivo(false);
					bala->borrar();
					ene->borrar();
					--this->puntajeMaximo;
					break;
				}
			}
		}
	}

	void verificarEstadoDelJuego() {
		if (!this->puntajeMaximo) {
			this->termino = true;
			this->gane = true;
			return;
		}

		if (!this->player->getVidas()) {
			this->termino = true;
		}
	}

	bool getTermino() {
		return this->termino;
	}

	bool getGane() {
		return this->gane;
	}
};
