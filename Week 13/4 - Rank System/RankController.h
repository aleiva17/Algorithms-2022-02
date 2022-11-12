#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class RankController {
	vector<pair<string, int>> ranks;
public:
	RankController() {
		ifstream reader("Ranks.txt");
		if (reader.is_open()) {
			loadRanks();
			sortRanks();
		}
		else {
			ofstream writer("Ranks.txt");
			writer.close();
		}
		reader.close();
	}

	~RankController() { }

	void loadRanks() {
		string line, name, score;
		ifstream reader("Ranks.txt");
		while (getline(reader, line)) {
			stringstream ss(line);
			getline(ss, name, ' ');
			getline(ss, score, ' ');
			ranks.push_back(make_pair(name, stoi(score)));
		}
		reader.close();
	}
	
	void sortRanks() {
		sort(ranks.begin(), ranks.end(), [](pair<string, int>& r1, pair<string, int>& r2) {
			return r1.second > r2.second;
			});
	}
	
	void addRank(string name, int score) {
		ranks.push_back(make_pair(name,  score));
		sortRanks();
		saveRanks();
	}

	void saveRanks() {
		ofstream writer("Ranks.txt");
		for (pair<string, int> rank : ranks) {
			writer << rank.first << ' ' << to_string(rank.second) << '\n';
		}
		writer.close();
	}

	string getRankString() {
		string res = "";
		for (pair<string, int> rank : ranks) {
			res += rank.first + ' ' + to_string(rank.second) + '\n';
		}
		return res;
	}
};