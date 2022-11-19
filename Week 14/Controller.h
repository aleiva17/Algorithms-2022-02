#pragma once
#include <vector>
#include "Player.h"
#include "Ghost.h"
#include "PacDot.h"
#include "Bonus.h"

class Controller {
	Player* player;
	vector<Ghost*> enemies;
	vector<PacDot*> pacDots;
	vector<Bonus*> bonuses;

	int maxPoints;
	time_t bonusTime;
	time_t activeBonusTime;
public:
	Controller(int lives, int ghostQty, int pacDotsQty) {
		player = new Player(lives);
		maxPoints = pacDotsQty;
		
		generateEnemies(ghostQty);
		generatePacDots(pacDotsQty);
		addNewBonus();
	}

	~Controller() {
		for (Ghost* enemy : enemies) {
			delete enemy;
		}
		for (PacDot* pacDot : pacDots) {
			delete pacDot;
		}
		for (Bonus* bonus : bonuses) {
			delete bonus;
		}
		enemies.clear();
		pacDots.clear();
		bonuses.clear();
		delete player;
	}

	void generateEnemies(int qty) {
		Random^ gen = gcnew Random();
		int x, y, initCol;

		while (qty--) {
			x = gen->Next(120, 480);
			y = gen->Next(120, 480);
			initCol = 2 * gen->Next(0, 5);
			enemies.push_back(new Ghost(x, y, initCol));
			_sleep(100);
		}

		delete gen;
	}

	void generatePacDots(int qty) {
		Random^ gen = gcnew Random();
		int x, y;

		while (qty--) {
			x = gen->Next(120, 480);
			y = gen->Next(120, 480);
			pacDots.push_back(new PacDot(x, y));
			_sleep(100);
		}

		delete gen;
	}

	void addNewBonus() {
		Random^ gen = gcnew Random();
		int x, y, col;

		if (bonuses.size()) delete bonuses.front();
		bonuses.clear();

		activeBonusTime = time(0);

		x = gen->Next(120, 480);
		y = gen->Next(120, 480);
		col = gen->Next(0, 4);

		bonuses.push_back(new Bonus(x, y, col));
		delete gen;
	}

	void movePlayer(direccion dir) {
		player->desplazamiento(dir);
	}

	void gameManagement(Graphics^ g, Bitmap^ bmpPlayer, Bitmap^ bmpGhost, Bitmap^ bmpBonus, Bitmap^ bmpPacdot) {
		playerManagement(g, bmpPlayer);
		enemyManagement(g, bmpGhost);
		pacDotManagement(g, bmpPacdot);
		bonusManagement(g, bmpBonus);

		collisionManagement();
		bonusTimeManagement();
	}

	void playerManagement(Graphics^ g, Bitmap^ bmp) {
		player->mostrar(g, bmp);
		player->mover(g);
	}

	void enemyManagement(Graphics^ g, Bitmap^ bmp) {
		for (Ghost* enemy : enemies) {
			enemy->mostrar(g, bmp);
			enemy->mover(g);
		}
	}

	void pacDotManagement(Graphics^ g, Bitmap^ bmp) {
		for (PacDot* pacDot : pacDots) {
			pacDot->mostrar(g, bmp);
		}

		for (int i = 0; i < pacDots.size(); ++i) {
			if (pacDots.at(i)->getActive()) continue;
			pacDots.erase(pacDots.begin() + i);
		}
	}

	void bonusManagement(Graphics^ g, Bitmap^ bmp) {
		for (Bonus* bonus : bonuses) {
			bonus->mostrar(g, bmp);
		}

		if (difftime(time(0), activeBonusTime) > 20) {
			addNewBonus();
		}
	}

	void collisionManagement() {
		playerEnemyCollision();
		playerPacDotCollision();
		playerBonusCollision();
	}

	void playerEnemyCollision() {
		for (Ghost* enemy : enemies) {
			if (enemy->getArea().IntersectsWith(player->getArea())) {
				player->decreaseLives();
				player->respawn();
				break;
			}
		}
	}

	void playerPacDotCollision() {
		for (PacDot* pacDot : pacDots) {
			if (pacDot->getArea().IntersectsWith(player->getArea())) {
				pacDot->setActive(false);
				player->increasePoints();
			}
		}
	}

	void playerBonusCollision() {
		for (Bonus* bonus : bonuses) {
			if (bonus->getArea().IntersectsWith(player->getArea())) {
				player->setIsInBonus(true);
				player->desplazamiento(player->getOrientacion());
				bonusTime = time(0);
				addNewBonus();
				break;
			}
		}
	}

	void bonusTimeManagement() {
		if (!player->getIsInBonus()) return;
		if (difftime(time(0), bonusTime) <= 10) return;
		player->setIsInBonus(false);
		player->desplazamiento(player->getOrientacion());
	}

	bool isGameOver() {
		return !player->getActive() || player->getPoints() == maxPoints;
	}

	int getScore() {
		return player->getPoints();
	}
};
