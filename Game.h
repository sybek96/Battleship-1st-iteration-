#ifndef _GAME
#define _GAME

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

/// <summary>
/// The controller class that controls the game.
/// </summary>

class Game
{
	//enumerator defining game states
	enum class GameState { CUSTOMISE, DEPLOY_SHIPS, PLAY, WON, LOST, OPTIONS };

public:
	//default constructor
	Game();

	//destructor
	~Game();

	//game loop
	void run();
private:
	/***********************   FUNCTIONS    **********************/

	//process window events
	void processEvents();

	//update game
	void update(double dt);

	//draw fucntion
	void render();

	//clicked ship method
	void shipClicked(int id);

	//Method to finish customising
	void doneCustomising();

	//Function that starts the gameplay
	void gameStart();

	//Add 1 turn to player
	void addPlayerTurn();

	//change to game winning screen
	void gameWonScreen();

	//add turn to AI
	void addAITurn();

	//go to game lost screen
	void gameLostScreen();

	//open options screen
	void optionsScreen();

	//exit the application
	void exitApplication();

	//placing ship on board
	void placeShip(Ship s, Square sq);

	//select a square
	void selectSquare(Square sq);

	//select a random square
	void selectRandomSquare();

	/******************   MEMBER VARIABLES    *****************/

	//the game render window
	sf::RenderWindow m_window;


	//current game state
	GameState m_currentGameState = GameState::CUSTOMISE;

	//the player
	std::unique_ptr<Player> m_player;

	//the board
	std::unique_ptr<Board> m_board;
};

#endif // !_GAME
