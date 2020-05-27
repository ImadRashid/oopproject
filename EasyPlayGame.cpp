//#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "EasyPlayGame.h"
using namespace sf;
//#include "c_menu.h"
//using namespace sf;
//int ts = 54; //tile size
struct EasyPlayGame:: piece
{
    int x,y,col,row,kind,match,alpha;

    piece(){match=0; alpha=255;}
} sgrid[8][8];

void EasyPlayGame:: swap ( piece p1 , piece p2 ){
  std::swap(p1.col,p2.col);
  std::swap(p1.row,p2.row);

  sgrid[p1.row][p1.col]=p1;
  sgrid[p2.row][p2.col]=p2;
}
//void PlayGame::score(){
//
//}
//void PlayGame::score(){
//    sf::Text box;
//
//    sf::Font font;
//
//    if(!font.loadFromFile("arial.ttf")){
//            return;
//    }
//
//    box.setFont(font);
//    box.setColor(sf::Color::Black);
//    box.setString("0000000");
//    box.setCharacterSize(43);
//    box.setPosition(sf::Vector2f(504,43));
//
//}
void EasyPlayGame:: ClickValidate ( sf::RenderWindow &window ){

    if(click==1){
      x0=pos.x/ts+1;
      y0=pos.y/ts+1;
    }
    if(click==2){
        x=pos.x/ts+1;
        y=pos.y/ts+1;
        if (abs(x-x0)+abs(y-y0)==1){
            swap(sgrid[y0][x0],sgrid[y][x]);
            isSwap=1;
          //  SCOREINCREMENT();
            click=0;
        }

    else click=1;
    }
}
//void GameWin(){
//
//}
void EasyPlayGame::SCOREINCREMENT(){

    ScoreINT=stoi(ScoreCount);
    ScoreINT+=50;
    ScoreCount= std::to_string(ScoreINT);
}
void EasyPlayGame::Score(sf::RenderWindow &window){
//    sf::Text SCORE;
    SCORE.setFont(font);
    SCORE.setColor(sf::Color::Black);
    SCORE.setString(ScoreCount);
//    box.setCharacterSize(43);
    SCORE.setPosition(sf::Vector2f(520,43));
    window.draw(SCORE);
//    window.display();
}
void EasyPlayGame::MOVESCOUNT(){
//    std::string str1;
    Moves_Count_INT= stoi(Moves_count);
    Moves_Count_INT++;
    Moves_count= std::to_string(Moves_Count_INT);
}

void EasyPlayGame::Moves(sf::RenderWindow &window){
    T_MOVES.setFont(font);
    T_MOVES.setColor(sf::Color::Red);
    T_MOVES.setString(Moves_count);
//    MOVES.setCharacterSize();
    T_MOVES.setPosition(sf::Vector2f(656,43));
    window.draw(T_MOVES);
}

//PlayGameResult PlayGame::GetGameResponse(sf::RenderWindow &Window){
//
//
//}

EasyPlayGame::PlayGameResult EasyPlayGame::draw(sf::RenderWindow& window){

    while(true){

        srand(time(0));
//        score();
        Vector2i offset(102 ,82);
//    RenderWindow window(VideoMode(740,480), "Match-3 Game!");
//
//    window.setFramerateLimit(60);

    //test code for adding menu frame
    font.loadFromFile("KOMIKAX_.ttf");
//        if(!font.loadFromFile("KOMIKAX_.ttf")){
//            return 0;
//        }
//    c_menu menu(window.getSize().x,window.getSize().y);
    Texture t1,t2;
    t1.loadFromFile("Designs/easygrid.png");
    t2.loadFromFile("Designs/emoji.png");
    Sprite background(t1), emoji(t2);

	for (int i=1;i<=6;i++)
     for (int j=1;j<=6;j++)
      {
          sgrid[i][j].kind=rand()%3;
          sgrid[i][j].col=j;
          sgrid[i][j].row=i;
          sgrid[i][j].x = j*ts;
          sgrid[i][j].y = i*ts;
      }

//    int x0,y0,x,y; int click=0; Vector2i pos;
//    bool isSwap=false, isMoving=false;

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
				   if (!isSwap && !isMoving) click++;
				   pos = Mouse::getPosition(window)-offset;
                }
         }

         ClickValidate(window);
