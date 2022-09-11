#pragma once
#include <iostream>
#include <string>

class Fuselaje {
private:
	std::string figura;
public:
	Fuselaje() {
		this->figura = "__|__";
	}

	~Fuselaje() { }

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