#pragma once
#include <memory>
#include <vector>
#include "Ship.h"

class AI
{
public:
	AI();
	~AI();
	void randomiseAI();
	void randomiseAIShips();
	void attackPlayer();
	void addTurn();
	std::vector<std::shared_ptr<Ship>> getShips();

private:
	int m_turns;
	bool m_attack;
	std::vector<std::shared_ptr<Ship>> m_ships;
};

