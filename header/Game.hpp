#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Pawn.hpp"
#include "Cube.hpp"


using namespace sf;

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		void draw(RenderWindow &window);
		void load_components(RenderWindow &window);
		Pawn pawnsArr[4][4]; // [player][pawn]
		void createPawns(RenderWindow &window, Board &board);
		void live_in_game(RenderWindow &window);
		~Game();
		
	private:
		bool isRun;
		Board *board;
		Cube *cube;
		
};
