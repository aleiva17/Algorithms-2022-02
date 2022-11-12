#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Product {
  std::string name;
  float price;
  int stock;
public:
  Product(std::string name, float price, int stock) {
    this->name = name;
    this->price = price;
    this->stock = stock;
  }

  ~Product() { }

  std::string toString() {
    return name + '|' + std::to_string(price) + '|' + std::to_string(stock) + '\n';
  }
};

// Dada la clase Product, registre y lea la informacion de un producto
// segun sea consultada desde un principal.
int main() {
  int option, stock;
  float price;
  std::string name, line;

  std::fstream fileHandler("./products.txt");
  std::vector<Product*> dbInMemory;

  if (fileHandler.fail()) {
    std::cout << "El archivo no existe";
    return 0;
  }

  while (getline(fileHandler, line)) {
    std::stringstream ss(line);
    std::string data;

    getline(ss, data, '|');
    name = data;

    getline(ss, data, '|');
    price = std::stof(data);

    getline(ss, data, '|');
    stock = std::stoi(data);

    dbInMemory.push_back(new Product(name, price, stock));
  }
  fileHandler.close();
  
  while (true) {
    do {
      system("cls");
      std::cout << "\t\tMENU PRINCIPAL\n\n";
      std::cout << "\t1. Registrar producto\n"; 
      std::cout << "\t2. Listar productos\n"; 
      std::cout << "\t3. Salir\n\n";
      std::cout << "\tOpcion: ";
      std::cin >> option; 
    } while (option < 1 || option > 3);

    if (option == 3) break;

    system("cls");

    if (option == 1) {
      std::cout << "\t\tREGISTRAR PRODUCTO\n\n";

      std::cout << "\tNombre del producto: ";
      std::cin >> name;

      std::cout << "\tPrecio: ";
      std::cin >> price;

      std::cout << "\tStock: ";
      std::cin >> stock;

  	  dbInMemory.push_back(new Product(name, price, stock));
    }
    else {
      std::cout << "\t\tLISTA DE PRODUCTOS\n\n";
      for (Product* prod : dbInMemory) {
        std::cout << '\t' << prod->toString();
      }
    }

    system("pause>0");
  }
  
  fileHandler.open("./products.txt", std::ios::out);
  for (Product* prod : dbInMemory) {
    fileHandler << prod->toString();
  }
  fileHandler.close();

  for (Product* prod : dbInMemory) {
    delete prod;
  }
  dbInMemory.clear();
  return 0;
}