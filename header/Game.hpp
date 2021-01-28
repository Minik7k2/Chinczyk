#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"


using namespace sf;

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		void draw(RenderWindow &window);
		Player players[4]; // [player][pawn]
		void createPlayers(RenderWindow &window, Board &board);
		~Game();
		
	private:
		bool isRun;
		
		
};
