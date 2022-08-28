#include <iostream>
#include "EclipseList.h"

void showMenu() {
	std::cout << "\t\tMY ECLIPSE LIST\n\n";
	std::cout << "\t1. Add a new eclipse\n";
	std::cout << "\t2. Remove an eclipse\n";
	std::cout << "\t3. Modify an eclipse\n";
	std::cout << "\t4. List my eclipses\n";
	std::cout << "\t5. Exit\n\n";
}

void showListOptionsMenu() {
	std::cout << "\t1. All eclipses\n";
	std::cout << "\t2. Visible in Europe\n";
	std::cout << "\t3. Caused earthquakes\n";
	std::cout << "\t4. During the night\n\n";
}

int main() {
	System::Console::ForegroundColor = System::ConsoleColor::White;
	int option, indexPosition; 
	
	Eclipse* toModify = nullptr;
	std::string eclipseType;
	std::string date;
	int hour;
	bool earthquakes;
	bool rains;
	std::string contHigherVisibility;

	EclipseList* eclipses = new EclipseList();

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
			std::cout << "\t\tADD A NEW ECLIPSE\n\n";

			std::cout << "\tEclipse type: ";
			std::cin >> eclipseType;

			std::cout << "\tDate: ";
			std::cin >> date;

			do {
				std::cout << "\tHour (0 - 2359): ";
				std::cin >> hour;
			} while (hour < 0 || hour > 2359);

			std::cout << "\tEarthquakes (0: No, 1: Yes): ";
			std::cin >> earthquakes;

			std::cout << "\tRains (0: No, 1: Yes): ";
			std::cin >> rains;

			std::cout << "\tContinent with higher visibility: ";
			std::cin >> contHigherVisibility;
			
			eclipses->addNewEclipse(new Eclipse(eclipseType, date, hour, earthquakes, rains, contHigherVisibility));

			std::cout << "\n\tSuccessful registration.";
			break;
		case 2:
			if (eclipses->getQuantity() == 0) break;
			std::cout << "\t\tREMOVE AN ECLIPSE\n\n";

			do {
				std::cout << "\tID: ";
				std::cin >> indexPosition;
			} while (indexPosition < 0 || indexPosition >= eclipses->getQuantity());

			eclipses->removeDish(indexPosition);

			std::cout << "\n\tSuccessful removal.";
			break;
		case 3:
			if (eclipses->getQuantity() == 0) break;
			std::cout << "\t\tMODIFY AN ECLIPSE\n\n";

			do {
				std::cout << "\tID: ";
				std::cin >> indexPosition;
			} while (indexPosition < 0 || indexPosition >= eclipses->getQuantity());

			toModify = eclipses->getEclipse(indexPosition);

			std::cout << "\tNew eclipse type: ";
			std::cin >> eclipseType;

			std::cout << "\tNew date: ";
			std::cin >> date;

			do {
				std::cout << "\tNew hour (0 - 2359): ";
				std::cin >> hour;
			} while (hour < 0 || hour > 2359);

			std::cout << "\tNew earthquakes (0: No, 1: Yes): ";
			std::cin >> earthquakes;

			std::cout << "\tNew rains (0: No, 1: Yes): ";
			std::cin >> rains;

			std::cout << "\tNew continent with higher visibility: ";
			std::cin >> contHigherVisibility;

			toModify->setEclipseType(eclipseType);
			toModify->setDate(date);
			toModify->setHour(hour);
			toModify->setEarthquakes(earthquakes);
			toModify->setRains(rains);
			toModify->setContHigherVisibility(contHigherVisibility);
			toModify = nullptr;

			std::cout << "\n\tSuccessful edition.";
			break;
		case 4:
			std::cout << "\t\tLIST MY ECLIPSES\n\n";
			showListOptionsMenu();

			do {
				std::cout << "\tOption: ";
				std::cin >> option;
			} while (option < 1 || option > 4);

			switch (option) {
				case 1: eclipses->listEclipses(); break;
				case 2: eclipses->listOfEclipsesVisibleInEurope(); break;
				case 3: eclipses->listOfEclipsesThatCausedEarthquakes(); break;
				case 4: eclipses->listOfEclipsesThatHappenedInNight();
			}
		}

		system("pause>0");
	}

	delete eclipses;
	return 0;
}