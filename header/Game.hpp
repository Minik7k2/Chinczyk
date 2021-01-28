#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
<<<<<<< Updated upstream:header/Game.h
#include "Board.h"
=======
#include "Board.hpp"
#include "Pawn.hpp"
#include "Cube.hpp"

>>>>>>> Stashed changes:header/Game.hpp

using namespace sf;

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		void draw(RenderWindow &window);
<<<<<<< Updated upstream:header/Game.h
=======
		void load_components(RenderWindow &window);
		Pawn pawnsArr[4][4]; // [player][pawn]
		void createPawns(RenderWindow &window, Board &board);
		void live_in_game(RenderWindow &window);
>>>>>>> Stashed changes:header/Game.hpp
		~Game();
		
	private:
		bool isRun;
		Board *board;
		Cube *cube;
		
};
