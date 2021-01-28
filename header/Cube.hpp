#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Cube
{
	public:
		Cube(float positon_x = 0,float position_x = 0);
		bool loadtexture();
		void draw(RenderWindow &window);
		int throw_cube();
		~Cube();
		
	private:
		bool isRun = true;
		int random;
		float position_x;
		float position_y;
		
		Texture *texture_cube = new Texture();
		Sprite *cube_arr = new Sprite [6];
};


