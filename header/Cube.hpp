#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Cube
{
	public:
		Cube();
		bool loadtexture();
		void draw(RenderWindow &window);
		int throw_cube();
		void set_position(float positon_x,float position_x);
		~Cube();
		
	private:
		bool isRun = true;
		int random;
		
		Texture *texture_cube = new Texture();
		Sprite *cube_arr = new Sprite [6];
};


