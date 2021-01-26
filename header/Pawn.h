#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Board.h"

using namespace std;
using namespace sf;

class Pawn
{
public:
	Pawn();
	~Pawn();

	void draw(RenderWindow &window);
	void set_position(Board &board);
	void set_color(int color);
	void scaleDown();
	void scaleUp();
	int pawnColor;
	Vector2f startingPosition;
	bool is_inYard = true;
	
	Sprite pawnFigure;

private:
	
	Texture pawnTexture;
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
