#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Game.h"
#include "Board.h"

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

void Game::createPawns(Board &board){
	for(int i=0;i<4;i++){
		for(int j=0; j<4; j++){
		}
	}
}

Game::~Game()
{
	isRun = false;
}

