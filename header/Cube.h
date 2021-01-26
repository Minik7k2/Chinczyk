#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Cube
{
	public:
		Cube(float size,float positon_x,float position_x);
		void draw(RenderWindow &window);
		//int throw_cube();
	private:
		bool isRun = true;
		RectangleShape rectangle;
		//string tab_cube[6] = {'test','test','test','test','test','test'};
		
};


