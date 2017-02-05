#include "Game.h"

/// <summary>
/// By: Sebastian Kruzel
/// Title: Battleship
/// Descryption: A first iteration of a battleship game
/// following an agile process
/// Date: 05/02/2017
/// 
/// </summary>

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;


Game::Game()
	: m_window(sf::VideoMode(800u, 600u, 32u), "Battleship", sf::Style::Default)
	, m_player(new Player())
	, m_board(new Board(10))
{
	srand(time(NULL)); //for random seed
}

/// <summary>
/// Main game loop
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;
	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();
		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}
}

/// <summary>
/// process the game events
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// update game
/// </summary>
/// <param name="dt">time</param>
void Game::update(double dt)
{
	//running a few commands to see if program compiles
	shipClicked(1);
	m_player->rotateShip();
	shipClicked(0);
	m_player->rotateShip();
	m_player->changeColour();
}

/// <summary>
/// render all objects on the screen
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.display();
}

/// <summary>
/// A method that tells that a ship has been clicked
/// </summary>
/// <param name="id">ship id</param>
void Game::shipClicked(int id)
{
	m_player->shipClicked(id);
}

/// <summary>
/// This method is called when the customise stage is complete
/// it switches to the deploy stage
/// </summary>
void Game::doneCustomising()
{
	m_currentGameState = GameState::DEPLOY_SHIPS;
}

/// <summary>
/// Called after all ships have been deployed
/// </summary>
void Game::gameStart()
{
	m_currentGameState = GameState::PLAY;
}

/// <summary>
/// Increment players turns by 1
/// </summary>
void Game::addPlayerTurn()
{
	m_player->addTurn();
}

/// <summary>
/// switch to game won state
/// </summary>
void Game::gameWonScreen()
{
	m_currentGameState = GameState::WON;
}

/// <summary>
/// Increment AI turns by 1
/// </summary>
void Game::addAITurn()
{
}

/// <summary>
/// Change to game lost state
/// </summary>
void Game::gameLostScreen()
{
	m_currentGameState = GameState::LOST;
}

/// <summary>
/// Change to options state
/// </summary>
void Game::optionsScreen()
{
	m_currentGameState = GameState::OPTIONS;
}

/// <summary>
/// Exit the application
/// </summary>
void Game::exitApplication()
{
}
/// <summary>
/// place ship on board
/// </summary>
/// <param name="s"></param>
/// <param name="sq"></param>
void Game::placeShip(Ship s, Square sq)
{
	m_board->placeShip(s, sq);
}

/// <summary>
/// Select a square that is currently being hovered
/// </summary>
/// <param name="sq"></param>
void Game::selectSquare(Square sq)
{
	m_board->selectSquare(sq);
}

/// <summary>
/// Select a random square on the board
/// </summary>
void Game::selectRandomSquare()
{
	m_board->selectRandomSquare();
}

/// <summary>
/// destructor for game
/// </summary>
Game::~Game()
{
}
