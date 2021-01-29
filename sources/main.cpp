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
	Image icon;
	icon.loadFromFile("../textures/icon.png"); 
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	Event event;
	Game game;
	MainMenu menu(window.getSize().x, window.getSize().y);
	MenuInfo *project = new MenuInfo(window.getSize().x, window.getSize().y, 0);
	MenuInfo *authors = new MenuInfo(window.getSize().x, window.getSize().y, 1);
	Sprite *background = new Sprite;
	Texture *bgTxt = new Texture;
	if(!bgTxt->loadFromFile("../textures/background.png"))
			cout<<endl<<"B³¹d w ³adowaniu background";
	background->setTexture(*bgTxt);
	
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if(menu.check_isRun() == true)
			{	
				if(project->check_isRun() == true)
				{
					switch (event.type)
					{
						case Event::MouseMoved:
			    			project->checkCursorFocus(event.mouseMove.x, event.mouseMove.y);
						break;
						case Event::MouseButtonPressed:
							if(event.mouseButton.button == Mouse::Left)
							{
								project->exit(&window, Vector2f(event.mouseButton.x, event.mouseButton.y));
							}
			    		break;
					}
				}
				else if(authors->check_isRun() == true){
					switch (event.type)
					{
						case Event::MouseMoved:
			    			authors->checkCursorFocus(event.mouseMove.x, event.mouseMove.y);
						break;
						case Event::MouseButtonPressed:
							if(event.mouseButton.button == Mouse::Left)
							{
								authors->exit(&window, Vector2f(event.mouseButton.x, event.mouseButton.y));
							}
			    		break;
					}
				}else{
					switch (event.type)
					{
						case Event::MouseMoved:
			    			menu.CheckCursorFocus(event.mouseMove.x, event.mouseMove.y);
						break;
						case Event::MouseButtonPressed:
							if(event.mouseButton.button == Mouse::Left)
							{
								menu.MenuAction(&window, &menu, &game, project, authors);
							}
			    		break;
					}
				}
			}
			else if(game.check_isRun() == true)
			{
				if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				{
					game.live_in_game(window, Vector2f(event.mouseButton.x, event.mouseButton.y) );
				}
			}
			
			if(event.type == Event::Closed)
				window.close();
		}
	
		if(game.check_isRun() == true)
		{
			window.clear();
			window.draw(*background);
			game.draw(window, *background);
		}
		else if(project->check_isRun() == true)
		{
			window.clear();
			window.draw(*background);
			project->draw(window);
		}
		else if(authors->check_isRun() == true)
		{
			window.clear();
			window.draw(*background);
			authors->draw(window);
		}
		else
		{
			window.clear();
			window.draw(*background);
			menu.draw(window);
		}
	
		window.display();
	}
	
}
