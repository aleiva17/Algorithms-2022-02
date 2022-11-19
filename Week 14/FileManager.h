#pragma once
#include <fstream>
#include <string>

class FileManager {
	int lives;
	int ghostQty;
	int pacDotsQty;
public:
	FileManager() {
		loadData();
	}

	~FileManager() { }

	void loadData() {
		std::ifstream reader("INPUT.TXT");
		std::string line;

		if (reader.fail()) {
			return;
		}

		getline(reader, line);
		lives = std::stoi(line);

		getline(reader, line);
		ghostQty = std::stoi(line);

		getline(reader, line);
		pacDotsQty = std::stoi(line);

		reader.close();
	}

	void saveScore(int score) {
		std::ofstream writer("OUTPUT.TXT");
		writer << score;
		writer.close();
	}

	int getGhostQty() {
		return ghostQty;
	}

	int getLives() {
		return lives;
	}

	int getPacDotsQty() {
		return pacDotsQty;
	}
};
