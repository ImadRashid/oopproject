//#include "stdafx.h"
#include "SplashScreen.h"
//#include "MainMenu.h"

void SplashScreen::show(sf::RenderWindow &window){

    sf:: Texture t1,t2,SplashImage;

    SplashImage.loadFromFile("SplashScreen.jpeg");

    if( !SplashImage.loadFromFile("SplashScreen.jpeg")){
        return;
    }

    sf::Sprite sprite(SplashImage);

    while(true){

        sf::Event e ;

        while(window.pollEvent(e)){

           if(e.type == sf::Event::EventType::Closed ){
            window.close() ;
           }

           if( e.type == sf::Event::EventType::KeyPressed || e.type == sf::Event::EventType::MouseButtonPressed){
                return ;
              }
        }

    window.draw(sprite);
    window.display();
    }
}

