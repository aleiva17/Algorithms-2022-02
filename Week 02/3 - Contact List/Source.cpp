#include <iostream>
#include "ContactList.h"

void showMenu() {
	std::cout << "\t\tMY CONTACT LIST\n\n";
	std::cout << "\t1. Add a new contact\n";
	std::cout << "\t2. Remove a contact\n";
	std::cout << "\t3. Modify a contact\n";
	std::cout << "\t4. List my contacts\n";
	std::cout << "\t5. Exit\n\n";
}

void showListOptionsMenu() {
	std::cout << "\t1. All contacts\n";
	std::cout << "\t2. Only Male\n";
	std::cout << "\t3. Born in May\n";
	std::cout << "\t4. From Facebook and WhatsApp\n\n";
}

int main() {
	System::Console::ForegroundColor = System::ConsoleColor::White;
	int option, indexPosition; 
	
	Contact* toModify = nullptr;
	int phoneNumber;
	char genre;
	std::string name;
	std::string career;
	std::string birthdate;
	std::string email;
	std::string socialNetwork;

	ContactList* agenda = new ContactList();

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
			std::cout << "\t\tADD A NEW CONTACT\n\n";

			std::cout << "\tName: ";
			std::cin >> name;

			std::cout << "\tPhone: ";
			std::cin >> phoneNumber;

			do {
				std::cout << "\tGenre (F, M, O): ";
				std::cin >> genre;
				genre = toupper(genre);
			} while (genre != 'F' && genre != 'M' && genre != 'O');

			std::cout << "\tCareer: ";
			std::cin >> career;

			std::cout << "\tBirthdate month: ";
			std::cin >> birthdate;

			std::cout << "\tEmail: ";
			std::cin >> email;

			std::cout << "\tSocial Network: ";
			std::cin >> socialNetwork;

			agenda->addNewContact(new Contact(name, phoneNumber, genre, career, birthdate, email, socialNetwork));

			std::cout << "\n\tSuccessful registration.";
			break;
		case 2:
			if (agenda->getQuantity() == 0) break;
			std::cout << "\t\tREMOVE A CONTACT\n\n";

			do {
				std::cout << "\tID: ";
				std::cin >> indexPosition;
			} while (indexPosition < 0 || indexPosition >= agenda->getQuantity());

			agenda->removeContact(indexPosition);

			std::cout << "\n\tSuccessful removal.";
			break;
		case 3:
			if (agenda->getQuantity() == 0) break;
			std::cout << "\t\tMODIFY A CONTACT\n\n";

			do {
				std::cout << "\tID: ";
				std::cin >> indexPosition;
			} while (indexPosition < 0 || indexPosition >= agenda->getQuantity());

			toModify = agenda->getContact(indexPosition);

			std::cout << "\tNew Name: ";
			std::cin >> name;

			std::cout << "\tNew Phone: ";
			std::cin >> phoneNumber;

			do {
				std::cout << "\tNew Genre (F, M, O): ";
				std::cin >> genre;
				genre = toupper(genre);
			} while (genre != 'F' && genre != 'M' && genre != 'O');

			std::cout << "\tNew Career: ";
			std::cin >> career;

			std::cout << "\tNew Birthdate month: ";
			std::cin >> birthdate;

			std::cout << "\tNew Email: ";
			std::cin >> email;

			std::cout << "\tNew Social Network: ";
			std::cin >> socialNetwork;

			toModify->setName(name);
			toModify->setPhoneNumber(phoneNumber);
			toModify->setGenre(genre);
			toModify->setCareer(career);
			toModify->setBirthdate(birthdate);
			toModify->setEmail(email);
			toModify->setSocialNetwork(socialNetwork);
			toModify = nullptr;

			std::cout << "\n\tSuccessful edition.";
			break;
		case 4:
			std::cout << "\t\tLIST MY CONTACTS\n\n";
			showListOptionsMenu();

			do {
				std::cout << "\tOption: ";
				std::cin >> option;
			} while (option < 1 || option > 4);

			switch (option) {
				case 1: agenda->listContacts(); break;
				case 2: agenda->listOfMaleContacts(); break;
				case 3: agenda->listOfContactsBornInMay(); break;
				case 4: agenda->listOfContactsOnFacebookAndWhatsApp();
			}

			break;
		}

		system("pause>0");
	}

	delete agenda;
	system("pause>0");
	return 0;
}