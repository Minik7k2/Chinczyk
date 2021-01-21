#pragma once
#include "SFML/Graphics.hpp"

#define COLUMN_NUMBER_OF_PIECES 17
#define ROW_NUMBER_OF_PIECES 17

class Board
{
public:
	Board(float width, float height);
	~Board();

	void draw(sf::RenderWindow &window);

private:
	int sizeOfPiece;
	
	sf::RectangleShape boardPiece[ROW_NUMBER_OF_PIECES][COLUMN_NUMBER_OF_PIECES];
	sf::Font font;
	sf::Text logo;
	sf::Text menu;
};
