#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Pawn
{
public:
	Pawn(sf::RenderWindow &window, sf::Board board);
	~Pawn();

	void draw(sf::RenderWindow &window);
	
	int color;
	int startingPointID;
	

private:
	
		
	sf::Image pawns[ROW_NUMBER_OF_PIECES][COLUMN_NUMBER_OF_PIECES];
	sf::Texture pawns;
	sf::Image pawnsImgs[4]; //[0=zwykle_pola, 1=start, 2=pre_home, 3=home]
	void loadTextures();
	
};


/*
KOLORY POLA:
0 = none
1 = neutral
2 = blue
3 = green
4 = violet
5 = red

TYPY POLA:
0 = normal
1 = starting
2 = pre_home
3 = home


*/
