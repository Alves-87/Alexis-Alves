#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "game.h"
#include "base.h"
#include "items.h"
#include "graphics.h"
using namespace sf;

const int W=600;
const int H=480;
int speed = 4;
int  field[W][H]={0};

int main()
{	
	// Create Game Window
	Tron game;
	// Create Game Sprite
	// 
	//  Need to merge with Tron class
	//
	graphics base_graphics;

	// Create all players and items
	player p1(Color::Blue);
	enemie p2(Color::Red);
	ClearBall I1(Color::Green);

	Sprite sprite;
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
    t.clear();  t.draw(base_graphics.Background);

	bool Game=1;
	//Main Menu 
	
    //EVENT LOOP
    while (game.is_open())
    {
		//pull input
        Event e;
        while (game.window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                game.window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir != right) p1.dir=left;
	    if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir!=left)  p1.dir=right;
	    if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir != up ) p1.dir=down;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir != down) p1.dir=up;
		//p2.RandomMove();
        // if (rand() % 15 == 0)
		// 	p2.dir = rand() % 4; 
		// if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir!=2) p2.dir=1;
	    // if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir!=1)  p2.dir=2;
	    // if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir!=0) p2.dir=3;
		// if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir!=3) p2.dir=0;

		if (!Game)	continue;
        
		    field[I1.x+1][I1.y] = -1;
			field[I1.x-1][I1.y] = -1;
			field[I1.x-1][I1.y+1] = -1;
			field[I1.x-1][I1.y-1] = -1;
			field[I1.x][I1.y+1] = -1;
			field[I1.x][I1.y-1] = -1;
			field[I1.x][I1.y] = -1;
		
		//update game state
		for(int i=0;i<speed;i++)
		{
			p1.tick(); p2.tick();
			//if (field[p1.x][p1.y] >= 1) Game=0;
			//if (field[p2.x][p2.y] == 1) Game=0;
			field[p1.x+1][p1.y+1] = 1;
			field[p2.x+1][p2.y-1] = 2;
			
			if (field[p1.x][p1.y] == -1)
			{
				std::cout << "HERE\n";
				Game = 0;
			}
			
			CircleShape c(3);
			CircleShape cc(6);
			c.setPosition(p1.x,p1.y); c.setFillColor(p1.color); t.draw(c);
			c.setPosition(p2.x,p2.y); c.setFillColor(p2.color);	t.draw(c);
			cc.setPosition(I1.x ,I1.y); cc.setFillColor(I1.color);t.draw(cc);
			t.display();
		}
		
	   ////// draw  ///////
		game.window.clear();
		game.window.draw(sprite);
 		game.window.display();
		 
	}

    return 0;
}
