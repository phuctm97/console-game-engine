#include "MainScene.h"
#include "Game.h"

MainScene::MainScene()
{
	_ballMoveX = 1;
	_ballMoveY = 0;

	init();
}

void MainScene::init()
{
	_player1 = new Player();
	_player1->setWidth( 5 );
	_player1->setHeight( 15 );
	_player1->setPositionX( 1 );
	_player1->setPositionY( (Game::getInstance()->getHeight() - _player1->getHeight()) / 2 );
	addChild( _player1 );

	_player2 = new Player();
	_player2->setWidth( 5 );
	_player2->setHeight( 15 );
	_player2->setPositionX( Game::getInstance()->getWidth() - _player2->getWidth() - 1 );
	_player2->setPositionY( (Game::getInstance()->getHeight() - _player2->getHeight()) / 2 );
	addChild( _player2 );

	_ball = new Ball();
	_ball->setRadius( 3 );
	_ball->setPositionX( Game::getInstance()->getWidth() / 2 );
	_ball->setPositionY( Game::getInstance()->getHeight() / 2 );
	addChild( _ball );

	Game::getInstance()->registerInputNotification(
	                                               CC_CALLBACK_1( MainScene::processInput, this )
	                                              );
}

bool MainScene::isPointInsidePlayer( int px, int py, Player* player )
{
	return px >= player->getPositionX() - 1 && px <= player->getPositionX() + player->getWidth() + 1
			&& py >= player->getPositionY() - 1 && py <= player->getPositionY() + player->getHeight() + 1;
}

bool MainScene::ballCollidedWith( Player* player )
{
	int px, py;

	for ( int r = _ball->getRadius(); r > 0; r-- ) {
		px = _ball->getPositionX() - r;
		py = _ball->getPositionY() - _ball->getRadius() + r;

		for ( int i = _ball->getPositionX() - r; i < _ball->getPositionX() + r; i++ ) {
			if ( isPointInsidePlayer( px, py, player ) ) return true;
		}
		px = _ball->getPositionX() - r;
		py = _ball->getPositionY() + _ball->getRadius() - r;

		for ( int i = _ball->getPositionX() - r; i < _ball->getPositionX() + r; i++ ) {
			if ( isPointInsidePlayer( px, py, player ) ) return true;
		}
	}

	return false;
}

void MainScene::childUpdate()
{
	if ( ballCollidedWith( _player1 ) || ballCollidedWith( _player2 ) ) {
		_ballMoveX *= -1;
		_ballMoveY *= -1;
	}

	if ( _ball->getPositionX() - _ball->getRadius() ==
		_player1->getPositionX() + _player1->getWidth() ) {
		_ballMoveX *= -1;
	}
	if ( _ball->getPositionX() + _ball->getRadius() ==
		_player2->getPositionX() ) {
		_ballMoveX *= -1;
	}

	// Move ball
	_ball->move( _ballMoveX, _ballMoveY );

	if ( _ball->getPositionX() <= _ball->getRadius() ||
		_ball->getPositionX() >= Game::getInstance()->getWidth() - _ball->getRadius() )
		_ballMoveX *= -1;

	if ( _ball->getPositionY() <= _ball->getRadius() ||
		_ball->getPositionY() >= Game::getInstance()->getHeight() - _ball->getRadius() )
		_ballMoveY *= -1;
}

void MainScene::childRender() { }

void MainScene::processInput( int pressedKey )
{
	switch ( pressedKey ) {
	case 72: { // Up arrow key
		_player1->moveUp();
	}
		break;

	case 80: { // Down arrow key
		_player1->moveDown();
	}
		break;
	}
}
