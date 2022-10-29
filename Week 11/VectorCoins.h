#pragma once
#include "Coin.h"
#include <vector>

class VectorCoins {
	std::vector<Coin*> coins;
	time_t initTime;
public:
	VectorCoins() {
		initTime = time(0);
	}

	~VectorCoins() {
		for (Coin* coin : this->coins) {
			delete coin;
		}
		this->coins.clear();	
	}

	void addCoin(int width, int height) {
		if (difftime(time(0), this->initTime) < 3) return;
		System::Random^ gen = gcnew System::Random();
		this->coins.push_back(new Coin(gen->Next(0, width - 64), gen->Next(0, width - 64)));
		this->initTime = time(0);
		delete gen;
	}

	void mostrarMonedas(Graphics^ g, Bitmap^ bmp) {
		for (Coin* coin : this->coins) {
			coin->mostrar(g, bmp);
		}
	}

	void removerMonedas() {
		for (int i = 0; i < this->coins.size(); ++i) {
			if (this->coins.at(i)->getActive()) continue;
			this->coins.erase(this->coins.begin() + i);
			break;
		}
	}

	std::vector<Coin*>& getCoins() {
		return this->coins;
	}
};