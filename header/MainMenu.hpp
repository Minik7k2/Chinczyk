#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"

#define MAX_NUMBER_OF_ITEMS 4

using namespace sf;

class MainMenu
{
	public:
		MainMenu(float width, float height);
	
		void draw(RenderWindow &window);
		void MoveUp();
		void MoveDown();
		void CheckCursorFocus(float m_x, float m_y);
		int GetPressedItem() { return selectedItemIndex; }
		void MenuAction(RenderWindow *window, MainMenu *menu, Game *game);
		bool set_isRun();
		bool check_isRun();
		~MainMenu();
	
	private:
		int selectedItemIndex;
		bool isRun = true;
		Font font;
		Text menu[MAX_NUMBER_OF_ITEMS];
		Text logo;

};
