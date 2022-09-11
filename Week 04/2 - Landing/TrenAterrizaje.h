#pragma once
#include <iostream>
#include <string>

class TrenAterrizaje {
private:
	std::string figura;
public:
	TrenAterrizaje() {
		this->figura = "* *";
	}

	~TrenAterrizaje() { }

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