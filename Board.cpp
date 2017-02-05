#include "Board.h"


/// <summary>
/// default board constructor takes in a size
/// size determines amount of squares created
/// </summary>
/// <param name="size"></param>
Board::Board(int size)
	: m_size(size)
	, m_countCol(0)
	, m_countRow(0)
{
	for (int i = 1; i < m_size; i++) //loop through squares and assign row and col
	{
		m_countCol++;
		if (m_countCol = m_size + 1)
		{
			m_countCol = 0;
			m_countRow += 1;
		}
		m_squares.push_back(std::unique_ptr<Square>(new Square(sf::Vector2i(m_countCol,m_countRow))));
	}
}

/// <summary>
/// Destructor
/// </summary>
Board::~Board()
{
}

/// <summary>
/// place a ship on a square
/// </summary>
/// <param name="s"></param>
/// <param name="sq"></param>
void Board::placeShip(Ship s, Square sq)
{
	for (auto & square : m_squares)
	{
		if (square->getSelected() == true)
		{
			square->assignShip(&s);
		}
	}
}

/// <summary>
/// A passed in square becomes selected
/// </summary>
/// <param name="sq"></param>
void Board::selectSquare(Square sq)
{
	for (auto & square : m_squares) //see any previously selected squares and deselect
	{
		if (square->getSelected() == true)
		{
			square->setSelected(false);
			continue;
		}
	}
	sq.setSelected(true);
}

/// <summary>
/// select a random square
/// </summary>
void Board::selectRandomSquare()
{
	for (auto & square : m_squares) //see any previously selected squares and deselect
	{
		if (square->getSelected() == true)
		{
			square->setSelected(false);
			continue;
		}
	}
	int randNum = 0;
	randNum = rand() % m_size + 1; //generate num between 1 and board size
	m_squares.at(randNum)->setSelected(true);
}
