#pragma once
#include "Dish.h"
#include <iostream>

class DishList {
private:
	Dish** dishes;
	int quantity;
public:
	DishList() {
		this->dishes = nullptr;
		this->quantity = 0;
	}

	~DishList() {
		for (int i = 0; i < quantity; ++i) {
			delete this->dishes[i];
		}
		delete[] this->dishes;
	}

	void addNewDish(Dish* dish) {
		Dish** temp = new Dish * [this->quantity + 1];

		for (int i = 0; i < this->quantity; ++i) {
			temp[i] = this->dishes[i];
		}

		temp[this->quantity] = dish;

		delete[] this->dishes;
		this->dishes = temp;

		++this->quantity;
	}

	void removeDish(int indexPosition) {
		Dish** temp = new Dish * [this->quantity - 1];

		int curr = 0;
		for (int i = 0; i < this->quantity; ++i) {
			if (i == indexPosition) continue;
			temp[curr] = this->dishes[i];
			++curr;
		}

		delete[] this->dishes;
		this->dishes = temp;

		--this->quantity;
	}

	void listDishes() {
		for (int i = 0; i < this->quantity; ++i) {
			std::cout << "ID: " << i << " -> " << this->dishes[i]->toString() << '\n';
		}
	}

	void listOfSpicyDishes() {
		for (int i = 0; i < this->quantity; ++i) {
			if (!this->dishes[i]->getIsSpicy()) continue;
			std::cout << "ID: " << i << " -> " << this->dishes[i]->toString() << '\n';
		}
	}

	void listOfDishesHigherThan100() {
		for (int i = 0; i < this->quantity; ++i) {
			if (this->dishes[i]->getAvgPrice() <= 100) continue;
			std::cout << "ID: " << i << " -> " << this->dishes[i]->toString() << '\n';
		}
	}

	void listOfTop3MostExpensiveDishes() {
		if (this->quantity == 0) return;

		Dish** sortedByPriceDsc = new Dish * [this->quantity];
		
		for (int i = 0; i < this->quantity; ++i) {
			sortedByPriceDsc[i] = this->dishes[i];
		}

		for (int i = 0; i < this->quantity - 1; ++i) {
			for (int j = i + 1; j < this->quantity; ++j) {
				if (sortedByPriceDsc[i]->getAvgPrice() < sortedByPriceDsc[j]->getAvgPrice()) {
					std::swap(sortedByPriceDsc[i], sortedByPriceDsc[j]);
				}
			}
		}

		std::cout << "Top 1 -> " << sortedByPriceDsc[0]->toString() << '\n';
		if (this->quantity > 1) std::cout << "Top 2 -> " << sortedByPriceDsc[1]->toString() << '\n';
		if (this->quantity > 2) std::cout << "Top 3 -> " << sortedByPriceDsc[2]->toString() << '\n';
	}

	Dish* getDish(int indexPosition) {
		return this->dishes[indexPosition];
	}

	int getQuantity() {
		return this->quantity;
	}
};