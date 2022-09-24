#pragma once
#include "Gato.h"
#include "VectorRatones.h"

class Controller {
private:
	Gato* player;
	VectorRatones* ratones;

	int cantRatones;
	int width, height;
public:
	Controller(int width, int height, int cantRatones) {
		this->width = width;
		this->height = height;
		this->cantRatones = cantRatones;
		
		this->player = new Gato();
		this->player->setX((this->width - this->player->getW()) / 2);
		this->player->setY((this->height - this->player->getH()) / 2);

		this->ratones = new VectorRatones(this->cantRatones, width, height);
	}

	~Controller() {
		delete this->player;
	}

	void gestionTecla(char t) {
		if (t == 32) {
			this->player->cambiarColor();
			return;
		}
		if (t == 'P') {
			this->player->agregarRatonCapturado();
			return;
		}
		this->player->cambiarDireccion(t);
	}

	void gestionHud() {
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		System::Console::SetCursorPosition(0, 0);
		std::cout << "RATONES CAPTURADOS: " << this->player->getCantRatonesAtrapados();
		System::Console::ForegroundColor = System::ConsoleColor::White;
	}

	void gestionGato() {
		this->player->borrar();
		this->player->mover(this->width, this->height);
		this->player->imprimir();
	}
	
	void gestionColisiones() {
		for (Raton* rat : this->ratones->getRatones()) {
			if (rat->getRectangle().IntersectsWith(this->player->getRectangle())) {
				this->player->agregarRatonCapturado();
				rat->setActivo(false);
				break;
			}
		}
	}

	void runGame() {
		this->gestionGato();
		this->ratones->gestionRatones(width, height);
		this->gestionHud();
		this->gestionColisiones();
	}

	bool isGameOver() {
		return this->player->getCantRatonesAtrapados() * 2 == this->cantRatones;
	}
};