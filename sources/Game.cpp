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

bool Game::security_verification(int player_positon)
{
	bool isSecurity = false;
	for(int k=0;k<8;k++)
	{
		if(player_positon == special_tile[k])
		{
			isSecurity = true;
			break;
		}
		else
		{
			isSecurity = false;
		}
	}
	
	return isSecurity;
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
<<<<<<< Updated upstream
		cout<<"Gracz"<<i<<endl;
=======
		cout<<"Tura: "<<playerTurn<<endl;
>>>>>>> Stashed changes
		
		switch(i)
		{
<<<<<<< Updated upstream
			case 1:
				cube->set_position(220,230);
			break;		
			case 2:
				cube->set_position(220,530);
			break;
		}		
		i++;
=======
			cubeOutput = cube->throw_cube();
			cout<<"Kostka "<<cubeOutput<<endl;
		}
			
			if(cubeOutput <= 5)
			{
				int users_in_move_cancel = 0;
		
				for(int k=0;k<4;k++)
				{
					if(players[playerTurn].playerPawns[k].checkIfAbleToMove(cubeOutput) == true)
					{
						players[playerTurn].playerPawns[k].highlightOn();	
					}
					else
					{
						users_in_move_cancel++;
					}
				}
						
				if(users_in_move_cancel == 4)
				{
					cubeOutput = 7;
					playerTurn++;
				}
				else
				{
					for(int h=0;h<4;h++)
					{		
						if(mousePos.x >= players[playerTurn].playerPawns[h].pawnFigure.getPosition().x && mousePos.x <= players[playerTurn].playerPawns[h].pawnFigure.getPosition().x+50 && mousePos.y >= players[playerTurn].playerPawns[h].pawnFigure.getPosition().y && mousePos.y <= players[playerTurn].playerPawns[h].pawnFigure.getPosition().y+50)
						{
							if(players[playerTurn].playerPawns[h].checkIfAbleToMove(cubeOutput) == true)
							{
								players[playerTurn].playerPawns[h].move(cubeOutput, *board);
							
								for(int i=0;i<4;i++)
								{
									players[playerTurn].playerPawns[i].highlightOff();
								}		
								
								cubeOutput = 7;
								if(security_verification(players[playerTurn].playerPawns[h].pathPosition) == false)
								{
									for(int i=0;i<4;i++)
									{
										if(playerTurn != i)
										{
											for(int j=0;j<4;j++)
											{
												if(players[playerTurn].playerPawns[h].pathPosition == players[i].playerPawns[j].pathPosition)
												{
													cout<<"Gracz: "<<playerTurn<<" bije pionek gracza "<<i<<endl;
													players[i].playerPawns[j].setOnStart();
													attack = true;
												}	
											}
										}
									}
								}
								
								if(playerTurn == 3)
								{
									playerTurn = 0;
								}
								else
								{
									if(attack == true)
									{
										attack = false;
									}
									else
									{
										playerTurn++;	
									}
								}
								
							}
						}
					}		
				}
			}
			else if(cubeOutput == 6)
			{
				for(int i=0;i<4;i++)
				{
					players[playerTurn].playerPawns[i].highlightOn();
				}
						
				for(int j=0;j<4;j++)
				{			
					if(mousePos.x >= players[playerTurn].playerPawns[j].pawnFigure.getPosition().x && mousePos.x <= players[playerTurn].playerPawns[j].pawnFigure.getPosition().x+50 && mousePos.y >= players[playerTurn].playerPawns[j].pawnFigure.getPosition().y && mousePos.y <= players[playerTurn].playerPawns[j].pawnFigure.getPosition().y+50)
					{
						players[playerTurn].playerPawns[j].move(cubeOutput, *board);
							
						for(int i=0;i<4;i++)
						{
							players[playerTurn].playerPawns[i].highlightOff();
						}
						cubeOutput = 7;
					}
				}
			}

			cout<<endl;
			round++;	
			if(playerTurn == 4)
			{
				playerTurn = 0;
			}
	}

	switch(playerTurn)
	{
		case 0:
			cube->set_position(225,225);
			cout<<"Gracz "<<playerTurn<<endl;		
		break;		
		case 1:
			cube->set_position(575,225);
			cout<<"Gracz "<<playerTurn<<endl;
		break;
		case 2:
			cube->set_position(575,575);
			cout<<"Gracz "<<playerTurn<<endl;
		break;
		case 3:
			cube->set_position(225,575);
			cout<<"Gracz "<<playerTurn<<endl;
		break;
		default:
			cout<<"Gracz "<<playerTurn<<endl;
		break;
>>>>>>> Stashed changes
	}
}

Game::~Game()
{
	isRun = false;
}

