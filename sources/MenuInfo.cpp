#include <iostream>
#include "SFML/Graphics.hpp" 
#include "MenuInfo.hpp"

using namespace std;
using namespace sf;

MenuInfo::MenuInfo(float width, float height, int x)
{
	if (!font->loadFromFile("../font/Lato-black.ttf"))
	{
		// handle error
	}
	logoTxt->loadFromFile("../textures/logo.png");
	logo->setTexture(*logoTxt);
	logo->setOrigin(logo->getLocalBounds().width/2, logo->getLocalBounds().height/2);
	logo->setPosition(Vector2f(width / 2, height / (NUMBER_OF_ITEMS + 1) * 0.5));
	
	texts[0].setFont(*font);
	texts[0].setFillColor(Color::White);
	texts[0].setOrigin(texts[0].getLocalBounds().width/2, texts[0].getLocalBounds().height/2);
	
	texts[1].setFont(*font);
	texts[1].setFillColor(Color::White);
	texts[1].setOrigin(texts[1].getLocalBounds().width/2, texts[1].getLocalBounds().height/2);
	
	texts[2].setFont(*font);
	texts[2].setFillColor(Color::White);
	texts[2].setOrigin(texts[2].getLocalBounds().width/2, texts[2].getLocalBounds().height/2);

	if(x == 0)
	{
		texts[0].setString("O projekcie");
		texts[0].setPosition(Vector2f(50, height / (NUMBER_OF_ITEMS + 1) * 1.2));
		texts[1].setCharacterSize(18);
		texts[1].setString("LudoMaster jest to odwzorowanie gry planszowej 'Chiñczyk'. \nGra dla 4 graczy polegaj¹ca na poruszaniu siê pionków do momentu wejœcia do ich domów.\nKto pierwszy doprowadzi wszystkie pionki do domu wygrywa.\n\nProjekt LudoMaster zosta³ wykonany na potrzeby zaliczenia \nmodu³u Podstawy Programowania w Collegium Da Vinci, którego \nprowadz¹cym jest Pan Roger Szczêsny.");
		texts[1].setPosition(Vector2f(50, height / (NUMBER_OF_ITEMS + 1) * 1.5));
		texts[2].setString("Wyjœcie");
		texts[2].setPosition(Vector2f(width / 2 - texts[2].getLocalBounds().width/2, height / (NUMBER_OF_ITEMS + 1) * 3.5));
	}
	else if(x == 1)
	{
		texts[0].setString("Wykonawcy");
		texts[0].setPosition(Vector2f(50, height / (NUMBER_OF_ITEMS + 1) * 1.2));
		texts[1].setCharacterSize(20);
		texts[1].setString("Dominik K³odziñski: \n	- Dbanie o optymalizacje, \n	- uwydatnianie kodu, \n	- poprawa b³êdów, \n	- gameplay.\n\nMaciej £aszewski: \n	- Grafiki, \n	- pozycjonowanie elementów, \n	- g³ówne klasy, \n	- gameplay");
		texts[1].setPosition(Vector2f(50, height / (NUMBER_OF_ITEMS + 1) * 1.5));
		texts[2].setString("Wyjœcie");
		texts[2].setPosition(Vector2f(width / 2 - texts[2].getLocalBounds().width/2, height / (NUMBER_OF_ITEMS + 1) * 3.5));
	}
}



void MenuInfo::draw(RenderWindow &window)
{
	window.draw(*logo);
	for (int i = 0; i < NUMBER_OF_ITEMS; i++)
	{
		window.draw(texts[i]);
	}
}

void MenuInfo::checkCursorFocus(float m_x, float m_y)
{
	Vector2f mousePosition(m_x, m_y);
	
	
		Vector2f menuTextPos = texts[2].getPosition();
		float textWidth = texts[2].getLocalBounds().width;
		float textHeight = texts[2].getLocalBounds().height;
		
		if ((mousePosition.y >= (menuTextPos.y-(textHeight/2))) && (mousePosition.y <= (menuTextPos.y+textHeight*1.5)) && (mousePosition.x >= (menuTextPos.x-textWidth/2)) && (mousePosition.x <= (menuTextPos.x+textWidth*1.5)))
		{
			texts[2].setFillColor(Color::Red);
		}else{
			texts[2].setFillColor(Color::White);
		}
	
}
void MenuInfo::exit(RenderWindow *window, Vector2f mousePosition)
{
	Vector2f menuTextPos = texts[2].getPosition();
		float textWidth = texts[2].getLocalBounds().width;
		float textHeight = texts[2].getLocalBounds().height;
		
		if ((mousePosition.y >= (menuTextPos.y-(textHeight/2))) && (mousePosition.y <= (menuTextPos.y+textHeight*1.5)) && (mousePosition.x >= (menuTextPos.x-textWidth/2)) && (mousePosition.x <= (menuTextPos.x+textWidth*1.5)))
		{
			isRun = false;
		}
}

bool MenuInfo::set_isRun()
{
	isRun = true;
}

bool MenuInfo::check_isRun()
{
	return isRun;
}

MenuInfo::~MenuInfo()
{

}
