#include "Ship.h"


//constructor
Ship::Ship(int size, int row, int col, int id)
	: m_size(size)
	, m_row(row)
	, m_column(col)
	, m_selected(false)
	, m_destroyed(false)
	, m_id(id)
{
	for (int i = 0; i < m_size; i++) //create parts equal size of ship
	{
		m_parts.push_back(Part());
	}
}

//destructor
Ship::~Ship()
{
}

/// <summary>
/// Change the colour of the ship
/// </summary>
/// <param name="c"></param>
void Ship::changeColour(Colour c)
{
	m_colour = c;
}

/// <summary>
/// Assign a new accessory for the ship
/// current iteration does not take into account different accessories
/// or stacking of accessories
/// </summary>
void Ship::assignAccessory()
{
	m_accessories.push_back(Accessory());
}

/// <summary>
/// Assigns a random colour to the ships
/// </summary>
void Ship::randomColour()
{
	int randNum;
	randNum = rand() % 4 + 1; //generate num between 1 and 4
	switch (randNum) //depending on rand num assign rand colour
	{
	case 1:
		m_colour == Colour::BLUE;
		break;
	case 2:
		m_colour == Colour::RED;
		break;
	case 3:
		m_colour == Colour::YELLOW;
		break;
	case 4:
		m_colour == Colour::GREEN;
		break;
	default:
		break;
	}
}

/// <summary>
/// This method would normally have a number that 
/// randomly assigns an accessory from enum
/// works just like random colour method
/// </summary>
void Ship::randomAccessory()
{
	//assign random accessory
}

/// <summary>
/// Rotates the ship 90 degrees anticlockwise
/// according to the enumerator
/// </summary>
void Ship::rotate()
{
	switch (m_orientation) //rotate ship 90 anti-clockwise
	{
	case Ship::Orientation::RIGHT:
		m_orientation = Orientation::UP;
		break;
	case Ship::Orientation::UP:
		m_orientation = Orientation::LEFT;
		break;
	case Ship::Orientation::LEFT:
		m_orientation = Orientation::DOWN;
		break;
	case Ship::Orientation::DOWN:
		m_orientation = Orientation::RIGHT;
		break;
	default:
		break;
	}
}

/// <summary>
/// Returns if ship is currently selected
/// </summary>
/// <returns></returns>
bool Ship::getSelected() const
{
	return m_selected;
}

/// <summary>
/// Setter to change the selected variable
/// </summary>
/// <param name="selected"></param>
void Ship::setSelected(bool selected)
{
	m_selected = selected;
}

/// <summary>
/// Returns ID of the ship
/// </summary>
/// <returns></returns>
int Ship::getID() const
{
	return m_id;
}

