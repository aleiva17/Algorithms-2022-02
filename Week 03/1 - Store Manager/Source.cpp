#include <iostream>
#include "Controller.h"

void showMenu() {
	std::cout << "\t\tMY STORE MANAGER\n\n";
	std::cout << "\t1. Register new client\n";
	std::cout << "\t2. Register new product\n";
	std::cout << "\t3. Register new sale\n";
	std::cout << "\t4. Add stock to product\n";
	std::cout << "\t5. Show clients\n";
	std::cout << "\t6. Show products\n";
	std::cout << "\t7. Show sales\n";
	std::cout << "\t8. Exit\n\n";
}

void registerClientView(Controller* app) {
	std::string id, name;
	std::cout << "\t\tREGISTER NEW CLIENT\n\n";

	std::cout << "\tId: ";
	std::cin >> id;

	std::cout << "\tName: ";
	std::cin >> name;

	if (app->existsClient(id)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "\n\tError: Client already exists.";
		return;
	}

	app->addClient(id, name);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	std::cout << "\n\tSuccessful registration.";
}

void registerProductView(Controller* app) {
	int id, stock;
	std::string name, type, brand;
	float price;

	std::cout << "\t\tREGISTER NEW PRODUCT\n\n";

	std::cout << "\tId: ";
	std::cin >> id;

	if (app->existsProduct(id)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "\n\tError: Product already exists. Try to add stock.";
		return;
	}

	std::cout << "\tName: ";
	std::cin >> name;

	std::cout << "\tType: ";
	std::cin >> type;

	std::cout << "\tBrand: ";
	std::cin >> brand;

	do {
		std::cout << "\tStock: ";
		std::cin >> stock;
	} while (stock <= 0);

	std::cout << "\tPrice: ";
	std::cin >> price;

	app->addProduct(id, name, type, brand, stock, price);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	std::cout << "\n\tSuccessful registration.";
}

void registerSaleView(Controller* app) {
	int saleId, productId, quantity;
	std::string date, clientId;
	VectorOfSaleProducts* products = new VectorOfSaleProducts();

	std::cout << "\t\tREGISTER NEW SALE	\n\n";

	if (!app->enoughData()) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "\n\tError: Not enough data.";
		return;
	}

	std::cout << "\tSale Id: ";
	std::cin >> saleId;

	std::cout << "\tDate: ";
	std::cin >> date;

	std::cout << "\tClient Id: ";
	std::cin >> clientId;

	if (!app->existsClient(clientId)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "\n\tError: Client doesn't exists.";
		return;
	}

	std::cout << "\n\tType 0 0 to exit\n";

	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		std::cout << "\tProduct Id and Quantity: ";
		std::cin >> productId >> quantity;
		
		if (!productId && !quantity) break;

		if (!app->existsProduct(productId)) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			std::cout << "\n\tError: Product doesn't exists.\n";
			continue;
		}

		if (quantity <= 0) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			std::cout << "\n\tError: Invalid quantity.\n";
			continue;
		}

		if (!app->enoughStock(productId, quantity)) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			std::cout << "\n\tError: Not enough stock.\n";
			continue;
		}

		app->removeStockToProduct(productId, quantity);
		products->addProduct(new SaleProduct(productId, quantity));
	}

	app->addSale(saleId, date, clientId, products);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	std::cout << "\n\tSuccessful registration.";
}

void addStockProductView(Controller* app) {
	int id, quantity;
	std::cout << "\t\tADD STOCK TO PRODUCT\n\n";
	
	std::cout << "\tProduct Id: ";
	std::cin >> id;

	do {
		std::cout << "\tQuantity to add: ";
		std::cin >> quantity;
	} while (quantity <= 0);

	if (!app->existsProduct(id)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "\n\tError: Product doesn't exists.";
		return;
	}

	app->addStockToProduct(id, quantity);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	std::cout << "\n\tSuccessful operation.";
}

void showClientsView(Controller* app) {
	std::cout << "\t\tMY CLIENTS\n\n";
	app->printClients();
}

void showProductsView(Controller* app) {
	std::cout << "\t\tMY PRODUCTS\n\n";
	app->printProducts();
}

void showSalesView(Controller* app) {
	std::cout << "\t\tMY SALES\n\n";
	app->printSales();
}

int main() {
	Controller* app = new Controller();
	int option;

	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		do {
			system("cls");
			showMenu();
			std::cout << "\tOption: ";
			std::cin >> option;
		} while (option < 1 || option > 8);

		if (option == 8) break;
		system("cls");

		switch (option) {
			case 1: registerClientView(app); break;
			case 2: registerProductView(app); break;
			case 3: registerSaleView(app); break;
			case 4: addStockProductView(app); break;
			case 5: showClientsView(app); break;
			case 6: showProductsView(app); break;
			case 7: showSalesView(app); break;
		}

		system("pause>0");
	}

	delete app;
	return 0;
}