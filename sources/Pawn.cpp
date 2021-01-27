#include <iostream>
#include <SFML/Graphics.hpp>
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
	if(fieldGroup == 0)
	{
		changeFieldGroup(1);
		pawnFigure.setPosition(startingPoint);
		pathPosition = 0; // zeby sprawdzic ktory to -> pathElements[(playerID*14)+pathPosition]
		
	}else if(fieldGroup == 1)
	{
		pathPosition = pathPosition + cubeOutput;
		pawnFigure.setPosition(board.getPosition(board.pathElements[pathPosition]));
	}
}


Pawn::~Pawn()
{
}
