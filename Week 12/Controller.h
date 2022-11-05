#pragma once
#include "Caballo.h"
#include <vector>

class Controller {
private:
	Caballo* horse;
	std::vector<Caballo*> caballos;
public:
	Controller() {
		this->horse = new Caballo();
	}

	~Controller() {
		for (Caballo* caballo : caballos) {
			delete caballo;
		}
		this->caballos.clear();
		delete this->horse;
	}

	void moveHorse(direccion dir) {
		this->horse->desplazamiento(dir);
	}

	void changeMainHorseColor(color colorType) {
		this->horse->changeColor(colorType);
	}

	void addHorse() {
		Random^ gen = gcnew Random();
		color colores[4] = { color::white, color::blue, color::green, color::yellow };
		this->caballos.push_back(new Caballo(gen->Next(0, 500), gen->Next(0, 500), colores[gen->Next(0, 4)]));
		delete gen;
	}

	void gameManagement(Graphics^ g, Bitmap^ bmpCaballo) {
		mainHorseManagement(g, bmpCaballo);
		otherHorsesManagement(g, bmpCaballo);
	}

	void mainHorseManagement(Graphics^ g, Bitmap^ bmp) {
		this->horse->mostrar(g, bmp);
		this->horse->mover(g);
	}

	void otherHorsesManagement(Graphics^ g, Bitmap^ bmp) {
		for (Caballo* caballo : this->caballos) {
			caballo->mostrar(g, bmp);
			caballo->moverRebote(g);
		}
	}
};