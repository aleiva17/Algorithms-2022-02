#pragma once
#include "Entidad.h"

class Coin : public Entidad {
public:
	Coin(int x, int y) : Entidad(x, y, 0, 0, 1, 1) { }
	~Coin() { }
};