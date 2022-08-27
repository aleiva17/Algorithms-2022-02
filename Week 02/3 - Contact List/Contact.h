#pragma once
#include <string>

class Contact {
private:
	std::string name;
	int phoneNumber;
	char genre;
	std::string career;
	std::string birthdate;
	std::string email;
	std::string socialNetwork;
public:
	Contact(std::string name, int phoneNumber, char genre, std::string career, std::string birthdate, std::string email, std::string socialNetwork) {
		this->name = name;
		this->phoneNumber = phoneNumber;
		this->genre = genre;
		this->career = career;
		this->birthdate = birthdate;
		this->email = email;
		this->socialNetwork = socialNetwork;
	}

	~Contact() { }

	void toString() {
		std::cout << "NAME: " << this->name << " | PHONE: " << this->phoneNumber << " | GENRE: " << this->genre << " | CAREER: " << this->career << " | BIRTHDATE: " << this->birthdate << " | EMAIL: " << this->email << " | SOCIAL NETWORK: " << this->socialNetwork << '\n';
	}

	char getGenre() {
		return this->genre;
	}

	std::string getSocialNetwork() {
		return this->socialNetwork;
	}

	std::string getBirthdate() {
		return this->birthdate;
	}

	void setName(std::string name) {
		this->name = name;
	}

	void setPhoneNumber(int phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	void setGenre(char genre) {
		this->genre = genre;
	}
	
	void setCareer(std::string career) {
		this->career = career;
	}
	
	void setBirthdate(std::string birthdate) {
		this->birthdate = birthdate;
	}
	
	void setEmail(std::string email) {
		this->email = email;
	}

	void setSocialNetwork(std::string socialNetwork) {
		this->socialNetwork = socialNetwork;
	}

};