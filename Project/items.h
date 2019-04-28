#ifndef ITEMS_H_INCLUDE
#define ITEMS_H_INCLUDE
#include <SFML/Graphics.hpp>
#include "game.h"
using namespace sf;
extern const int W;
extern const int H;
extern int speed;
extern int  field[][480];

class Item
{
	public:
		int x,y,dir;
		Color color;
};

class ClearBall : public Item 
{
	public:
		ClearBall(Color c);
		void ClearAll();

};













#endif