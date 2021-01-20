#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Game.h"
using namespace sf;
using namespace std;

Game game;

void menuAction(RenderWindow *window, Menu *menu){
	switch (menu->GetPressedItem())
	{
		case 0:
		{
			cout << "Play button has been pressed" << endl;
			game.set_isRun();
		}
		break;
		case 1:
			cout << "Option button has been pressed" << endl;
			break;
		case 2:
			cout << "Authors button has been pressed" << endl;
			break;
		case 3:
			window->close();
			break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"");
	
	unsigned frame=0;
	
	RenderWindow window(VideoMode(1000, 800), "SFML WORK!");
	window.setActive(true);
    window.setVerticalSyncEnabled(true);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		frame++;
		
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
					menuAction(&window, &menu);

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
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					menuAction(&window, &menu);
				}
    		
				break;
			}
		}
		
		if (game.check_isRun() == true)
		{
			window.clear();
		}
		else
		{
			window.clear();
			menu.draw(window);
		}
		
		window.display();
		
		if(!(frame%60))
	    {
	    	cout<<frame<<" FPS"<<endl;
	    	frame=0;
		}
	}
	
	
}