//    mouse click
//   if (click==1)
//    {
//      x0=pos.x/ts+1;
//      y0=pos.y/ts+1;
//    }
//   if (click==2)
//    {
//      x=pos.x/ts+1;
//      y=pos.y/ts+1;
//
//      if (abs(x-x0)+abs(y-y0)==1)
//        {
//            swap( grid[y0][x0] , grid[y][x] ) ;
//            isSwap=1;
//            click=0;
//            Score(window);
//        }
//      else click=1;
//    }

   //Match finding

   for(int i=1;i<=6;i++)


   for(int j=1;j<=6;j++)
   {
    if (sgrid[i][j].kind==sgrid[i+1][j].kind)
    if (sgrid[i][j].kind==sgrid[i-1][j].kind)
     for(int n=-1;n<=1;n++) sgrid[i+n][j].match++;

    if (sgrid[i][j].kind==sgrid[i][j+1].kind)
    if (sgrid[i][j].kind==sgrid[i][j-1].kind)
     for(int n=-1;n<=1;n++) sgrid[i][j+n].match++;
//    SCOREINCREMENT();
//   Score(window);
   }


//   SCOREINCREMENT();
   //Moving animation

   isMoving=false;
   for (int i=1;i<=6;i++)
    for (int j=1;j<=6;j++)
     {
       piece &p = sgrid[i][j];
       int dx,dy;
       for(int n=0;n<4;n++)   // 4 - speed
       {dx = p.x-p.col*ts;
        dy = p.y-p.row*ts;
        if (dx) p.x-=dx/abs(dx);
	    if (dy) p.y-=dy/abs(dy);}
       if (dx||dy) isMoving=1;
     }
//     Score(window);
   //Deleting amimation
   if (!isMoving)
//    SCOREINCREMENT();
    for (int i=1;i<=6;i++)
    for (int j=1;j<=6;j++)
    if (sgrid[i][j].match) if (sgrid[i][j].alpha>10) {sgrid[i][j].alpha-=10; isMoving=true;}

   //Get score
   int score=0;
   for (int i=1;i<=6;i++)
    for (int j=1;j<=6;j++)
      score+=sgrid[i][j].match;

   //Second swap if no match
   if (isSwap && !isMoving)
      {if (!score) swap(sgrid[y0][x0],sgrid[y][x]); isSwap=0;}

   //Update sgrid
   if (!isMoving)
    {
      for(int i=6;i>0;i--)
       for(int j=1;j<=6;j++)
         if (sgrid[i][j].match)
         for(int n=i;n>0;n--)
            if (!sgrid[n][j].match) {swap(sgrid[n][j],sgrid[i][j]); break;};

      for(int j=1;j<=6;j++)
       for(int i=6,n=0;i>0;i--)
         if (sgrid[i][j].match)
           {
            sgrid[i][j].kind = rand()%7;
            sgrid[i][j].y = -ts*n++;
            sgrid[i][j].match=0;
			sgrid[i][j].alpha = 255;
           }
     }
    //////draw///////
//    menu.draw(window);

    window.draw(background);
    Score(window);
//    window.draw(SCORE);
//    Score(window);
//    Moves(window);

    if(Moves_Count_INT <= 30){
        if(ScoreINT>=200){
            return win;
        }
    }
	for (int i=1;i<=6;i++)
     for (int j=1;j<=6;j++)
      {
        piece p = sgrid[i][j];
        emoji.setTextureRect( IntRect(p.kind*49,0,49,49));
        emoji.setColor(Color(255,255,255,p.alpha));
        emoji.setPosition(p.x,p.y);
        emoji.move(offset.x-ts,offset.y-ts);
        window.draw(emoji);
      }
     window.display();
    }
}
}
