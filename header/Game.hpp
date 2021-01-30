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
<<<<<<< Updated upstream
		Pawn pawnsArr[4][4]; // [player][pawn]
		void createPawns(RenderWindow &window, Board &board);
		void live_in_game(RenderWindow &window);
=======
		void live_in_game(RenderWindow &window, Vector2f mousePos);
		int special_tile[8] = {6,18,30,42,0,12,24,36};
		bool security_verification(int player);
		bool attack = false;
>>>>>>> Stashed changes
		~Game();
		
	private:
		bool isRun;
		Board *board;
		Cube *cube;
		
};
