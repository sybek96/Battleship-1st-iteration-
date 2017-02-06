#include "AI.h"



AI::AI()
{
	int m_shipsId = 5+1; //size of players ships plus 1 for debug purposes normally ui determined
	for (int i = 0; i < 5; i++) //create all ships
	{
		m_ships.push_back(std::shared_ptr<Ship>(new Ship(1, 0, 0, m_shipsId)));
		m_shipsId += 1;
	}
}


AI::~AI()
{
}

void AI::randomiseAI()
{
	for (auto & ship : m_ships) //go through ships and random customise
	{
		ship->randomColour();
		ship->randomAccessory();
	}
}


void AI::attackPlayer()
{
}

void AI::addTurn()
{
}

std::vector<std::shared_ptr<Ship>> AI::getShips()
{
	return m_ships;
}

