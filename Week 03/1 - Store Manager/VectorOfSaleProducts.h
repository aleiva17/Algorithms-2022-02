#pragma once
#include "SaleProduct.h"

class VectorOfSaleProducts {
private:
	SaleProduct** array;
	int sz;
public:
	VectorOfSaleProducts() {
		this->array = nullptr;
		this->sz = 0;
	}

	~VectorOfSaleProducts() {
		for (int i = 0; i < this->sz; ++i) {
			delete this->array[i];
		}
		delete[] array;
	}

	void addProduct(SaleProduct* prod) {
		SaleProduct** temp = new SaleProduct * [this->sz + 1];

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

	SaleProduct* at(int index) {
		if (index < 0 || index >= this->sz) throw "Error: Index out of range";
		return this->array[index];
	}
};