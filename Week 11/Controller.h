#pragma once
#include "Player.h"
#include "VectorCoins.h"
#include <string>

class Controller {
	Player* player;
	VectorCoins* coins;
public:
	Controller() {
		this->player = new Player();
		this->coins = new VectorCoins();
	}

	~Controller() {
		delete this->player, this->coins;
	}

	void keyManagement(direccion dir) {
		player->desplazamiento(dir);
	}

	void mostrarEscenario(Graphics^ g, Bitmap^ bmp) {
		int w = bmp->Width;
		int h = bmp->Height;
		Rectangle porcion = Rectangle(0, 0, w, h);

		Rectangle aumentoMapa = Rectangle(0, 0, w * 0.8, h * 0.8);
		Rectangle aumentoMapa2 = Rectangle(w * 0.8, 0, w * 0.8, h * 0.8);
		Rectangle aumentoMapa3 = Rectangle(0, h * 0.8, w * 0.8, h * 0.8);
		Rectangle aumentoMapa4 = Rectangle(w * 0.8, h * 0.8, w * 0.8, h * 0.8);

		g->DrawImage(bmp, aumentoMapa, porcion, GraphicsUnit::Pixel);
		g->DrawImage(bmp, aumentoMapa2, porcion, GraphicsUnit::Pixel);
		g->DrawImage(bmp, aumentoMapa3, porcion, GraphicsUnit::Pixel);
		g->DrawImage(bmp, aumentoMapa4, porcion, GraphicsUnit::Pixel);
	}

	void gameManagement(Graphics^ g, Bitmap^ bmpEscenario, Bitmap^ bmpPlayer, Bitmap^ bmpCoin) {
		mostrarEscenario(g, bmpEscenario);
		playerManagement(g, bmpPlayer);
		coinManagement(g, bmpCoin);
		collisionPlayerCoin();
	}

	void playerManagement(Graphics^ g, Bitmap^ bmp) {
		player->mostrar(g, bmp);
		player->mover(g);
	}

	void coinManagement(Graphics^ g, Bitmap^ bmp) {
		this->coins->addCoin(600, 600);
		this->coins->mostrarMonedas(g, bmp);
		this->coins->removerMonedas();
	}

	void collisionPlayerCoin() {
		Rectangle r1 = this->player->getArea();
		std::vector<Coin*> vCoins = this->coins->getCoins();

		for (int i = 0; i < vCoins.size(); ++i) {
			if (r1.IntersectsWith(vCoins.at(i)->getArea())) {
				this->player->addPoint();
				vCoins.at(i)->setActive(false);
				break;
			}
		}
	}

	int getPoints() {
		return this->player->getPoints();
	}
};