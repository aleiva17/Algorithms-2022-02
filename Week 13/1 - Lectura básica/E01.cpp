#include <iostream>
#include <fstream>

// Abrir el archivo de texto: "e01.txt"
// Este archivo está compuesto de una cadena de texto, un entero y un flotante
// separados en cada línea. 
// Debe de imprimir en consola la cadena de texto concatenada con el resultado
// de aplicar la multiplicación entre el número entero y el flotante

int main() {
  int num;
  float dec;
  std::string texto, line;
  std::ifstream reader("./e01.txt");

  if (reader.fail()) {
    std::cout << "El archivo no existe.";
    return 0;
  }

  getline(reader, texto);

  getline(reader, line);
  num = std::stoi(line);

  getline(reader, line);
  dec = std::stof(line);

  std::cout << texto << ": " << num * dec;

  reader.close();
  return 0;
}