#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace sf;

const int W=600;
const int H=480;
int speed = 1;
int  field[W][H]={0};
sf::Color feild_color[W][H] = {Color::White};

enum  Direction
{
	up,
	down,
	left,
	right,
};
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
	player(Color c) 
	{
		    x=rand() % W;
			y=rand() % H;
			color=c;
			dir=rand() % 4;
	}
	virtual void tick() override
	{
		if (dir==up) y+=1;
		if (dir==left) x-=1;
		if (dir==right) x+=1;
		if (dir==down) y-=1;

		if (x>=W) x=0;  if (x<0) x=W-1;
		if (y>=H) y=0;  if (y<0) y=H-1;
	}

	virtual void RandomMove() override {};
	virtual Vector3f getColor() override
		{return Vector3f(color.r,color.g,color.b);}

};

class enemie: public base_Players
{
	public:
	enemie(Color c) 
	{
		    x=rand() % W;
			y=rand() % H;
			color=c;
			dir=rand() % 4;
	}
	virtual void tick() override
		{
		
			if (dir==up) y+=1;
			if (dir==left) x-=1;
			if (dir==right) x+=1;
			if (dir==down) y-=1;

			if (x>=W) x=0;  if (x<0) x=W-1;
			if (y>=H) y=0;  if (y<0) y=H-1;
		}
	virtual Vector3f getColor() override
		{return Vector3f(color.r,color.g,color.b);}
	
	virtual void RandomMove() override
	{
		// will emplement minimax algorithm for basic AI. 
		std::cout << "TEST\n";
		bool openpath[3] = {true};
		for(int i = 0 ; i < 5 ; ++i)
		{
			if( field[x+i][y] > 0)
				openpath[0] = false;
			if( field[x-i][y] > 0)
				openpath[1] = false;
			if( field[x][y+i] > 0)
				openpath[3] = false; 
			if( field[x][y-i] > 0)
				openpath[3] = false; 
		}
		if ( openpath[0] == true)
			dir = up;
		else if( openpath[1] == true)
			dir = left;
		else if( openpath[2] == true)
			dir = right;
		else if( openpath[3] == true)
			dir = down;

	}
};

class Item
{
	public:
		int x,y,dir;
		Color color;
};

class ClearBall : public Item 
{
	public:
		ClearBall(Color c)
		{
			color = c;
			x = rand() % W;
			y = rand() % H;
		}

		void ClearAll()
		{
			for (auto i = 0; i < W ; ++i )
			{
				for ( auto j = 0; j < H ; ++i )
				{
					CircleShape c(3);
					c.setPosition(i,j); c.setFillColor(Color::Green);	
					field[i][j] = 1;
				}
			}
		}

};


int main()
{
	srand(time(0));

    RenderWindow window(VideoMode(W, H), "The Tron Game!");
    window.setFramerateLimit(60);

	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sBackground(texture);

    player p1(Color::Blue);
	enemie p2(Color::Red);
	ClearBall I1(Color::Green);

	Sprite sprite;
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
    t.clear();  t.draw(sBackground);

	bool Game=1;
	//Main Menu 
	
    //EVENT LOOP
    while (window.isOpen())
    {
		//pull input
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
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
        
		
		//update game state
		for(int i=0;i<speed;i++)
		{
			p1.tick(); p2.tick();
			//if (field[p1.x][p1.y] >= 1) Game=0;
			//if (field[p2.x][p2.y] == 1) Game=0;
			field[p1.x][p1.y] = 1;
			field[p2.x][p2.y] = 2;
			field[I1.x][I1.y] = -1;
			
			
			


			if (field[p1.x][p1.y] == -1)
			{
				std::cout << "HERE\n";
			}
			
			CircleShape c(3);
			c.setPosition(p1.x,p1.y); c.setFillColor(p1.color); t.draw(c);
			c.setPosition(p2.x,p2.y); c.setFillColor(p2.color);	t.draw(c);
			c.setPosition(I1.x ,I1.y); c.setFillColor(I1.color);t.draw(c);
			t.display();
		}
		
	   ////// draw  ///////
		window.clear();
		window.draw(sprite);
 		window.display();
		 
	}

    return 0;
}
