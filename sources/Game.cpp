#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Game.h"
#include "Board.h"
#include "Cube.h"

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

void Game::draw(RenderWindow &window)
{
	Board board(window.getSize().x, window.getSize().y, window);
	Cube cube(50,219,580,window);
}

Game::~Game()
{
	isRun = false;
}

