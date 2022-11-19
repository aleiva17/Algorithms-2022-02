#pragma once
#include "Entidad.h"

class PacDot : public Entidad {
public:
	PacDot(int x, int y) : Entidad(x, y, 0, 0, 1, 1) { }
	~PacDot() { }
};