#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

using namespace sf;

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		void draw(RenderWindow &window, Board &board);
		~Game();
		
	private:
		bool isRun;
		
};
