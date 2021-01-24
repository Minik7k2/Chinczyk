#include <iostream>
#include "SFML/Graphics.hpp" 
#include "MainMenu.h"
#include "Game.h"

using namespace std;
using namespace sf;

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("../font/Lato-black.ttf"))
	{
		// handle error
	}
	logo.setFont(font);
	logo.setColor(Color::White);
	logo.setString("LUDO MASTER");
	logo.setCharacterSize(61);
	logo.setOrigin(logo.getLocalBounds().width/2, logo.getLocalBounds().height/2);
	logo.setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 0.5));
	
	menu[0].setFont(font);
	menu[0].setColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width/2, menu[0].getLocalBounds().height/2);
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

	menu[1].setFont(font);
	menu[1].setColor(Color::White);
	menu[1].setString("Options");
	menu[1].setOrigin(menu[1].getLocalBounds().width/2, menu[1].getLocalBounds().height/2);
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	
	menu[2].setFont(font);
	menu[2].setColor(Color::White);
	menu[2].setString("Authors");
	menu[2].setOrigin(menu[2].getLocalBounds().width/2, menu[2].getLocalBounds().height/2);
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.5));

	menu[3].setFont(font);
	menu[3].setColor(Color::White);
	menu[3].setString("Exit");
	menu[3].setOrigin(menu[3].getLocalBounds().width/2, menu[3].getLocalBounds().height/2);
	menu[3].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = -1;
}



void MainMenu::draw(RenderWindow &window)
{
	window.draw(logo);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void MainMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void MainMenu::CheckCursorFocus(float m_x, float m_y)
{
	Vector2f mousePosition(m_x, m_y);
	
	for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++){
		Vector2f menuTextPos = menu[i].getPosition();
		float textWidth = menu[i].getLocalBounds().width;
		float textHeight = menu[i].getLocalBounds().height;
		
		if ((mousePosition.y >= (menuTextPos.y-(textHeight/2))) && (mousePosition.y <= (menuTextPos.y+textHeight/2)) && (mousePosition.x >= (menuTextPos.x-textWidth/2)) && (mousePosition.x <= (menuTextPos.x+textWidth/2)))
		{
			menu[selectedItemIndex].setColor(Color::White);
			selectedItemIndex = i;
			menu[selectedItemIndex].setColor(Color::Red);
		}
	}
	
}
void MainMenu::MenuAction(RenderWindow *window, MainMenu *menu, Game *game)
{
	switch (menu->GetPressedItem())
	{
		case 0:
		{
			cout << "Play button has been pressed" << endl;
			game->set_isRun();
			menu->set_isRun();
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

bool MainMenu::set_isRun()
{
	isRun = false;
}

bool MainMenu::check_isRun()
{
	return isRun;
}

MainMenu::~MainMenu()
{

}
