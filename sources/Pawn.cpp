#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Pawn.h"
#include <string>

using namespace std;
using namespace sf;

Pawn::Pawn(Board &board)
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
	if(!pawnTexture.loadFromFile("../textures/pawns.png")){
		
	}
	pawnFigure.setTexture(pawnTexture);
	pawnFigure.setTextureRect(IntRect(50, color*50, 50, 50));
}
