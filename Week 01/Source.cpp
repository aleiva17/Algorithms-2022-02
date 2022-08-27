#include <iostream>
#include "Account.h"

void showMenu(std::string client, float balance) {
	std::cout << "\t\tPONCHI BANK\n\n";
	
	std::cout << "\tWelcome ";
	System::Console::ForegroundColor = System::ConsoleColor::Yellow;
	std::cout << client << '\n';
	System::Console::ForegroundColor = System::ConsoleColor::White;

	std::cout << "\tBalance: ";
	System::Console::ForegroundColor = System::ConsoleColor::Green;
	std::cout << '$' << balance << "\n\n";
	System::Console::ForegroundColor = System::ConsoleColor::White;

	std::cout << "\t1. Deposit\n";
	std::cout << "\t2. Withdraw\n";
	std::cout << "\t3. Exit\n\n";
}

void showTransactionStatus(bool successful) {
	if (successful) {
		System::Console::ForegroundColor = System::ConsoleColor::Green;
		std::cout << "\n\n\tTransaction Successful\n";
		return;
	}
	
	System::Console::ForegroundColor = System::ConsoleColor::Red;
	std::cout << "\n\n\tTransaction Failed\n";
}

int main() {
	Account* account = new Account("Michelle", 100);
	int option;
	float amount;
	
	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;

		do {
			system("cls");
			showMenu(account->getClient(), account->getBalance());
			std::cout << "\tOption: ";
			std::cin >> option;
		} while (option < 1 || option > 3);

		if (option == 3) break;
		system("cls");

		switch (option) {
		case 1:
			std::cout << "\t\tDEPOSIT\n\n";
			std::cout << "\tBalance: $" << account->getBalance() << "\n\n";
			
			std::cout << "\tAmount: ";
			std::cin >> amount;

			showTransactionStatus(account->deposit(amount));
			break;
		case 2:
			std::cout << "\t\tWITHDRAW\n\n";
			std::cout << "\tBalance: $" << account->getBalance() << "\n\n";
			
			std::cout << "\tAmount: ";
			std::cin >> amount;

			showTransactionStatus(account->withdraw(amount));
		}

		system("pause>0");
	}

	delete account;
	return 0;
}