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
	
	RenderWindow window(VideoMode(850, 850), "Ludo Master - Dominik K³odziñski & Maciej £aszewski", Style::Titlebar | Style::Close);
	window.setActive(true);
    window.setVerticalSyncEnabled(true);
	Event event;
	Game game;
	MainMenu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		
		if(game.check_isRun() == true)
		{
			window.clear();
			game.load_components(window);		
			game.live_in_game(window, Vector2f(0,0) );	
			game.draw(window);
		}
		else
		{
			window.clear();
			menu.draw(window);
		}

		while (window.pollEvent(event))
		{
			if(menu.check_isRun() == true)
			{	
				switch (event.type)
				{
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
			}else if(game.check_isRun() == true)
			{
				if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				{
					game.live_in_game(window, Vector2f(event.mouseButton.x, event.mouseButton.y) );
				}
			}
			if(event.type == Event::Closed)
				window.close();
		}
	

		window.display();
	}
	
}
