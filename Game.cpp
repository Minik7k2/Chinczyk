#include "Game.h"
#include <iostream>
using namespace std;

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

Game::~Game()
{
	isRun = false;
}
