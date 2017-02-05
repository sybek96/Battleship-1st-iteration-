#pragma once
#include <SFML\Graphics.hpp>
#include "Ship.h"
class Square
{
public:
	//constructor
	Square(sf::Vector2i position);

	//destructor
	~Square();


	//Getters/setters
	bool getSelected() const;
	void setSelected(bool select);

	//assign ship to square
	void assignShip(Ship*);
private:


	//see if a ship is on square
	Ship checkContents();

	//position
	sf::Vector2i m_position;

	//bool to check if square is selectable
	bool m_selectable;

	//ship that is currently on square
	Ship* m_ship;

	//check if square currently selected
	bool m_selected;

};

