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
	void changeFieldGroup(int groupIndex);
	bool checkIfAbleToMove(){return ableToMove;};
	void highlightOff();
	void highlightOn();
	int pathPosition;
	Sprite pawnFigure;
	Vector2f startingPosition;
	Vector2f startingPoint;
<<<<<<< Updated upstream
	~Pawn();

private:
	
	
	
	void scaleDown();
	void scaleUp();
	int fieldGroup; //0=yard, 1=path, 2=homeway, 3=home
=======
	void scaleDown(int position);
	void scaleUp(int position);
	int fieldGroup;//0=yard, 1=path, 2=homeway
	
	~Pawn();

private:
	void changeFieldGroup(int groupIndex);
>>>>>>> Stashed changes
	int pawnColor;
	bool ableToMove = true;
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
