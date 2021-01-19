#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1000, 800), "SFML WORK!");

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
					switch (menu.GetPressedItem())
					{
					case 0:
						cout << "Play button has been pressed" << endl;
						break;
					case 1:
						cout << "Option button has been pressed" << endl;
						break;
					case 2:
						cout << "Authors button has been pressed" << endl;
						break;
					case 3:
						window.close();
						break;
					}

					break;
				}

				break;
			case Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
}
