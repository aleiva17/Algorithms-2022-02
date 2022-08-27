#pragma once
#include <string>

class Account {
private:
	std::string client;
	float balance;
public:
	Account(std::string client) {
		this->client = client;
		this->balance = 0;
	}

	Account(std::string client, float balance) {
		this->client = client;
		this->balance = balance;
	}

	~Account() { }

	bool deposit(float amount) {
		if (amount <= 0) {
			return false;
		}

		this->balance += amount;
		return true;
	}

	bool withdraw(float amount) {
		if (amount > this->balance || amount <= 0) {
			return false;
		}

		this->balance -= amount;
		return true;
	}

	void setClient(std::string client) {
		this->client = client;
	}

	void setBalance(float amount) {
		this->balance = amount;
	}

	std::string getClient() {
		return this->client;
	}

	float getBalance() {
		return this->balance;
	}
};