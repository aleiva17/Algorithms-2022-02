#include <iostream>
#include "DishList.h"

void showMenu() {
	std::cout << "\t\tMY DISH LIST\n\n";
	std::cout << "\t1. Add a new dish\n";
	std::cout << "\t2. Remove a dish\n";
	std::cout << "\t3. Modify a dish\n";
	std::cout << "\t4. List my dishes\n";
	std::cout << "\t5. Exit\n\n";
}

void showListOptionsMenu() {
	std::cout << "\t1. All dishes\n";
	std::cout << "\t2. Only spicy\n";
	std::cout << "\t3. Top 3 most expensive\n";
	std::cout << "\t4. With price higher than 100\n\n";
}

int main() {
	System::Console::ForegroundColor = System::ConsoleColor::White;
	int option, indexPosition; 
	
	Dish* toModify = nullptr;
	std::string dishName;
	std::string dishType;
	bool isSpicy;
	int kcal;
	float avgPrice;

	DishList* dishList = new DishList();

	while (true) {
		do {
			system("cls");
			showMenu();
			std::cout << "\tOption: ";
			std::cin >> option;
		} while (option < 1 || option > 5);

		if (option == 5) break;
		system("cls");

		switch (option) {
		case 1:
			std::cout << "\t\tADD A NEW DISH\n\n";

			std::cout << "\tDish name: ";
			std::cin >> dishName;

			std::cout << "\tDish Type: ";
			std::cin >> dishType;

			std::cout << "\tIs it spicy? (0: No, 1: Yes): ";
			std::cin >> isSpicy;

			std::cout << "\tKcal: ";
			std::cin >> kcal;

			std::cout << "\tAvg price: ";
			std::cin >> avgPrice;
			
			dishList->addNewDish(new Dish(dishName, dishType, isSpicy, kcal, avgPrice));

			std::cout << "\n\tSuccessful registration.";
			break;
		case 2:
			if (dishList->getQuantity() == 0) break;
			std::cout << "\t\tREMOVE A DISH\n\n";

			do {
				std::cout << "\tID: ";
				std::cin >> indexPosition;
			} while (indexPosition < 0 || indexPosition >= dishList->getQuantity());

			dishList->removeDish(indexPosition);

			std::cout << "\n\tSuccessful removal.";
			break;
		case 3:
			if (dishList->getQuantity() == 0) break;
			std::cout << "\t\tMODIFY A DISH\n\n";

			do {
				std::cout << "\tID: ";
				std::cin >> indexPosition;
			} while (indexPosition < 0 || indexPosition >= dishList->getQuantity());

			toModify = dishList->getDish(indexPosition);

			std::cout << "\tNew Name: ";
			std::cin >> dishName;

			std::cout << "\tNew Type: ";
			std::cin >> dishType;

			std::cout << "\tIs it spicy? (0: No, 1: Yes): ";
			std::cin >> isSpicy;

			std::cout << "\tNew Kcal: ";
			std::cin >> kcal;

			std::cout << "\tNew avg price: ";
			std::cin >> avgPrice;

			toModify->setDishName(dishName);
			toModify->setDishType(dishType);
			toModify->setIsSpicy(isSpicy);
			toModify->setKcal(kcal);
			toModify->setAvgPrice(avgPrice);
			toModify = nullptr;

			std::cout << "\n\tSuccessful edition.";
			break;
		case 4:
			std::cout << "\t\tLIST MY DISHES\n\n";
			showListOptionsMenu();

			do {
				std::cout << "\tOption: ";
				std::cin >> option;
			} while (option < 1 || option > 4);

			switch (option) {
				case 1: dishList->listDishes(); break;
				case 2: dishList->listOfSpicyDishes(); break;
				case 3: dishList->listOfTop3MostExpensiveDishes(); break;
				case 4: dishList->listOfDishesHigherThan100();
			}
		}

		system("pause>0");
	}

	delete dishList;
	return 0;
}