#include "SFML/Graphics.hpp" 	
#include <iostream>
#include "Menu.h"
#include "Board.h"
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1000, 800), "Ludo Master - Dominik Klodzinski & Maciej Laszewski", sf::Style::Titlebar | sf::Style::Close);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;

				case Keyboard::Down:
					menu.MoveDown();
					break;

				case Keyboard::Return:
					menu.MenuAction(&window, &menu);

					break;
				}

				break;
			case Event::Closed:
				window.close();

				break;
			case Event::MouseMoved:
    			menu.CheckCursorFocus(event.mouseMove.x, event.mouseMove.y);
    			
				break;
			case Event::MouseButtonPressed:
				if(event.mouseButton.button == sf::Mouse::Left){
					menu.MenuAction(&window, &menu);
				}
    		
				break;
			}
		}

		window.clear();
		Board board(window.getSize().x, window.getSize().y);
			
			board.draw(window);
		//menu.draw(window);

		window.display();
	}
}
