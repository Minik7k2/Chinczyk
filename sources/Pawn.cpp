#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pawn.h"
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

void Pawn::set_position(Board &board)
{
	pawnFigure.setPosition(startingPosition);
}

void Pawn::set_color(int color)
{
	pawnColor = color;
	loadTexture();
}

void Pawn::loadTexture()
{
	if(!pawnTexture.loadFromFile("../textures/pawns.png")){
		
	}
	pawnFigure.setTexture(pawnTexture);
	pawnFigure.setTextureRect(IntRect(0, pawnColor*50, 50, 50));
}

Pawn::~Pawn()
{
}
