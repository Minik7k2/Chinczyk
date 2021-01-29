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
	
	window.clear();
	board->draw(window);
	cube->draw(window, cubeOutput-1);
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
	if(round == 0)
	{
		playerTurn = 0;
		round++;
	}
	else
	{
		if(mousePos.x >= cube->get_position().x && mousePos.x <= cube->get_position().x+50 && mousePos.y >= cube->get_position().y && mousePos.y <= cube->get_position().y+50)
		{
			cubeOutput = cube->throw_cube();
			cout<<"Kostka "<<cubeOutput<<endl;
		}
		else
		{
			cout<<"Tura: "<<round<<endl;
			if(cubeOutput <= 5)
			{
				for(int j=0;j<4;j++)
				{
					
				}
			}
			else if(cubeOutput == 6)
			{
				for(int j=0;j<4;j++)
				{
				
				}
			}
			else
			{
				if (playerTurn == 3)
				{
					playerTurn = 0;
				}
				else		
				{
					playerTurn++;				
				}
			}
			round++;
		}
	}

		
	switch(playerTurn)
	{
		case 0:
			cube->set_position(225,225);
			cout<<"Gracz "<<playerTurn<<" wyrzuci³ "<<cubeOutput<<endl;		
		break;		
		case 1:
			cube->set_position(575,225);
			cout<<"Gracz "<<playerTurn<<" wyrzuci³ "<<cubeOutput<<endl;
		break;
		case 2:
			cube->set_position(575,575);
			cout<<"Gracz "<<playerTurn<<" wyrzuci³ "<<cubeOutput<<endl;
		break;
		case 3:
			cube->set_position(225,575);
			cout<<"Gracz "<<playerTurn<<" wyrzuci³ "<<cubeOutput<<endl;
		break;
	}

}

Game::~Game()
{
	isRun = false;
}

