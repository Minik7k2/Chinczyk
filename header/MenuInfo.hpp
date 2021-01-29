#pragma once
#include <SFML/Graphics.hpp>

#define NUMBER_OF_ITEMS 3

using namespace sf;

class MenuInfo
{
	public:
		MenuInfo(float width, float height, int x);
	
		void draw(RenderWindow &window);
		void checkCursorFocus(float m_x, float m_y);
		void exit(RenderWindow *window, Vector2f mousePosition);
		bool set_isRun();
		bool check_isRun();
		~MenuInfo();
	
	private:
		int selectedItemIndex;
		bool isRun = false;
		Font *font = new Font;
		Text *texts = new Text[NUMBER_OF_ITEMS];
		Sprite *logo = new Sprite;
		Texture *logoTxt = new Texture;

};
