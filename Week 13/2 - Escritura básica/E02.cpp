#include <iostream>
#include <string>
#include <fstream>

class Player {
  std::string name;
  int score;
public:
  Player(std::string name, int score) {
    this->name = name;
    this->score = score;
  }

  ~Player() { }

  std::string getInfo() {
    return this->name + ' ' + std::to_string(this->score);
  }
};

// Dado dos objetos de la clase Player, almacene la informacion
// (metodo getInfo()) en un archivo de texto.
int main() {
  Player* p1 = new Player("Alex", 3600);
  Player* p2 = new Player("Michelle", 4200);
  	
  std::ofstream writer("./e02.txt");

  writer << p1->getInfo();
  writer << '\n';
  writer << p2->getInfo();
  writer.close();

  delete p1, p2;
  return 0;
}