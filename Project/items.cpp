#include "items.h"

ClearBall::ClearBall(Color c)
{
    color = c;
    x = rand() % W;
    y = rand() % H;
};

void ClearBall::ClearAll()
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
};