#include "game.h"
//#include "MainMenu.h"
//#include "SplashScreen.h"
////#include "PlayGame.h"
//#include "mode.h"
//#include "PLAYGAMEHARD.h"
////#include "EasyPlayGame.h"
//#include"Easy_Play_Game.h"

void Game::Start(void)
{

  if(_gameState != Uninitialized)
    return;

  _mainWindow.create(sf::VideoMode(740,480),"Master Blaster!!!!");
  _mainWindow.setFramerateLimit(60);
  //GAME STATE PLAYING WAS MADE FIRST BUT THEN WE NEEDE A START PAGE AS WELL
  //_gameState = Game::Playing;
//HERE GAME STATE IS INITIALIZED TO SHOWING SPLASH SEE THE SWITCH CASE SECTION FOR FLOW
  _gameState= Game::ShowingSplash;////////////NOTE 1:
//THE GAME LOOP RUNS AS LONG AS GAME STATE DOESNT CHANGES TO EXIT
    sf::SoundBuffer MainBuffer;
    sf::Sound MainSound;

    MainBuffer.loadFromFile("Sounds/PeterDeLang.wav");
  if(!MainBuffer.loadFromFile("Sounds/PeterDeLang.wav")){std::cout<<"failed to load\n"; }
  MainSound.setBuffer(MainBuffer);

  MainSound.play();

  while(!IsExiting())
  {
    GameLoop();//SEE GAME LOOP FOR FLOW OF GAME
  }
  //THIS MAIN WINDOW CLOASE WILL BE CALLED ONLY AFTER LOOP TERMINATES BECOMES FALSE
  _mainWindow.close();
}
//DEFINITION OF EXITING LOOP FOR CLOSING GAME
bool Game::IsExiting()
{
  if(_gameState == Game::Exiting)
    return true;
  else
    return false;
}
//DEFINITION OF GAME STARTS HERE
void Game::GameLoop()
{
//    buffer.loadFromFile("tada.mp3");
    //EVENT CREATED FOT GAME LOOP
  sf::Event currentEvent;
  while(_mainWindow.pollEvent(currentEvent)){
        std::cout<<"JUmperd to while loop\n";
      //GAME STATE IS AN ENUMERATION FOR VARIOUS POSSIBLE STATES SEE GAME.H FILE FOR DETAILS
//    if(currentEvent.type==currentEvent.Closed){IsExiting();}
    switch(_gameState)//NOTE IN FIRST ITERATION GAME STATE=SPLASHSCREEN CHECK NOTE 1 ABOVE
    {
    std::cout<<"JUmperd to switch case\n";
      case Game::ShowingSplash :
      {
          ShowSplashScreen(); //SHOW SPLASH SCREEN IS DEFINED BELOW.
          break;
      }
      case Game::Playing:
    {
        ShowMode();
        break;
    }
    case Game::ShowingMenu:
      {
          ShowMenu();
          break;
      }
      case Game::Easy:
        {
            std::cout<<"Easy called\n";
            CallPlayGameEasy();
            break;
        }
      case Game::Hard:
        {
            std::cout<<"Hard called\n";
            CallPlayGameHard();
            break;
        }
//      case Game::Playing:
//			{
//			    CallPlayGame();
//				break;
//			}
    }
  }
}

void Game::ShowSplashScreen(){
//Splash screen is a class defined in other file check SplashScreen.cpp and SplashScreen.h
//splashScreen OBJECT was created here
	SplashScreen splashScreen;
//show() function is defined in SplashScreen.cpp check it there.
	splashScreen.show(_mainWindow);

	_gameState = Game::ShowingMenu;
//    sound.setBuffer(splash_sound);
//    sound.play;
}
void Game::ShowMode(){
    mode MODE;
    mode::ModeResult result = MODE.GetModeResponse(_mainWindow);
//    std::cout<<"Easy received\n";
    switch(result){
        case mode::Exit:{
        _gameState=Exiting;
        break;
        }
        case mode::Easy:{
            _gameState=Easy;
            std::cout<<"Easy assigned\n";
            break;
        }
        case mode::Hard:{
            _gameState=Hard;
            std::cout<<"\n HArd assigned\n";
            break;
        }

    }
}
void Game::CallPlayGameEasy(){
//    EasyPlayGame easyplaygame;

    PlayGame2 playgame;
        std::cout<<"JUmperd to call Playgame easy\n";
    PlayGame2::PlayGameResult Result=playgame.draw(_mainWindow);
    std::cout<<"Play GAme easy result received\n";
    switch(Result){
        case PlayGame2::win:{
            std::cout<<"Game WIN result received from PLAYGAAME.draw()\n";
            _gameState=Game::ShowingMenu;
            break;}
        case PlayGame2::over:{
        std::cout<<"\n\nGAME OVER RECEIVED\n";
        IsExiting();
    }
        }

}
void Game::CallPlayGameHard(){

    PLAYGAMEHARD playgame;
    PLAYGAMEHARD::PlayGameResult result=playgame.draw(_mainWindow);
    switch(result){
        case PLAYGAMEHARD::win:{
            std::cout<<"Game WIN result received from PLAYGAAMEHARD.draw()\n";
            _gameState=Game::ShowingMenu;
            break;
        }
        case PLAYGAMEHARD::over:{
        std::cout<<"\n\nGAME OVER RECEIVED\n";
        IsExiting();
        }
}
//    while(true){
//            sf::Event currentEvent;
//            while(_mainWindow.pollEvent(currentEvent)){
//					if(currentEvent.type == sf::Event::Closed){
////                        _gameState = Game::Exiting;
//                        _mainWindow.close();
//                    }
//					if(currentEvent.type == sf::Event::KeyPressed){
//						    ShowMenu();
////							if(currentEvent.KeyPressed == sf::Keyboard::Escape) ShowMenu();
//                    }
//                }
//                _mainWindow.clear(sf::Color(0,0,0));
//                _mainWindow.display();
//    }

}

void Game::ShowMenu(){

	MainMenu mainMenu ;

	MainMenu::MenuResult result = mainMenu.GetMenuResponse(_mainWindow);
//    _gameState=Game::ShowingSplash;
	switch(result)
	{
	case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
