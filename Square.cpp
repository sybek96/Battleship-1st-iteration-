#include "Square.h"


/// <summary>
/// Default square constructor
/// takes in position row/column
/// </summary>
/// <param name="position"></param>
Square::Square(sf::Vector2i position)
	: m_position(position)
	, m_selectable(true)
	, m_ship(nullptr)
{
}

/// <summary>
/// Destructor
/// </summary>
Square::~Square()
{
}

/// <summary>
/// Check if square is selected
/// </summary>
/// <returns></returns>
bool Square::getSelected() const
{
	return m_selected;
}

/// <summary>
/// Assign selected to passed argument
/// </summary>
/// <param name="select"></param>
void Square::setSelected(bool select)
{
	m_selected = select;
}

/// <summary>
/// assign a ship to this square
/// </summary>
void Square::assignShip(Ship* ship)
{
	m_ship = ship;
}

/// <summary>
/// Check if this square has a ship
/// </summary>
Ship Square::checkContents()
{
	if(m_ship != nullptr)
	{
		return *m_ship;
	}
}
