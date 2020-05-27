////This Part was made from SFML TUTORIAL ON YOUTUBE AUTHOR IMAD RASHID

#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PLAYGAMEHARD.h"
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu {
public:

    sf::Vector2i pos;
    sf::Vector2i offset;
//	MainMenu();

	void draw(sf::RenderWindow &window);

	void MoveUp();
	void MoveDown();
//
	int GetPressedItem() { return selectedItemIndex; }
    enum MenuResult { Nothing, Exit, Play };

    MenuResult GetMenuResponse(sf::RenderWindow& window);
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text Menu[MAX_NUMBER_OF_ITEMS];

};
#endif // MAINMENU_H_INCLUDED
