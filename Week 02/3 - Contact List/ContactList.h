#pragma once
#include "Contact.h"

class ContactList {
private:
	Contact** contacts;
	int quantity;
public:
	ContactList() {
		this->contacts = nullptr;
		this->quantity = 0;
	}

	~ContactList() {
		for (int i = 0; i < quantity; ++i) {
			delete this->contacts[i];
		}
		delete[] this->contacts;
	}

	void addNewContact(Contact* contact) {
		Contact** temp = new Contact * [this->quantity + 1];

		for (int i = 0; i < this->quantity; ++i) {
			temp[i] = this->contacts[i];
		}

		temp[this->quantity] = contact;

		delete[] this->contacts;
		this->contacts = temp;

		++this->quantity;
	}

	void removeContact(int indexPosition) {
		Contact** temp = new Contact * [this->quantity - 1];

		int curr = 0;
		for (int i = 0; i < this->quantity; ++i) {
			if (i == indexPosition) continue;
			temp[curr] = this->contacts[i];
			++curr;
		}

		delete[] this->contacts;
		this->contacts = temp;

		--this->quantity;
	}

	void listContacts() {
		for (int i = 0; i < this->quantity; ++i) {
			std::cout << "ID: " << i << " -> ";
			this->contacts[i]->toString();
		}
	}

	void listOfContactsBornInMay() {
		for (int i = 0; i < this->quantity; ++i) {
			std::string birthdate = this->contacts[i]->getBirthdate();

			for (char& letter : birthdate) {
				letter = tolower(letter);
			}

			if (birthdate == "may" || birthdate == "mayo") {
				std::cout << "ID: " << i << " -> ";
				this->contacts[i]->toString();
			}
		}
	}

	void listOfMaleContacts() {
		for (int i = 0; i < this->quantity; ++i) {
			if (toupper(this->contacts[i]->getGenre()) == 'M') {
				std::cout << "ID: " << i << " -> ";
				this->contacts[i]->toString();
			}
		}
	}

	void listOfContactsOnFacebookAndWhatsApp() {
		for (int i = 0; i < this->quantity; ++i) {
			std::string socialNetwork = this->contacts[i]->getSocialNetwork();

			for (char& letter : socialNetwork) {
				letter = tolower(letter);
			}

			if (socialNetwork == "whatsapp" || socialNetwork == "facebook") {
				std::cout << "ID: " << i << " -> ";
				this->contacts[i]->toString();
			}
		}
	}

	Contact* getContact(int indexPosition) {
		return this->contacts[indexPosition];
	}

	int getQuantity() {
		return this->quantity;
	}
};