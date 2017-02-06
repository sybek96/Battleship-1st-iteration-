#pragma once
#include "Ship.h"
#include <vector>
#include <memory>
//The player class

class Player
{
	enum class Colour { GREEN, RED, BLUE, YELLOW };
public:
	Player();
	~Player();
	void shipClicked(int id);
	void changeColour();
	void selectShipAccessory();
	void rotateShip();
	bool attackEnemy();
	void addTurn();
	void addScore();
private:
	int m_turns;
	int m_score;
	std::vector<std::shared_ptr<Ship>> m_ships;
	bool m_attack;
};

