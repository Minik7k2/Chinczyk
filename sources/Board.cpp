#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <string>

using namespace std;
using namespace sf;

Board::Board(float width, float height, RenderWindow &window)
{
	sizeOfPiece = 50;
	
	//setting path elements
	int startingPoint[3] = {3, 6}; 
	pathElements[0][0] = startingPoint[0];
	pathElements[0][1] = startingPoint[1];
	pathElements[0][2] = 1;
	//memcpy(pathElements[0], startingPoint, sizeof(startingPoint));
	int actualDirection;
	for(int i=0;i<12;i++)
	{
		actualDirection = directions[i];
		for(int j=0;j<4;j++){
			if(!(i==0 && j==0)){
				switch(actualDirection){
				case 0:
					{
						pathElements[(i*4)+j][0] = pathElements[((i*4)+j)-1][0]+1;
						pathElements[(i*4)+j][1] = pathElements[((i*4)+j)-1][1];
					}
					break;
				case 1:
					{
						pathElements[(i*4)+j][0] = pathElements[((i*4)+j)-1][0];
						pathElements[(i*4)+j][1] = pathElements[((i*4)+j)-1][1]-1;
					}
					break;
				case 2:
					{
						pathElements[(i*4)+j][0] = pathElements[((i*4)+j)-1][0];
						pathElements[(i*4)+j][1] = pathElements[((i*4)+j)-1][1]+1;
					}
					break;
				case 3:
					{
						pathElements[(i*4)+j][0] = pathElements[((i*4)+j)-1][0]-1;
						pathElements[(i*4)+j][1] = pathElements[((i*4)+j)-1][1];
					}
					break;
				}
			}
			pathElements[(i*4)+j][2] = 0;
		}
		
	}
	
	//setting starting points
	for(int i=0; i<4; i++){
		pathElements[(i*12)][2] = i+1;
	}
	
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++){
			boardPiece[i][j].setSize(Vector2f(sizeOfPiece, sizeOfPiece));
			boardPiece[i][j].setPosition(Vector2f(i*sizeOfPiece, j*sizeOfPiece));
			for(int k=0;k<48;k++){
				if(i==pathElements[k][0] && j==pathElements[k][1]){
					switch(pathElements[k][2])
					{
						case 0:
							boardPiece[i][j].setFillColor(Color::White);
							break;
						case 1:
							boardPiece[i][j].setFillColor(Color(2, 2, 2));
							break;
					}
					break;	
				}
					
				
				boardPiece[i][j].setFillColor(Color(150, 50, 250));
			}
				
			boardPiece[i][j].setOutlineThickness(1.f);
			boardPiece[i][j].setOutlineColor(Color(250, 150, 100));
			window.draw(boardPiece[i][j]);
		}
	}
	
	
}

Board::~Board()
{
}

void Board::draw(RenderWindow &window)
{
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++)
			window.draw(boardPiece[i][j]);
	}
}
