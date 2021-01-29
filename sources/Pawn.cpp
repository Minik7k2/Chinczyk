#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Pawn.hpp"
#include <string>

using namespace std;
using namespace sf;

Pawn::Pawn()
{
	
}

void Pawn::draw(RenderWindow &window)
{
	window.draw(pawnFigure);
}

void Pawn::set_color(int color)
{
	pawnColor = color;
	loadTexture();
}

void Pawn::loadTexture()
{
	if(!pawnTexture.loadFromFile("../textures/pawns.png"))
	{
		
	}
	pawnFigure.setTexture(pawnTexture);
	pawnFigure.setTextureRect(IntRect(0, pawnColor*50, 50, 50));
}

void Pawn::setOnStart()
{
	pawnFigure.setPosition(startingPosition);
	fieldGroup = 0;
}

void Pawn::highlightOn()
{
	pawnFigure.setTextureRect(IntRect(50, pawnColor*50, 50, 50));
}
void Pawn::highlightOff()
{
	pawnFigure.setTextureRect(IntRect(0, pawnColor*50, 50, 50));
}

void Pawn::changeFieldGroup(int x)
{
	fieldGroup = x;
}

bool Pawn::checkIfAbleToMove(int cubeOutput)
{
	ableToMove = false;
	switch(fieldGroup)
	{
		case 0:
			if(cubeOutput==6){
				ableToMove = true;
				return ableToMove;
			}
			break;
		case 1:
		{
			if(((pawnColor*12)-3<0 ? 48+((pawnColor*12)-3)<pathPosition : (pawnColor*12)-3>pathPosition) && (cubeOutput > 5))
			{
				ableToMove = false;
				return ableToMove;
			}else{
				ableToMove = true;
				return ableToMove;
			}
		}
		break;
		case 2:
		{
			if(homePosition + cubeOutput <= 4)
			{
				ableToMove = true;
				return ableToMove;
			}
		}
		break;
		case 3:
			return ableToMove;
		break;
	}
	return ableToMove;
}

void Pawn::move(int cubeOutput, Board &board)
{
	if(checkIfAbleToMove(cubeOutput)){
	switch(fieldGroup)
	{
		case 0:
			{
				if(cubeOutput==6)
				{
					changeFieldGroup(1);
					pawnFigure.setPosition(startingPoint);
					pathPosition = pawnColor*12; // zeby sprawdzic ktory to -> pathElements[(color*12)+pathPosition]
				}
			}
			break;
		case 1:
			{
					for(int i=0; i<cubeOutput; i++){
						pathPosition++;
						if(pathPosition >= 48) pathPosition = 0;
						if(pathPosition == ((pawnColor*12)-3<0 ? 48+((pawnColor*12)-3) : (pawnColor*12)-3)){
							changeFieldGroup(2);
							if(cubeOutput-(i+1) > 0){
								move(cubeOutput-(i+1),board);
							}else{
								pawnFigure.setPosition(board.getPosition(board.pathElements[pathPosition]));
							}
							
							break;
						}
					}
				if(fieldGroup == 1)
					pawnFigure.setPosition(board.getPosition(board.pathElements[pathPosition]));
			}
			break;
		case 2:
			{
				
					if(pathPosition == ((pawnColor*12)-3<0 ? 48+((pawnColor*12)-3) : (pawnColor*12)-3) && (0 + (cubeOutput-1)) < 4){
						homePosition = 0 + (cubeOutput-1);
						pawnFigure.setPosition(board.getPosition(board.playersHomeWays[(pawnColor*4)+homePosition]));
						pathPosition = NULL;
					}
					else if(homePosition+cubeOutput < 4)
					{
						homePosition += cubeOutput;
						pawnFigure.setPosition(board.getPosition(board.playersHomeWays[(pawnColor*4)+homePosition]));
						//cout<<"Dunno";
						
					}
					else if(homePosition+cubeOutput == 4){
						homePosition+=cubeOutput;
						cout << endl << homePosition<<" Player "<<pawnColor<<"-------------XD";
						//cout<<"HELLO";
						pawnFigure.setPosition(board.getPosition(board.playersHomes[pawnColor]));
					}else if((0 + (cubeOutput-1)) == 4){
						fieldGroup = 3;
						pawnFigure.setPosition(board.getPosition(board.playersHomes[pawnColor]));
					}
			}
	}
	ableToMove = false;

	cubeOutput = 0;
	}
}

void Pawn::scaleDown(int position)
{
	pawnFigure.scale(Vector2f(0.5, 0.5));
	switch(position)
	{
		case 0:
			pawnFigure.move(Vector2f(0, 15));
			break;
		case 1:
			pawnFigure.move(Vector2f(25, 15));
			break;
		case 2:
			pawnFigure.move(Vector2f(0, 40));
			break;
		case 3:
			pawnFigure.move(25, 40);
			break;
	}
}
void Pawn::scaleUp(int position)
{
	pawnFigure.scale(Vector2f(2, 2));
	switch(position)
	{
		case 0:
			pawnFigure.move(Vector2f(0, -15));
			break;
		case 1:
			pawnFigure.move(Vector2f(-25, -15));
			break;
		case 2:
			pawnFigure.move(Vector2f(0, -40));
			break;
		case 3:
			pawnFigure.move(-25, -40);
			break;
	}
}

Pawn::~Pawn()
{
}
