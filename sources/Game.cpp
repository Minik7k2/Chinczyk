#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Cube.hpp"
#include <windows.h>

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
	Board *board = new Board(window);
	Cube *cube = new Cube(219,580);
	
	createPlayers(window, *board);
	board->draw(window);
	
	
	for(int i=0; i<4; i++)
		players[i].drawPawns(window);
}

void Game::createPlayers(RenderWindow &window, Board &board)
{
	for(int i=0; i<4; i++)
	{
		players[i].setPlayerColor(i);
		for(int j=0; j<4; j++)
			players[i].setPawns(board);
	}
	
}

Game::~Game()
{
	isRun = false;
}

