#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Game.hpp"
#include "Board.hpp"

using namespace std;
using namespace sf;

Game::Game(bool r)
{
	isRun = r;
}

void Game::set_isRun()
{
	isRun = true;
}

bool Game::check_isRun()
{
 	return isRun;
}

void Game::draw(RenderWindow &window, Board &board)
{
	board.draw(window);
}

Game::~Game()
{
	isRun = false;
}

