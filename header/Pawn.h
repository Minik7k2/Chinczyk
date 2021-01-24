#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Pawn
{
public:
	Pawn(Board &board);
	~Pawn();

	void draw(sf::RenderWindow &window);
	void set_color(int color);
	void scaleDown();
	void scaleUp();
	
	int pawnColor;
	int startingPointID;
	bool is_inYard = true;
	

private:
	sf::Sprite pawnFigure;
	sf::Texture pawnTexture;
	void loadTexture();
	
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
