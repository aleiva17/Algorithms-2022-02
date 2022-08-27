#pragma once
#include <string>

class Dish {
private:
	std::string dishName;
	std::string dishType;
	bool isSpicy;
	int kcal;
	float avgPrice;
public:
	Dish(std::string dishName, std::string dishType, bool isSpicy, int kcal, float avgPrice) {
		this->dishName = dishName;
		this->dishType = dishType;
		this->isSpicy = isSpicy;
		this->kcal = kcal;
		this->avgPrice = avgPrice;
	}

	~Dish() { }

	std::string toString() {
		return "Name: " + this->dishName + " | Type: " + this->dishType + " | Is it spicy? " + (this->isSpicy ? "Yes" : "No") + " | Kcal: " + std::to_string(this->kcal) + " | AVG. Price: " + std::to_string(this->avgPrice);
	}
	
	void setDishName(std::string dishName) {
		this->dishName = dishName;
	}

	void setDishType(std::string dishType) {
		this->dishType = dishType;
	}

	void setIsSpicy(bool isSpicy) {
		this->isSpicy = isSpicy;
	}
	
	void setKcal(int kcal) {
		this->kcal = kcal;
	}
	
	void setAvgPrice(float avgPrice) {
		this->avgPrice = avgPrice;
	}
	
	bool getIsSpicy() {
		return this->isSpicy;
	}

	float getAvgPrice() {
		return this->avgPrice;
	}
};