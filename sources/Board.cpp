#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <string>

using namespace std;
using namespace sf;

Board::Board(float width, float height, RenderWindow &window)
{
	sizeOfPiece = 50;
	
	fields.loadFromFile("field.png");
	
	for(int i=0; i<4; i++){
		for(int j=0; j<6;j++){
			fieldsArr[i][j].setTexture(fields);
			fieldsArr[i][j].setTextureRect(IntRect(i*50, j*50, 50, 50));
		}
	}
	
	//setting up path elements
	int startingPoint[3] = {3, 6}; 
	
	pathElements[0][0] = startingPoint[0];
	pathElements[0][1] = startingPoint[1];
	pathElements[0][2] = 1;
	
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
			pathElements[(i*4)+j][2] = 1;
			pathElements[(i*4)+j][3] = 0;
		}
		
	}
	
	//setting up starting points
	for(int i=0; i<4; i++)
	{
		pathElements[(i*12)][2] = i+2;
		pathElements[(i*12)][3] = 1;
	}
	
	//setting up pre homes
	for(int i=0; i<4; i++)
	{
		pathElements[((i*12)-3) < 0 ? 48-3 : (i*12)-3][2] = i+2;
		pathElements[((i*12)-3) < 0 ? 48-3 : (i*12)-3][3] = 2;
	}
	
	//setting up yards
	for(int i=0; i<4;i++)
	{
		for(int j=0; j<2;j++){
			for(int k=0; k<2; k++){
				
				if(i<2)
				{
					playersYards[(i*4)+(j*2)+k][0] = (i*11)+j+2;
					playersYards[(i*4)+(j*2)+k][1] = k+2;
				}
				else
				{
					playersYards[(i*4)+(j*2)+k][0] = j+2;
					playersYards[(i*4)+(j*2)+k][1] = ((i-2)*11)+k+2;
				}
				
				playersYards[(i*4)+(j*2)+k][2] = i;
				playersYards[(i*4)+(j*2)+k][3] = 0;
				
			}
		}
	}
	
	
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++){
			for(int k=0;k<48;k++)
			{
				if(i==pathElements[k][0] && j==pathElements[k][1]){
					boardPiece[i][j] = fieldsArr[pathElements[k][3]][pathElements[k][2]];
					break;
				}
					boardPiece[i][j] = fieldsArr[0][0];
			}
			
			boardPiece[i][j].setPosition(Vector2f(i*sizeOfPiece, j*sizeOfPiece));
			//window.draw(boardPiece[i][j]);
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
