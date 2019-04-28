#ifndef GAME_H_INCLUDE
#define GAME_H_INCLUDE
#include <SFML/Graphics.hpp>
#include <vector>
#include "game.h"
#include "base.h"
#include "items.h"
using namespace sf;
extern const int W;
extern const int H;
extern int speed;
extern int  field[][480];
enum  Direction
{
	up,
	down,
	left,
	right,
};

class Tron
{
	public:
		Tron();
		bool is_open() const;
		RenderWindow window;
        bool Game;
       // std::vector<base_Players> Players;
       // std::vector<Item> items;

};
#endif