#include "base.h"


player::player(Color c)
{
    x=rand() % W;
    y=rand() % H;
    color=c;
    dir=rand() % 4;
};

void player::tick()
{    
    if (dir==up) y+=1;
    if (dir==left) x-=1;
    if (dir==right) x+=1;
    if (dir==down) y-=1;

    if (x>=W) x=0;  if (x<0) x=W-1;
    if (y>=H) y=0;  if (y<0) y=H-1;
};

void player::RandomMove(){};

Vector3f player::getColor()
{
   return Vector3f(color.r,color.g,color.b); 
};


enemie::enemie(Color c) 
{
        x=rand() % W;
        y=rand() % H;
        color=c;
        dir=rand() % 4;
};

void enemie::tick() 
{

    if (dir==up) y+=1;
    if (dir==left) x-=1;
    if (dir==right) x+=1;
    if (dir==down) y-=1;

    if (x>=W) x=0;  if (x<0) x=W-1;
    if (y>=H) y=0;  if (y<0) y=H-1;
};

Vector3f enemie::getColor()
{
    return Vector3f(color.r,color.g,color.b);
};
	
void enemie::RandomMove() 
{
    // will emplement minimax algorithm for basic AI. 
    //std::cout << "TEST\n";
    #if 0

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

    #endif

};