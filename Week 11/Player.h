#pragma once
#include "Entidad.h"

class Player : public Entidad {
	int points;
public:
	Player() : Entidad(0, 0, 0, 0, 4, 4) {
		this->points = 0;
	}

	~Player() { }

	void addPoint() {
		++this->points;
	}

	int getPoints() {
		return this->points;
	}
};