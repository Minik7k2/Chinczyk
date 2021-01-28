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
}

void Game::createPawns(RenderWindow &window, Board &board)
{
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			Vector2f pos = board.getPosition(board.playersYards[(i*4)+j]);
			pawnsArr[i][j].set_color(i);
			pawnsArr[i][j].startingPosition = Vector2f(pos.x, pos.y-20);
			pawnsArr[i][j].startingPoint = board.getPosition(board.playersStartingPoints[i]);
			pawnsArr[i][j].setOnStart();
			//cout << endl << board.boardPiece[2][9].getPosition().y;
		}
	}
		pawnsArr[0][1].move(6, board);
		pawnsArr[0][1].move(2, board);
		pawnsArr[0][1].move(28, board);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				pawnsArr[i][j].draw(window);
}

void Game::load_components(RenderWindow &window)
{
		board = new Board(window);
		cube = new Cube();
		//this->createPawns(window, *board);
}

void Game::live_in_game(RenderWindow &window)
{
	for (int i=1;i<=4;)
	{
		cout<<"Gracz"<<i<<endl;
		
		switch(i)
		{
			case 1:
				cube->set_position(220,230);
			break;		
			case 2:
				cube->set_position(220,530);
			break;
		}		
		i++;
	}
}

Game::~Game()
{
	isRun = false;
}

