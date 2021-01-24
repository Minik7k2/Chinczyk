#pragma once
#include "SFML/Graphics.hpp"
#include <string>

#define COLUMN_NUMBER_OF_PIECES 17
#define ROW_NUMBER_OF_PIECES 17

using namespace sf;

class Board
{
	public:
		Board(float width, float height, RenderWindow &window);
	
		void draw(RenderWindow &window);
		int pathElements[48][4]; //[id][0=x, 1=y, 2=kolor_pola, 3=typ_pola]
		int playersYards[16][4]; //[id][0=x, 1=y, 2=kolor_pola, 3=typ_pola]
		int playersHomes[4][5];
		~Board();

	private:
		int sizeOfPiece;
		
		Sprite boardPiece[ROW_NUMBER_OF_PIECES][COLUMN_NUMBER_OF_PIECES];
		Font font;
		Text logo;
		Text menu;
		Texture fields;
		Sprite fieldsArr[4][6]; //[0=zwykle_pola, 1=start, 2=pre_home, 3=home]
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
