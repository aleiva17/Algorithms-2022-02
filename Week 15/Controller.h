#pragma once
#include "Pacman.h"
#include "Ghost.h"
#include "PacDot.h"
#include "Bonus.h"

#include <vector>

class Controller {
	Pacman* player;
	vector<Ghost*> ghosts;
	vector<PacDot*> pacDots;
	Bonus* bonus;

	time_t activeDisplayBonusTime;
	time_t playerBonusTime;
	int mxPoints;
public:
	Controller(int lives, int qtyGhosts, int qtyPacDots) {
		player = new Pacman(lives);
		bonus = new Bonus();
		activeDisplayBonusTime = time(0);

		mxPoints = qtyPacDots;
		generateGhosts(qtyGhosts);
		generatePacDots(qtyPacDots);
	}

	~Controller() {
		for (Ghost* ghost : ghosts) {
			delete ghost;
		}
		for (PacDot* pacDot : pacDots) {
			delete pacDot;
		}
		delete player, bonus;
		ghosts.clear();
		pacDots.clear();
	}

	void changeDirection(direccion dir) {
		player->desplazamiento(dir);
	}

	void generateGhosts(int qty) {
		while (qty--) {
			ghosts.push_back(new Ghost());
			 _sleep(50);
		}
	}

	void generatePacDots(int qty) {
		while (qty--) {
			pacDots.push_back(new PacDot());
			_sleep(50);
		}
	}
	
	void generateNewBonus() {
		delete bonus;
		bonus = new Bonus();
	}

	void gameManagement(Graphics^ g, Bitmap^ bmpPacman, Bitmap^ bmpGhost, Bitmap^ bmpPacDot, Bitmap^ bmpBonus) {
		playerManagement(g, bmpPacman);
		ghostManagement(g, bmpGhost);
		pacDotManagement(g, bmpPacDot);
		bonusManagement(g, bmpBonus);
		collisionManagement();
	}

	void playerManagement(Graphics^ g, Bitmap^ bmp) {
		player->mostrar(g, bmp);
		player->mover(g);
		
		if (player->getIsInBonus() && difftime(time(0), playerBonusTime) > 10) {
			player->setIsInBonus(false);
		}
	}

	void ghostManagement(Graphics^ g, Bitmap^ bmp) {
		for (Ghost* ghost : ghosts) {
			ghost->mostrar(g, bmp);
			ghost->mover(g);
		}
	}

	void pacDotManagement(Graphics^ g, Bitmap^ bmp) {
		for (PacDot* pacDot : pacDots) {
			pacDot->mostrar(g, bmp);
		}
		for (int i = 0; i < pacDots.size(); ++i) {
			if (pacDots.at(i)->getActive()) continue;
			delete pacDots.at(i);
			pacDots.erase(pacDots.begin() + i);
			break;
		}
	}

	void bonusManagement(Graphics^ g, Bitmap^ bmp) {
		bonus->mostrar(g, bmp);

		if (difftime(time(0), activeDisplayBonusTime) > 10) {
			generateNewBonus();
			activeDisplayBonusTime = time(0);
		}
	}

	void collisionManagement() {
		playerGhostCollision();
		playerPacDotCollision();
		playerBonusCollision();
	}

	void playerGhostCollision() {
		for (Ghost* ghost : ghosts) {
			if (ghost->getArea().IntersectsWith(player->getArea())) {
				player->decreaseLives();
				player->respawn();
			}
		}
	}

	void playerPacDotCollision() {
		for (PacDot* pacDot : pacDots) {
			if (pacDot->getArea().IntersectsWith(player->getArea())) {
				player->increasePoints();
				pacDot->setActive(false);
			}
		}
	}

	void playerBonusCollision() {
		if (!player->getArea().IntersectsWith(bonus->getArea())) return;

		generateNewBonus();
		player->setIsInBonus(true);
		playerBonusTime = time(0);
	}

	int getPoints() {
		return player->getPoints();
	}

	bool isGameOver() {
		return !player->getActive() || player->getPoints() == mxPoints;
	}
};