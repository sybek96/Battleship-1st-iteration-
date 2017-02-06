#pragma once
#include <iostream>
#include <vector>
#include "Part.h"
#include "Accessory.h"
//ship class

class Ship
{
	enum class Orientation{RIGHT,UP,LEFT,DOWN};
public:
	enum class Colour { GREEN, RED, BLUE, YELLOW };

	Ship(int size, int row, int col, int id);
	~Ship();
	void changeColour(Colour c);
	void assignAccessory();
	void randomColour();
	void randomAccessory();
	void rotate();

	//getters/setters
	bool getSelected() const;
	void setSelected(bool selected);
	int getID() const;

private:
	int m_size;
	int m_row;
	int m_column;
	Orientation m_orientation = Orientation::RIGHT;
	bool m_selected;
	Colour m_colour = Colour::BLUE;
	bool m_destroyed;
	int m_id;
	std::vector<Part> m_parts;
	std::vector<Accessory> m_accessories;
};

