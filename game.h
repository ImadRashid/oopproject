#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "MainMenu.h"
#include "stdafx.h"
#include "mode.h"
#include "PLAYGAMEHARD.h"
#include "Easy_Play_Game.h"
#include "SplashScreen.h"
class Game
{
public:
 static void Start();
//   s sf::SoundBuffer buffer;

//    if(!buffer.loadFromFile("tada.mp3")){return ;}
//        sf::Sound splash_Sound;
  static bool IsExiting();
  static void GameLoop();
  static void CallPlayGameHard();
  //For splash screen Imad
  static void ShowSplashScreen();
  //This part was added later by imad Showing menu screen
  //after menu clas was created in 12/15/2018   11:51PM SATURDAY
//  static sf::SoundBuffer MainBuffer;
//  static sf::Sound MainSound;
  static void ShowMenu();
  static void ShowMode();
  static void CallPlayGameEasy();
//Represents different states that is different screens possible in gme
  enum GameState { Uninitialized, ShowingSplash, Paused,
          ShowingMenu, Playing, Exiting, Mode, Easy , Hard };
//
  static GameState _gameState;
//Used Render Window function here
  static sf::RenderWindow _mainWindow;
};
