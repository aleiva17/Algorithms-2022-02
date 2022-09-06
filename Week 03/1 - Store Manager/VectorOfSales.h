#pragma once
#include "Sale.h"

class VectorOfSales {
private:
	Sale** array;
	int sz;
public:
	VectorOfSales() {
		this->array = nullptr;
		this->sz = 0;
	}

	~VectorOfSales() {
		for (int i = 0; i < this->sz; ++i) {
			delete this->array[i];
		}
		delete[] array;
	}

	void addSale(Sale* sale) {
		Sale** temp = new Sale * [this->sz + 1];

		for (int i = 0; i < this->sz; ++i) {
			temp[i] = array[i];
		}

		temp[this->sz] = sale;

		delete[] this->array;
		this->array = temp;

		++this->sz;
	}

	int size() {
		return this->sz;
	}

	Sale* at(int index) {
		if (index < 0 || index >= this->sz) throw "Error: Index out of range";
		return this->array[index];
	}
};