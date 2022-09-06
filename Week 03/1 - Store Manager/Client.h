#pragma once
#include <string>

class Client {
private:
	std::string id;
	std::string name;
public:
	Client(std::string id, std::string name) {
		this->id = id;
		this->name = name;
	}

	~Client() { }

	std::string getId() {
		return this->id;
	}

	std::string getName() {
		return this->name;
	}
};