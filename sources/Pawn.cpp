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
<<<<<<< Updated upstream
		changeFieldGroup(1);
		pawnFigure.setPosition(startingPoint);
		pathPosition = 0; // zeby sprawdzic ktory to -> pathElements[(playerID*14)+pathPosition]
		
	}else if(fieldGroup == 1)
=======
		case 0:
			pawnFigure.move(Vector2f(0, 15));
			break;
		case 1:
			pawnFigure.move(25, 40);
			break;
		case 2:
			pawnFigure.move(Vector2f(25, 15));
			break;
		case 3:
			pawnFigure.move(Vector2f(0, 40));
			break;
	}
}
void Pawn::scaleUp(int position)
{
	pawnFigure.scale(Vector2f(2, 2));
	switch(position)
>>>>>>> Stashed changes
	{
		pathPosition = pathPosition + cubeOutput;
		pawnFigure.setPosition(board.getPosition(board.pathElements[pathPosition]));
	}
}


Pawn::~Pawn()
{
}
