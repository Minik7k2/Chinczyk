#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Pawn.hpp"


using namespace sf;

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		void draw(RenderWindow &window, Board &board);
		Pawn pawnsArr[4][4]; // [player][pawn]
		void createPawns(RenderWindow &window, Board &board);
		~Game();
		
	private:
		bool isRun;
		
		
};
