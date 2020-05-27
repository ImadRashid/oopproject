/*CReated on 12/16/2018 3:32PM SUNDAY
*/
#ifndef PLAYGAMEHARD_H_INCLUDED
#define PLAYGAMEHARD_H_INCLUDED
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include"stdafx.h"

class PLAYGAMEHARD {

public:

    void MOVESCOUNT();
    int  Moves_Count_INT=0;
    //String for moves
    std::string Moves_count = "0";
    //Text area for Moves text
    sf::Text T_MOVES;
    void SCOREINCREMENT();
    int ScoreINT=0;
    std::string ScoreCount = "0";
    int ts=54;//tile size
    int x0,y0,x,y;
    int click=0; sf::Vector2i pos;
    bool isSwap=false , isMoving=false;
    sf::Font font;
    sf::Text SCORE;
//    PlayGame();
    enum PlayGameResult{ win , over };
    void score();
    PlayGameResult draw(sf::RenderWindow & window);
    void MatchFind();
    void show();
    void Moves(sf::RenderWindow &window);
    void Score(sf::RenderWindow &window);
    void ClickValidate(sf::RenderWindow & window);
    struct piece;
    void swap(piece p1 , piece p2);
    PlayGameResult GetGameResponse(sf::RenderWindow &window);
};
#endif // PLAYGAME_H_INCLUDED
