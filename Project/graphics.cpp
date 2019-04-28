#include "graphics.h"

graphics::graphics()
{
    texture.loadFromFile("background.jpg");
    Background.setTexture(texture);
};
