#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Pawn.h"

using namespace sf;

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		void draw(RenderWindow &window, Board &board);
		Pawn pawns[4][4]; // [player][pawn]
		~Game();
		
	private:
		bool isRun;
		void createPawns(Board &board);
		
};
