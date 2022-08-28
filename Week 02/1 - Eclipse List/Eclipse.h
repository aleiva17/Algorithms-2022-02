#pragma once
#include <string>
#include <iostream>

class Eclipse {
private:
	std::string eclipseType;
	std::string date;
	int hour;
	bool earthquakes;
	bool rains;
	std::string contHigherVisibility;
public:
	Eclipse(std::string eclipseType, std::string date, int hour, bool earthquakes, bool rains, std::string contHigherVisibility) {
		this->eclipseType = eclipseType;
		this->date = date;
		this->hour = hour;
		this->earthquakes = earthquakes;
		this->rains = rains;
		this->contHigherVisibility = contHigherVisibility;
	}

	~Eclipse() { }

	void toString() {
		std::cout << "Type: " << this->eclipseType << " | Date: " << this->date << " | Hour: " << this->hour << " | Earthquakes: " << (this->earthquakes ? "Yes" : "No") << " | Rains: " << (this->rains ? "Yes" : "No") << " | Continent w/Higher visibility: " << this->contHigherVisibility << '\n';
	}
	
	void setEclipseType(std::string eclipseType) {
		this->eclipseType = eclipseType;
	}

	void setDate(std::string date) {
		this->date = date;
	}

	void setHour(int hour) {
		this->hour = hour;
	}

	void setEarthquakes(bool earthquakes) {
		this->earthquakes = earthquakes;
	}

	void setRains(bool rains) {
		this->rains = rains;
	}

	void setContHigherVisibility(std::string contHigherVisibility) {
		this->contHigherVisibility = contHigherVisibility;
	}

	int getHour() {
		return this->hour;
	}

	bool getEarthquakes() {
		return this->earthquakes;
	}

	std::string getContHigherVisibility() {
		return this->contHigherVisibility;
	}
};