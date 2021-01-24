#include "SFML/Graphics.hpp" 	
#include <iostream>
#include "Game.h"
#include "MainMenu.h"
#include "Board.h"

using namespace sf;
using namespace std;


int main()
{
	
	srand(time(NULL));
	setlocale(LC_ALL,"");
	
	unsigned frame=0;
	
	RenderWindow window(VideoMode(850, 850), "Ludo Master - Dominik K³odziñski & Maciej £aszewski", Style::Titlebar | Style::Close);
	window.setActive(true);
    window.setVerticalSyncEnabled(true);

	Game game;
	MainMenu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		frame++;
		
		Event event;

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
			Board board(window);
			//game.draw(window, board);
		}
		else
		{
			window.clear();
			menu.draw(window);
		}
	

		window.display();
		
		if(!(frame%60))
	    {
	    	//cout<<frame<<" FPS"<<endl;
	    	frame=0;
		}
	}
	
}
