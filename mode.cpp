//#include"mode.h"

#include "mode.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

void mode::draw(sf::RenderWindow &window){
    sf::Texture modeimage;
    modeimage.loadFromFile("mode.png");
    if(!modeimage.loadFromFile("mode.png")){std::cout<<"Failed TO load mode.png\n";
    return;
    }
    sf::Sprite mode(modeimage);
    window.draw(mode);
}
mode::ModeResult mode::GetModeResponse(sf::RenderWindow &window){
while(true){
    draw(window);
    sf::Event event;
		while (window.pollEvent(event)){
            if(event.type==event.Closed){
                return Exit;
            }
            if(event.type==sf::Event::MouseButtonPressed)
			{
//            case sf::Event::MouseButtonPressed:
                if(event.key.code==sf::Mouse::Left){
                    pos = sf::Mouse::getPosition(window);

                    if(pos.x>=258 && pos.x<=468){
                        if(pos.y>=311 && pos.y<=353){
                            std::cout<<"Easy Selected\n";
                            return Easy;
                        }
                    }

                    if(pos.x>=258 && pos.x<=468){
                        if(pos.y>=381 && pos.y<=423){
                            std::cout<<"Hard Selected\n";
                            return Hard;
                        }
                    }
                }
            }
		}
//ending bracket for while loop}
window.display();
}
}
