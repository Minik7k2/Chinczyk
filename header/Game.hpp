#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Cube.hpp"


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
		void load_components(RenderWindow &window);
		void live_in_game(RenderWindow &window, Vector2f mousePos);
		~Game();
		
	private:
		bool isRun;
		bool nextTurn = false;
		Board *board;
		Cube *cube;
		
};
