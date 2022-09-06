#include <iostream>
#include "DriverList.h"

void showMenu() {
	std::cout << "\t\tDELIVERY MAN MANAGER\n\n";
	std::cout << "\t1. Add a driver\n";
	std::cout << "\t2. Remove a driver\n";
	std::cout << "\t3. Show all drivers\n";
	std::cout << "\t4. Show drivers from Mapi\n";
	std::cout << "\t5. Show drivers from Glopo\n";
	std::cout << "\t6. Exit\n\n";
}

int main() {
	DriverList* drivers = new DriverList();

	int option, pos;

	std::string name, lastName, plate;
	float mileage;
	int enterprise;

	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		
		do {
			system("cls");
			showMenu();
			std::cout << "\tOption: ";
			std::cin >> option;
		} while (option < 1 || option > 6);

		if (option == 6) break;

		system("cls");

		switch (option) {
		case 1:
			std::cout << "\t\tADD A DRIVER\n\n";

			std::cout << "\tName and lastname: ";
			std::cin >> name >> lastName;

			std::cout << "\tPlate: ";
			std::cin >> plate;
			
			do {
				std::cout << "\tMileage: ";
				std::cin >> mileage;
			} while (mileage < 0);

			do {
				std::cout << "\tSelect an enterprise (1: Mapi, 2: Glopo): ";
				std::cin >> enterprise;
			} while (enterprise < 1 || enterprise > 2);

			drivers->addDriver(new Driver(name, lastName, plate, mileage, (enterprise == 1 ? "Mapi" : "Glopo")));

			System::Console::ForegroundColor = System::ConsoleColor::Green;
			std::cout << "\n\tSuccessful registration.";
			break;
		case 2:
			if (drivers->getSize() == 0) break;
			std::cout << "\t\tREMOVE A DRIVER\n\n";

			do {
				std::cout << "\tEnter the driver position: ";
				std::cin >> pos;
			} while (pos < 0 || pos >= drivers->getSize());

			drivers->removeDriver(pos);
			System::Console::ForegroundColor = System::ConsoleColor::Green;
			std::cout << "\n\tSuccessful operation.";
			break;
		case 3:
			std::cout << "\t\tSHOW ALL DRIVERS\n\n";
			drivers->showAllDrivers();
			break;
		case 4:
			std::cout << "\t\tSHOW DRIVERS FROM MAPI\n\n";
			drivers->showDriversFromMapi();
			break;
		case 5:
			std::cout << "\t\tSHOW DRIVERS FROM GLOPO\n\n";
			drivers->showDriversFromGlopo();
		}

		system("pause>0");
	}

	delete drivers;
	return 0;
}