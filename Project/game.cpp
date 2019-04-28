
#include "base.h"
#include "items.h"
#include "game.h"

Tron::Tron()
{
    srand(time(0));
    window.create(VideoMode(W, H), "The Tron Game!");
    window.setFramerateLimit(60);	
    Game = 0;
};

bool Tron::is_open() const 
{
    return window.isOpen();
};

