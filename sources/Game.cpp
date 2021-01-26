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

void Game::createPawns(RenderWindow &window, Board &board)
{
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			Vector2f pos = board.boardPiece[board.playersYards[(i*4)+j][0]][board.playersYards[(i*4)+j][1]].getPosition();
			pawnsArr[i][j].set_color(i);
				pawnsArr[i][j].startingPosition = Vector2f(pos.x, pos.y-20);
			pawnsArr[i][j].set_position(board);
			//cout << endl << board.boardPiece[2][9].getPosition().y;
			pawnsArr[i][j].draw(window);
		}
	}
}

Game::~Game()
{
	isRun = false;
}

