#pragma once
#include "SFML/Graphics.hpp"
#include <string>

#define COLUMN_NUMBER_OF_PIECES 17
#define ROW_NUMBER_OF_PIECES 17

class Board
{
public:
	Board(sf::RenderWindow &window);
	~Board();

	void draw(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	int pathElements[48][4]; //[id][0=x, 1=y, 2=kolor_pola, 3=typ_pola]
	int playersYards[16][4]; //[id][0=x, 1=y, 2=kolor_pola, 3=typ_pola]
	int playersHomeWays[16][4]; // [id][0=x, 1=y, 2=kolor_pola, 3=typ_pola]
	int playersHomes[4][4]; //[id][0=x, 1=y, 2=kolor_pola, 3=typ_pola]
	sf::Sprite boardPiece[ROW_NUMBER_OF_PIECES][COLUMN_NUMBER_OF_PIECES];

private:
	int sizeOfPiece;
	void set_pathElements();
	void set_safeFields();
	void set_yards();
	void set_startingPoints();
	void set_homes();
	void set_boardGrid(sf::RenderWindow&window);
		
	
	sf::Font font;
	sf::Text logo;
	sf::Text menu;
	int directions[12] = {0,1,0,2,0,2,3,2,3,1,3,1};
	sf::Texture fields;
	sf::Sprite fieldsArr[4][6]; //[0=zwykle_pola, 1=start, 2=pre_home, 3=home]
	void loadTextures();
	
};


/*
KOLORY POLA:
0 = none
1 = neutral		/	gold
2 = blue			  \
3 = green			  \
4 = violet			  \
5 = red				  \
					  \
TYPY POLA:			  \
0 = normal			  \
1 = starting	/	safe
2 = pre_home
3 = home


*/
