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
	nextTurn = false;
	switch(playerTurn)
			{
				case 0:
					cube->set_position(225,225);
				break;		
				case 1:
					cube->set_position(575,225);
				break;
				case 2:
					cube->set_position(575,575);
				break;
				case 3:
					cube->set_position(225,575);
				break;
			}
			//cout<<endl<<"Gracz "<<playerTurn<<" Mouse Position: "<<mousePos.x;
			if(mousePos.x >= cube->get_position().x && mousePos.x <= cube->get_position().x+50 && mousePos.y >= cube->get_position().y && mousePos.y <= cube->get_position().y+50){
				cubeOutput = cube->throw_cube();
				draw(window);
			}
			if(cubeOutput!=7){
				for(int j=0;j<4;j++){
					if(!players[playerTurn].playerPawns[j].checkIfAbleToMove(cubeOutput)){
						nextTurn = true;
						cubeOutput = 7;
						continue;
					}else{
						players[playerTurn].playerPawns[j].highlightOn();
					}
					if(mousePos.x >= players[playerTurn].playerPawns[j].pawnFigure.getPosition().x && mousePos.x <= players[playerTurn].playerPawns[j].pawnFigure.getPosition().x+50 && mousePos.y >= players[playerTurn].playerPawns[j].pawnFigure.getPosition().y && mousePos.y <= players[playerTurn].playerPawns[j].pawnFigure.getPosition().y+50){
						players[playerTurn].playerPawns[j].move(cubeOutput, *board);
						for(int k=0;k<4;k++)
							players[playerTurn].playerPawns[j].highlightOff();
						cout<<endl<<players[playerTurn].playerPawns[j].pawnFigure.getPosition().y<<" ----------------->";
						if(cubeOutput !=6)
							nextTurn = true;
						cubeOutput = 7;
						draw(window);
					}
				}
				
			}
				
			if(nextTurn == true){
				playerTurn = (playerTurn+1 > 3) ? 0 : playerTurn+1;
			}
}

Game::~Game()
{
	isRun = false;
}

