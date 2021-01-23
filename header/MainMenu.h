#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

#define MAX_NUMBER_OF_ITEMS 4

class MainMenu
{
	public:
		MainMenu(float width, float height);
		~MainMenu();
	
		void draw(sf::RenderWindow &window);
		void MoveUp();
		void MoveDown();
		void CheckCursorFocus(float m_x, float m_y);
		int GetPressedItem() { return selectedItemIndex; }
		void MenuAction(sf::RenderWindow *window, MainMenu *menu, Game *game);
	
	private:
		int selectedItemIndex;
		sf::Font font;
		sf::Text menu[MAX_NUMBER_OF_ITEMS];
		sf::Text logo;

};
