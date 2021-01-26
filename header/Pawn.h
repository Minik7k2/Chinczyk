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
	void setOnStart();
	void set_color(int color);
	Vector2f startingPoint;
	
	Vector2f startingPosition;
	
	bool isInHome = false;
	Sprite pawnFigure;

private:
	void scaleDown();
	void scaleUp();
	int fieldGroup; //0=yard, 1=path, 2=homeway, 3=home
	int pawnColor;
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
