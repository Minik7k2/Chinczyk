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
		void draw(RenderWindow &window, Sprite &bg);
		Player players[4]; // [player][pawn]
		void createPlayers(RenderWindow &window, Board &board);
		void load_components(RenderWindow &window);
		void live_in_game(RenderWindow &window, Vector2f mousePos);
		~Game();
		
	private:
		int playerTurn = 0;
		int cubeOutput = 7;
		bool isRun;
		int round = 0;
		Board *board;
		Cube *cube;
		
};
