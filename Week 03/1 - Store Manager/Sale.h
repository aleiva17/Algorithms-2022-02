#pragma once
#include <iostream>
#include <string>
#include "VectorOfSaleProducts.h"

class Sale {
private:
	int saleId;
	std::string date;
	std::string clientId;
	VectorOfSaleProducts* products;
public:
	Sale(int saleId, std::string date, std::string clientId, VectorOfSaleProducts* products) {
		this->saleId = saleId;
		this->date = date;
		this->clientId = clientId;
		this->products = products;
	}

	~Sale() {
		delete products;
	}

	void printInfo() {
		std::cout << "\tSale Id: " << this->saleId << '\n';
		std::cout << "\tDate: " << this->date << '\n';
		std::cout << "\tClient Id: " << this->clientId << '\n';
		std::cout << "\tProducts:\n";
		for (int i = 0; i < products->size(); ++i) {
			std::cout << "\t\tID: " << products->at(i)->getProductId() << " - QUANTITY: " << products->at(i)->getQuantity() << '\n';
		}
		std::cout << '\n';
	}
};