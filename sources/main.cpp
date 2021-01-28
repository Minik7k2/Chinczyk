#include <SFML/Graphics.hpp>	
#include <iostream>
#include "Game.hpp"
#include "MainMenu.hpp"

using namespace sf;
using namespace std;


int main()
{
	
	srand(time(NULL));
	setlocale(LC_ALL,"");
	
	RenderWindow window(VideoMode(850, 850), "Ludo Master - Dominik Kłodziński & Maciej Łaszewski", Style::Titlebar | Style::Close);
	window.setActive(true);
    window.setVerticalSyncEnabled(true);
	Event event;
	Game game(event);
	MainMenu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		
		

		while (window.pollEvent(event))
		{
			if(menu.check_isRun() == true)
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
								menu.MenuAction(&window, &menu, &game);
							break;
						}
					break;
					case Event::MouseMoved:
		    			menu.CheckCursorFocus(event.mouseMove.x, event.mouseMove.y);
					break;
					case Event::MouseButtonPressed:
						if(event.mouseButton.button == Mouse::Left)
						{
							menu.MenuAction(&window, &menu, &game);
						}
		    		break;
				}
			}
			if(event.type == Event::Closed)
				window.close();
		}

		if(game.check_isRun() == true)
		{
			window.clear();
			game.draw(window);
			
			
		}
		else
		{
			window.clear();
			menu.draw(window);
		}
	

		window.display();
	}
	
}
