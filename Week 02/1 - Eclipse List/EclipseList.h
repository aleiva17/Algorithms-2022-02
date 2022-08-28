#pragma once
#include "Eclipse.h"

class EclipseList {
private:
	Eclipse** eclipses;
	int quantity;
public:
	EclipseList() {
		this->eclipses = nullptr;
		this->quantity = 0;
	}

	~EclipseList() {
		for (int i = 0; i < quantity; ++i) {
			delete this->eclipses[i];
		}
		delete[] this->eclipses;
	}

	void addNewEclipse(Eclipse* eclipse) {
		Eclipse** temp = new Eclipse * [this->quantity + 1];

		for (int i = 0; i < this->quantity; ++i) {
			temp[i] = this->eclipses[i];
		}

		temp[this->quantity] = eclipse;

		delete[] this->eclipses;
		this->eclipses = temp;

		++this->quantity;
	}

	void removeDish(int indexPosition) {
		Eclipse** temp = new Eclipse * [this->quantity - 1];

		int curr = 0;
		for (int i = 0; i < this->quantity; ++i) {
			if (i == indexPosition) continue;
			temp[curr] = this->eclipses[i];
			++curr;
		}

		delete[] this->eclipses;
		this->eclipses = temp;

		--this->quantity;
	}

	void listEclipses() {
		for (int i = 0; i < this->quantity; ++i) {
			std::cout << "ID: " << i << " -> ";
			this->eclipses[i]->toString();
		}
	}

	void listOfEclipsesVisibleInEurope() {
		for (int i = 0; i < this->quantity; ++i) {
			std::string continent = this->eclipses[i]->getContHigherVisibility();

			for (char& letter : continent) {
				letter = tolower(letter);
			}

			if (continent != "europe") continue;

			std::cout << "ID: " << i << " -> ";
			this->eclipses[i]->toString();
		}
	}

	void listOfEclipsesThatCausedEarthquakes() {
		for (int i = 0; i < this->quantity; ++i) {
			if (this->eclipses[i]->getEarthquakes()) {
				std::cout << "ID: " << i << " -> ";
				this->eclipses[i]->toString();
			}
		}
	}

	void listOfEclipsesThatHappenedInNight() {
		for (int i = 0; i < this->quantity; ++i) {
			if (this->eclipses[i]->getHour() <= 1800) continue;
			std::cout << "ID: " << i << " -> ";
			this->eclipses[i]->toString();
		}
	}
	
	Eclipse* getEclipse(int indexPosition) {
		return this->eclipses[indexPosition];
	}

	int getQuantity() {
		return this->quantity;
	}
};