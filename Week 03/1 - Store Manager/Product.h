#pragma once
#include <iostream>
#include <string>

class Product {
private:
	int id;
	std::string name;
	std::string type;
	std::string brand;
	int stock;
	float price;
public:
	Product(int id, std::string name, std::string type, std::string brand, int stock, float price) {
		this->id = id;
		this->name = name;
		this->type = type;
		this->brand = brand;
		this->stock = stock;
		this->price = price;
	}

	~Product() { }

	void printInfo() {
		std::cout << "Id: " << this->id << " | " << this->name << " | Type: " << this->type << " | Brand: " << this->brand << " | Stock: " << this->stock << " | Price: " << this->price << '\n';
	}

	void addStock(int quantity) {
		this->stock += quantity;
	}

	void removeStock(int quantity) {
		this->stock -= quantity;
	}

	int getId() {
		return this->id;
	}

	int getStock() {
		return this->stock;
	}
};