#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 4

class Game
{
	public:
		Game(bool = false);
		void set_isRun();
		bool check_isRun();
		~Game();
		
	private:
		bool isRun;
		
};
