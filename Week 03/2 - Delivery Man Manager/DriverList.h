#pragma once
#include "Driver.h"

class DriverList {
private:
	Driver** drivers;
	int size;
public:
	DriverList() {
		this->drivers = nullptr;
		this->size = 0;
	}

	~DriverList() {
		for (int i = 0; i < this->size; ++i) {
			delete this->drivers[i];
		}
		delete[] this->drivers;
	}

	void addDriver(Driver* newDriver) {
		Driver** temp = new Driver * [this->size + 1];

		for (int i = 0; i < this->size; ++i) {
			temp[i] = this->drivers[i];
		}

		temp[this->size] = newDriver;

		delete[] this->drivers;
		this->drivers = temp;

		++this->size;
	}

	void removeDriver(int pos) {
		if (pos < 0 || pos >= this->size || this->size == 0) return;

		Driver** temp = new Driver * [this->size - 1];

		int j = 0;
		for (int i = 0; i < this->size; ++i) {
			if (i == pos) continue;
			temp[j++] = this->drivers[i];
		}

		delete[] this->drivers;
		this->drivers = temp;

		--this->size;
	}

	void showAllDrivers() {
		for (int i = 0; i < this->size; ++i) {
			this->drivers[i]->showInfo();
		}
	}

	void showDriversFromMapi() {
		for (int i = 0; i < this->size; ++i) {
			if (this->drivers[i]->getEnterprise() == "Mapi") {
				this->drivers[i]->showInfo();
			}
		}
	}

	void showDriversFromGlopo() {
		for (int i = 0; i < this->size; ++i) {
			if (this->drivers[i]->getEnterprise() == "Glopo") {
				this->drivers[i]->showInfo();
			}
		}
	}

	int getSize() {
		return this->size;
	}
};