#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Game.h"
#include "MainScene.h"

void getGameInput( int pressedKey )
{
	// MessageBoxA( 0, std::to_string( pressedKey ).c_str(), "Key", MB_OK );

	if ( pressedKey == 59 ) {
		Game::getInstance()->exit();
	}
}

void main()
{
	// create game
	Game::createInstance( "Static game", 100, 50 );
	Game* game = Game::getInstance();

	game->registerInputNotification( getGameInput );
	game->setDelayPerFrame( 33 );

	MainScene *scene = new MainScene();

	// run the game with scene created
	game->runWithScene( scene );

	delete game;
}
