#pragma once
#include <string>
#include <fstream>

class FileManager {
	int lives;
	int qtyGhosts;
	int qtyPacDots;
public:
	FileManager() {
		lives = 3;
		qtyGhosts = 4;
		qtyPacDots = 7;
		loadData();
	}

	~FileManager() { }

	void loadData() {
		std::ifstream reader("INPUT.txt");
		std::string line;

		getline(reader, line);
		lives = std::stoi(line);

		getline(reader, line);
		qtyGhosts = std::stoi(line);
		
		getline(reader, line);
		qtyPacDots = std::stoi(line);

		reader.close();
	}

	void saveScore(int points) {
		std::ofstream writer("OUTPUT.txt");
		writer << points;
		writer.close();
	}

	int getLives() {
		return lives;
	}

	int getQtyGhosts() {
		return qtyGhosts;
	}

	int getPacDots() {
		return qtyPacDots;
	}
};