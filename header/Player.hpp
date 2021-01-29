#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Pawn.hpp"

using namespace sf;

class Player
{
	public:
		Player();
		
		int playerColor;
		Pawn* playerPawns = new Pawn[4];
		
		void drawPawns(RenderWindow &window);
		void setPlayerTurn(bool status);
		void setPlayerColor(int color);
		void setPawns(Board &board);
		void checkPawnsAbilityToMove(int cubeOutput);
		
		~Player();
		
	private:
		bool isPlayerTurn = false;
};


