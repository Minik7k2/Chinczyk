#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
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
	board->draw(window);
	cube->draw(window);
	Sleep(250);
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

void Game::load_components(RenderWindow &window)
{
		board = new Board(window);
		cube = new Cube();
		createPlayers(window, *board);
		//this->createPawns(window, *board);
}

void Game::live_in_game(RenderWindow &window, Vector2f mousePos)
{
	for (int i=1;i<=4;)
	{
		nextTurn = false;
		while(nextTurn == true)
		{
			cout<<endl<<"Gracz "<<i;
			
			switch(i)
			{
				case 1:
					cube->set_position(225,225);
				break;		
				case 2:
					cube->set_position(225,575);
				break;
			}		
		}
		
		i++;
	}
}

Game::~Game()
{
	isRun = false;
}

