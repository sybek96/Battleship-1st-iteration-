#pragma once
#include <vector>
#include <memory>
#include "Square.h"
/// <summary>
/// Board class that contains squares
/// </summary>

class Board
{
public:
	//default constructor
	Board(int size);

	//destructor
	~Board();

	//place the ship on a square
	void placeShip(Ship s, Square sq);

	//select a square
	void selectSquare(Square sq);

	//select random square
	void selectRandomSquare();

private:
	//Size of row/col (n x n)
	int m_size;

	//vector of unique ptrs to squares
	std::vector<std::unique_ptr<Square>> m_squares;

	//count current col index
	int m_countCol;

	//count current row
	int m_countRow;
};

