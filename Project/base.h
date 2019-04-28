#ifndef BASE_H_INCLUDE
#define BASE_H_INCLUDE
#include <SFML/Graphics.hpp>
#include "game.h"
using namespace sf;
extern const int W;
extern const int H;
extern int speed;
extern int  field[][480];

class base_Players
{
	public:
		int x,y,dir;
		Color color;
		virtual void tick() = 0;
		virtual Vector3f getColor() = 0;
		virtual void RandomMove() = 0;
};

class player: public base_Players
{	
	public:
	player(Color c);
	virtual void tick() override;
	virtual void RandomMove() override;
	virtual Vector3f getColor() override;
};

class enemie: public base_Players
{
	public:
	enemie(Color c);
	virtual void tick() override;
	virtual Vector3f getColor() override;
	virtual void RandomMove() override;
};











#endif