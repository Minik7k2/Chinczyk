#include <iostream>
<<<<<<< Updated upstream
#include "SFML/Graphics.hpp" 
#include "Game.h"
#include "Board.h"
#include "Cube.hpp"
#include "windows.h"
=======
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <windows.h>
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
	Board *board = new Board(window.getSize().x, window.getSize().y, window);
	Cube *cube = new Cube(219,580);
	cube->draw(window);
	Sleep(250);
	delete(cube);
=======
	board->draw(window);
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
>>>>>>> Stashed changes
}

void Game::load_components(RenderWindow &window)
{
		board = new Board(window);
		cube = new Cube();
		this->createPawns(window, *board);
}

void Game::live_in_game(RenderWindow &window)
{
	for (int i=1;i<=4;)
	{
		cout<<"Gracz"<<i<<endl;
		
		if(i == 3)// to bedzie switch i case hipotetycznie cwel wyrzucil 6
		{
			//if () sprawdz 6
			i--;
		}
		
		i++;
	}
}

Game::~Game()
{
	isRun = false;
}

