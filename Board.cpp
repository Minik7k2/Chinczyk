#include "Board.h"
#include <iostream>

using namespace std;


Board::Board(float width, float height)
{
	sizeOfPiece = width/17;
	
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++){
			boardPiece[i][j].setSize(sf::Vector2f(sizeOfPiece, sizeOfPiece));
			boardPiece[i][j].setFillColor(sf::Color(150, 50, 250));
			boardPiece[i][j].setOutlineThickness(1.f);
			boardPiece[i][j].setOutlineColor(sf::Color(250, 150, 100));
		}
	}
}

Board::~Board()
{
}

void Board::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++)
			window.draw(boardPiece[i][j]);
	}
}
