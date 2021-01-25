#include <SFML/Graphics.hpp>
#include "Cube.h"

using namespace sf;

Cube::Cube(float size, float position_x,float positon_y)
{
	rectangle = RectangleShape(Vector2f(size, size));
	rectangle.setFillColor(Color::Black);
	rectangle.setPosition(position_x,positon_y);
}

void Cube::draw(RenderWindow &window)
{
	window.draw(rectangle);
}

/*int Cube::throw_cube()
{
	
	return rand()%6 + 1;
}*/
