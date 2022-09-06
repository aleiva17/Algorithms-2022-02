#pragma once
#include "Client.h"

class VectorOfClients {
private:
	Client** array;
	int sz;
public:
	VectorOfClients() {
		this->array = nullptr;
		this->sz = 0;
	}

	~VectorOfClients() {
		for (int i = 0; i < this->sz; ++i) {
			delete this->array[i];
		}
		delete[] array;
	}

	void addClient(Client* cli) {
		Client** temp = new Client * [this->sz + 1];

		for (int i = 0; i < this->sz; ++i) {
			temp[i] = array[i];
		}

		temp[this->sz] = cli;

		delete[] this->array;
		this->array = temp;

		++this->sz;
	}

	int size() {
		return this->sz;
	}

	Client* at(int index) {
		if (index < 0 || index >= this->sz) throw "Error: Index out of range";
		return this->array[index];
	}
};