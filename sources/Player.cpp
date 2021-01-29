#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"

using namespace sf;
using namespace std;

Player::Player()
{
	
}

void Player::setPlayerTurn(bool status)
{
	isPlayerTurn = status;
}
void Player::checkPawnsAbilityToMove(int cubeOutput)
{
	
}

void Player::drawPawns(RenderWindow &window)
{
	for(int i=0; i<4; i++)
		window.draw(playerPawns[i].pawnFigure);
}

void Player::setPlayerColor(int color)
{
	playerColor = color;
	for(int i=0; i<4; i++)
		playerPawns[i].set_color(color);
}

void Player::setPawns(Board &board)
{
	for(int i=0;i<4;i++){
			Vector2f pos = board.getPosition(board.playersYards[(playerColor*4)+i]);
			playerPawns[i].startingPosition = Vector2f(pos.x, pos.y-20);
			playerPawns[i].startingPoint = board.getPosition(board.playersStartingPoints[playerColor]);
			playerPawns[i].setOnStart();
	}
}

Player::~Player()
{
	
}
