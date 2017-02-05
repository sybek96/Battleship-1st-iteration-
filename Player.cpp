#include "Player.h"


//constructor
Player::Player()
	: m_turns(0)
	, m_score(0)
{
	int m_shipsId = 0;
	for (int i = 0; i < 5; i++) //create all ships
	{
		m_ships.push_back(std::shared_ptr<Ship>(new Ship(1, 0, 0, m_shipsId)));
		m_shipsId += 1;
	}
}

//destructor
Player::~Player()
{
}

/// <summary>
/// Method to select a ship
/// unselects currently selected ship and selects current one
/// </summary>
/// <param name="id"></param>
void Player::shipClicked(int id)
{
	for (auto & ship : m_ships)
	{
		if (ship->getID() == id && ship->getSelected() == false) //find ship with same ID + check if its currently selected
		{
			for (auto & ship : m_ships) //look for currently selected ship and unselect
			{
				if (ship->getSelected() == true)
				{
					ship->setSelected(false);
				}
			}
			ship->setSelected(true); //select the new ship
		}
	}
}

/// <summary>
/// Change colour of ship (currently just to green)
/// </summary>
void Player::changeColour()
{
	for (auto & ship : m_ships)
	{
		ship->changeColour(Ship::Colour::GREEN);
	}
}

void Player::selectShipAccessory()
{
}

/// <summary>
/// Call the rotate method of the selected ship
/// </summary>
void Player::rotateShip()
{
	for (auto & ship : m_ships) //run through ships and rotate currently selected ship
	{
		if (ship->getSelected() == true)
		{
			ship->rotate();
		}
	}
}

/// <summary>
/// Bool that returns if attacking enemy
/// </summary>
/// <returns></returns>
bool Player::attackEnemy()
{
	if (m_attack == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Increment turns by 1
/// </summary>
void Player::addTurn()
{
	m_turns++;
}

/// <summary>
/// Add 100 score
/// </summary>
void Player::addScore()
{
	m_score += 100;
}
