
#include "MainMenu.h"
//#include<iostream>
//#include "PLAYGAMEHARD.h"
//using namespace sf
//MainMenu::MainMenu()
//{
////	if (!font.loadFromFile("arial.ttf"))
//	{
//		// handle error
//	}
//	Menu[0].setFont(font);
//	Menu[0].setColor(sf::Color::Red);
//	Menu[0].setString("Play");
//	Menu[0].setPosition(sf::Vector2f ( 740 / 2 , 480 / (MAX_NUMBER_OF_ITEMS + 1) * 1));
//	Menu[1].setFont(font);
//	Menu[1].setColor(sf::Color::White);
//	Menu[1].setString("Options");
//	Menu[1].setPosition(sf::Vector2f(740 / 2, 480 / (MAX_NUMBER_OF_ITEMS + 1) * 2));
//	Menu[2].setFont(font);
//	Menu[2].setColor(sf::Color::White);
//	Menu[2].setString("Exit");
//	Menu[2].setPosition(sf::Vector2f(740 / 2, 480 / (MAX_NUMBER_OF_ITEMS + 1) * 3));
//	selectedItemIndex = 0;
//}
void MainMenu::draw(sf::RenderWindow &window)
{
//	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
//		window.draw(Menu[i]);
//	}
    sf::Texture menuimage;
    menuimage.loadFromFile("mainmenu.jpeg");
    if(!menuimage.loadFromFile("mainmenu.jpeg")){return;}
    sf::Sprite menu(menuimage);
    window.draw(menu);
//}
//void MainMenu::MoveUp(){
//	if (selectedItemIndex - 1 >= 0)
//	{
//		Menu[selectedItemIndex].setColor(sf::Color::White);
//		selectedItemIndex--;
//		Menu[selectedItemIndex].setColor(sf::Color::Red);
//	}
//}
//void MainMenu::MoveDown()
//{
//	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
//	{
//		Menu[selectedItemIndex].setColor(sf::Color::White);
//		selectedItemIndex++;
//		Menu[selectedItemIndex].setColor(sf::Color::Red);
//	}
//}
}
MainMenu::MenuResult MainMenu::GetMenuResponse( sf::RenderWindow &window) {
//creatig window sized 600x600
	//Passing window size to Menu screen
//	MainMenu MainMenu(window.getSize().x, window.getSize().y);
	//gameloop
while(true){
//        window.clear(sf::Color (0,0,0,255));
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

                    if(pos.x>=303 && pos.x<=436){
                        if(pos.y>=159 && pos.y<=213){
                            std::cout<<"PlayButton Pressed\n";
                            return Play;
                        }
                    }

                    if(pos.x>=303 && pos.x<=435){
                        if(pos.y>=217 && pos.y<=268){
                            std::cout<<"EXITING GAME \n";
                            return Exit;
                        }
                    }
                }
            }



//            case sf::Event::MouseButtonPressed:
//                if(event.key.code==sf::Mouse::Left){
//                    pos=sf::Mouse::getPosition(window);

//			case sf::Event::KeyReleased:
//				switch (event.key.code)
//				{
//				case sf::Keyboard::Up:
//					//calling menuUP function
//					MoveUp();
//					break;
//				case sf::Keyboard::Down:
//                    //calling menudown function
//					MoveDown();
//					break;
//				case sf::Keyboard::Return:
//					switch (GetPressedItem())
//					{
//					case 0:
//						std::cout << "Play button has been pressed" << std::endl;
//						return Play;
//						break;
//					case 1:
//						std::cout << "Option button has been pressed" << std::endl;
//						break;
//					case 2:
//						window.close();
//						break;
//					}
//					break;
//				}
//				break;
//			case sf::Event::Closed:
//				window.close();
//				break;
//			}
		}
//window.draw();
window.display();
}
}

