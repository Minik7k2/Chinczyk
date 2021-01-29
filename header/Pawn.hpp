#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Board.hpp"

using namespace std;
using namespace sf;

class Pawn
{
public:
	Pawn();

	void draw(RenderWindow &window);
	void setOnStart();
	void set_color(int color);
	void move(int cubeOutput, Board &board);
	bool checkIfAbleToMove(int cubeOutput);
	void highlightOff();
	void highlightOn();
	int pathPosition;
	int homePosition = -1;
	Sprite pawnFigure;
	Vector2f startingPosition;
	Vector2f startingPoint;
	
	~Pawn();

private:
	
	void changeFieldGroup(int groupIndex);
	void scaleDown();
	void scaleUp();
	int fieldGroup;//0=yard, 1=path, 2=homeway
	int pawnColor;
	bool ableToMove = false;
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
