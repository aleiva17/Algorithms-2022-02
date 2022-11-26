#pragma once
#include "Entidad.h"

class PacDot : public Entidad {
public:
	PacDot() : Entidad(0, 0, 1, 1) {
		System::Random^ gen = gcnew System::Random();

		x = gen->Next(120, 481);
		y = gen->Next(120, 481);

		delete gen;
	}

	~PacDot() { }
};