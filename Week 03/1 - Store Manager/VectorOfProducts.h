#pragma once
#include "Product.h"

class VectorOfProducts {
private:
	Product** array;
	int sz;
public:
	VectorOfProducts() {
		this->array = nullptr;
		this->sz = 0;
	}

	~VectorOfProducts() {
		for (int i = 0; i < this->sz; ++i) {
			delete this->array[i];
		}
		delete[] array;
	}

	void addProduct(Product* prod) {
		Product** temp = new Product * [this->sz + 1];

		for (int i = 0; i < this->sz; ++i) {
			temp[i] = array[i];
		}

		temp[this->sz] = prod;

		delete[] this->array;
		this->array = temp;

		++this->sz;
	}

	int size() {
		return this->sz;
	}

	Product* at(int index) {
		if (index < 0 || index >= this->sz) throw "Error: Index out of range";
		return this->array[index];
	}
};