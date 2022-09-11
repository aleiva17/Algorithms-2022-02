#pragma once
#include <iostream>
#include <string>

class Alas {
private:
	std::string figura;
public:
	Alas() {
		this->figura = "*___oOo___*";
	}

	~Alas() { }

	void imprimir() {
		std::cout << this->figura;
	}

	void borrar() {
		std::string blank = "";
		for (int i = 0; i < this->figura.length(); ++i) {
			blank += ' ';
		}
		std::cout << blank;
	}
};