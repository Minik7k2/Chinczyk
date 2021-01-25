#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <string>

using namespace std;
using namespace sf;

Board::Board(RenderWindow &window)
{
	sizeOfPiece = 50;
	
	loadTextures();
	
	set_pathElements();
	set_safeFields();
	set_startingPoints();
	set_homes();
	set_yards();
	
	set_boardGrid(window);
}

void Board::set_boardGrid(RenderWindow &window) 
{
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++)
		{
			for(int k=0;k<48;k++)
			{
				if(i==pathElements[k][0] && j==pathElements[k][1])
				{
					boardPiece[i][j] = fieldsArr[pathElements[k][3]][pathElements[k][2]];
					break;
				}else if(k<16 && i==playersYards[k][0] && j==playersYards[k][1])
				{
					boardPiece[i][j] = fieldsArr[playersYards[k][3]][playersYards[k][2]];
					break;
				}else if(k<16 && i==playersHomeWays[k][0] && j==playersHomeWays[k][1])
				{
					boardPiece[i][j] = fieldsArr[playersHomeWays[k][3]][playersHomeWays[k][2]];
					break;
				}else if(k<4 && i==playersHomes[k][0] && j==playersHomes[k][1])
				{
					boardPiece[i][j] = fieldsArr[playersHomes[k][3]][playersHomes[k][2]];
					break;
				}else if(k<4 && i==playersHomes[k][0] && j==playersHomes[k][1])
				{
					boardPiece[i][j] = fieldsArr[playersHomes[k][3]][playersHomes[k][2]];
					break;
				}
				boardPiece[i][j] = fieldsArr[0][0];
			}
			
			boardPiece[i][j].setPosition(Vector2f(i*sizeOfPiece, j*sizeOfPiece));
		}
	}
	draw(window);
}

void Board::loadTextures()
{
fields.loadFromFile("../textures/field.png");
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<6;j++)
		{
			fieldsArr[i][j].setTexture(fields);
			fieldsArr[i][j].setTextureRect(IntRect(i*50, j*50, 50, 50));
		}
	}
}

void Board::draw(RenderWindow &window)
{
	for (int i = 0; i < ROW_NUMBER_OF_PIECES; i++)
	{
		for (int j = 0; j < COLUMN_NUMBER_OF_PIECES; j++)
			window.draw(boardPiece[i][j]);
	}
}



void Board::set_pathElements()
{
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
}

void Board::set_safeFields()
{
	for(int i=0; i<4; i++)
	{
		pathElements[(i*12)+6][2] = 1;
		pathElements[(i*12)+6][3] = 1;
	}
}

void Board::set_startingPoints()
{
	for(int i=0; i<4; i++)
	{
		pathElements[(i*12)][2] = i+2;
		pathElements[(i*12)][3] = 1;
	}
}

void Board::set_homes()
{
	for(int i=0; i<4; i++)
	{
		int d = ((i*12)-3) < 0 ? 48-3 : (i*12)-3;
		pathElements[d][2] = i+2;
		pathElements[d][3] = 2;
		for(int j=0; j<5;j++)
		{
			int y = (pathElements[d][1]<8) ? j+1 : ((pathElements[d][1]!=8) ? -j-1 : 0);
			int x = (pathElements[d][0]<8) ? j+1 : ((pathElements[d][0]!=8) ? -j-1 : 0);
			if(j<4)
			{
				playersHomeWays[(i*4)+j][0] = pathElements[d][0] + x;
				playersHomeWays[(i*4)+j][1] = pathElements[d][1] + y;
				playersHomeWays[(i*4)+j][2] = i+2;
				playersHomeWays[(i*4)+j][3] = 0;
			}
			else
			{
				playersHomes[i][0] = pathElements[d][0] + x;
				playersHomes[i][1] = pathElements[d][1] + y;
				playersHomes[i][2] = i+2;
				playersHomes[i][3] = 3;
			}
		}
	}
} 

void Board::set_yards()
{
	for(int i=0; i<4;i++)
	{
		for(int j=0; j<2;j++){
			for(int k=0; k<2; k++){
				
				if(i<2)
				{
					playersYards[(i*4)+(j*2)+k][0] = (i*11)+j+2;
					playersYards[(i*4)+(j*2)+k][1] = k+2;
				}
				else{
					playersYards[(i*4)+(j*2)+k][0] = (i==2 ? 11 : 0)+j+2;
					playersYards[(i*4)+(j*2)+k][1] = 11+k+2;
				}
				
				
				playersYards[(i*4)+(j*2)+k][2] = i+2;
				playersYards[(i*4)+(j*2)+k][3] = 0;
				
			}
		}
	}
}
	


Board::~Board()
{
}
