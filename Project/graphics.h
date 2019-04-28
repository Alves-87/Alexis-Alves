#ifndef GRAPHICS_H_INCLUDE
#define GRAPHICS_H_INCLUDE
#include <SFML/Graphics.hpp>
#include "game.h"
using namespace sf;
extern const int W;
extern const int H;
extern int speed;
extern int  field[][480];

class graphics
{
	public:
		graphics();
		Texture texture;
		Sprite Background;
};
#endif