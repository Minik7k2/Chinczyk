#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Game.h"
#include "Board.h"
#include "Cube.hpp"
#include "windows.h"

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
	Board *board = new Board(window.getSize().x, window.getSize().y, window);
	Cube *cube = new Cube(219,580);
	cube->draw(window);
	Sleep(250);
	delete(cube);
}

Game::~Game()
{
	isRun = false;
}

