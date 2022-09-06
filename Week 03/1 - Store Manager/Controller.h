#pragma once
#include "VectorOfClients.h"
#include "VectorOfProducts.h"
#include "VectorOfSales.h"

class Controller {
private:
	VectorOfClients* clients;
	VectorOfProducts* products;
	VectorOfSales* sales;
public:
	Controller() {
		this->clients = new VectorOfClients();
		this->products = new VectorOfProducts();
		this->sales = new VectorOfSales();
	}

	~Controller() {
		delete this->clients, this->products, this->sales;
	}

	void addClient(std::string id, std::string name) {
		this->clients->addClient(new Client(id, name));
	}

	void addProduct(int id, std::string name, std::string type, std::string brand, int stock, float price) {
		this->products->addProduct(new Product(id, name, type, brand, stock, price));
	}

	void addSale(int id, std::string date, std::string clientId, VectorOfSaleProducts* products) {
		this->sales->addSale(new Sale(id, date, clientId, products));
	}

	void addStockToProduct(int id, int quantity) {
		for (int i = 0; i < this->products->size(); ++i) {
			if (this->products->at(i)->getId() != id) continue;
			this->products->at(i)->addStock(quantity);
			break;
		}
	}

	void removeStockToProduct(int id, int quantity) {
		for (int i = 0; i < this->products->size(); ++i) {
			if (this->products->at(i)->getId() != id) continue;
			this->products->at(i)->removeStock(quantity);
			break;
		}
	}
	
	void printClients() {
		for (int i = 0; i < this->clients->size(); ++i) {
			std::cout << "\tId: "<< this->clients->at(i)->getId() << " - Name: " << this->clients->at(i)->getName() << '\n';
		}
	}

	void printProducts() {
		for (int i = 0; i < this->products->size(); ++i) {
			std::cout << '\t';
			this->products->at(i)->printInfo();
		}
	}

	void printSales() {
		for (int i = 0; i < this->sales->size(); ++i) {
			this->sales->at(i)->printInfo();
		}
	}

	bool existsClient(std::string id) {
		for (int i = 0; i < this->clients->size(); ++i) {
			if (this->clients->at(i)->getId() == id) return true;
		}
		return false;
	}

	bool existsProduct(int id) {
		for (int i = 0; i < this->products->size(); ++i) {
			if (this->products->at(i)->getId() == id) return true;
		}
		return false;
	}

	bool enoughData() {
		return this->clients->size() != 0 && this->products->size() != 0;
	}

	bool enoughStock(int productId, int quantity) {
		for (int i = 0; i < this->products->size(); ++i) {
			if (this->products->at(i)->getId() != productId) continue;
			if (this->products->at(i)->getStock() < quantity) return false;
			return true;
		}
	}
};