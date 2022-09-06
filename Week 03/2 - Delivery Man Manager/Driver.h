#pragma once
#include <iostream>
#include <string>

class Driver {
private:
	std::string name;
	std::string lastName;
	std::string plate;
	float mileage;
	float price;
	std::string enterprise;
public:
	Driver(std::string name, std::string lastName, std::string plate, float mileage, std::string enterprise) {
		this->name = name;
		this->lastName = lastName;
		this->plate = plate;
		this->mileage = mileage;
		this->enterprise = enterprise;
		this->price = 1.5 * this->mileage;
	}

	~Driver() { }

	void showInfo() {
		std::cout << "{ Name: " << this->name << ' ' << this->lastName << " - Plate: " << this->plate << " - " << this->mileage << " KM - Enterprise: " << this->enterprise << " - Price: $" << this->price << " }\n";
	}

	std::string getEnterprise() {
		return this->enterprise;
	}
};