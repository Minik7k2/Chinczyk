#pragma once
#include "SFML/Graphics.hpp"
#include <string>

#define COLUMN_NUMBER_OF_PIECES 17
#define ROW_NUMBER_OF_PIECES 17

class Board
{
public:
	Board(float width, float height, sf::RenderWindow &window);
	~Board();

	void draw(sf::RenderWindow &window);

private:
	int sizeOfPiece;
	
	sf::RectangleShape boardPiece[ROW_NUMBER_OF_PIECES][COLUMN_NUMBER_OF_PIECES];
	sf::Font font;
	sf::Text logo;
	sf::Text menu;
	int pathElements[48][3]; //[id][0=x, 1=y, 2=typ_pola]
	int startingPoint[3] = {1, 7}; 
	int directions[12] = {0,1,0,2,0,2,3,2,3,1,3,1};
};
