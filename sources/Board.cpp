#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace std;
using namespace sf;

Board::Board(float width, float height)
{
	sizeOfPiece = width/17;
	
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++){
			boardPiece[i][j].setSize(Vector2f(sizeOfPiece, sizeOfPiece));
			boardPiece[i][j].setFillColor(Color(150, 50, 250));
			boardPiece[i][j].setOutlineThickness(1.f);
			boardPiece[i][j].setOutlineColor(Color(250, 150, 100));
		}
	}
}

Board::~Board()
{
}

void Board::draw(RenderWindow &window)
{
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++)
			window.draw(boardPiece[i][j]);
	}
}
