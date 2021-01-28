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
	pawnFigure.move(0,-5);
}
void Pawn::highlightOff()
{
	pawnFigure.setTextureRect(IntRect(0, pawnColor*50, 50, 50));
	pawnFigure.move(0,5);
}

void Pawn::changeFieldGroup(int x)
{
	fieldGroup = x;
}

void Pawn::move(int cubeOutput, Board &board)
{
	if(fieldGroup == 0 && cubeOutput==6)
	{
		changeFieldGroup(1);
		pawnFigure.setPosition(startingPoint);
		pathPosition = pawnColor*12; // zeby sprawdzic ktory to -> pathElements[(color*14)+pathPosition]
		
	}else if(fieldGroup == 1)
	{
		if(pathPosition+cubeOutput >=48)
			pathPosition = pathPosition + cubeOutput - 48;
		else{
			for(int i=1; i<=cubeOutput; i++){
				pathPosition++;
				if(pathPosition == ((pawnColor*12)-3<0 ? 48+((pawnColor*12)-3) : (pawnColor*12)-3)){
					changeFieldGroup(2);
					cubeOutput -= i;
					homePosition = 0;
					
					break;
				}
			}
		}
		pawnFigure.setPosition(board.getPosition(board.pathElements[pathPosition]));
	}
	if(fieldGroup == 2 && cubeOutput > 0)
	{
		if(homePosition + cubeOutput < 4)
		{
				homePosition += (homePosition == 0) ? cubeOutput-1 : cubeOutput;
				pawnFigure.setPosition(board.getPosition(board.playersHomeWays[(pawnColor*4)+homePosition]));
			
		}else if(homePosition + cubeOutput == 4)
		{
			homePosition = -1;
			ableToMove = false;
			pawnFigure.setPosition(board.getPosition(board.playersHomes[pawnColor]));
		}
	}
	
}


Pawn::~Pawn()
{
}
