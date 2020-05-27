#ifndef MODE_H_INCLUDED
#define MODE_H_INCLUDED

//#include "stdafx.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class mode{
public:
    void draw(sf::RenderWindow &window );
sf::Vector2i pos;

    enum ModeResult{ Easy , Hard, Exit };

//    static ModeResult _moderesult;
    ModeResult GetModeResponse(sf::RenderWindow &window);


};

#endif // MODE_H_INCLUDED
