#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.hpp"

using namespace sf;
using namespace std;

Cube::Cube()
{	
	if(this->loadtexture() == true)
	{	
		//cout<<"Kostka wczytana"<<endl;
	}
	else
	{
		//cout<<"Kostka nie wczytana"<<endl;
	}
}

bool Cube::loadtexture()
{
	texture_cube->loadFromFile("../textures/cube.png");
	for (int i=0;i<=6;i++)
	{
		cube_arr[i].setTexture(*texture_cube);
		cube_arr[i].setTextureRect(IntRect(0, i*50, 50, 50));
	}
	
	return true;
}

void Cube::draw(RenderWindow &window, int x)
{
	window.draw(cube_arr[x]);
}

int Cube::throw_cube()
{
	random = rand()%6 + 1;
	return random;
}

void Cube::set_position(float x,float y)
{
	for(int i=0; i<7; i++)
		cube_arr[i].setPosition(Vector2f(x, y));
}
Vector2f Cube::get_position()
{
		return cube_arr[6].getPosition();
}

Cube::~Cube()
{
	delete(this->texture_cube);
	delete[] cube_arr;
	cout<<"Umiera kostka"<<endl;
}
