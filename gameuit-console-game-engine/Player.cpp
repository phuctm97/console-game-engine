#include "Player.h"
#include "Game.h"

Player::Player()
{
	_width = 5;
	_height = 10;

	Game::getInstance()->registerInputNotification( CC_CALLBACK_1(Player::processInput, this) );
}

Player::~Player() {}

void Player::moveUp()
{
	int y = getPositionY();
	y -= 1;

	setPositionY( y );
}

void Player::moveDown()
{
	int y = getPositionY();
	y += 1;

	setPositionY( y );
}

void Player::setPositionX( int x )
{
	if ( x < 0 || x > Game::getInstance()->getWidth() - _width ) return;
	GameObject::setPositionX( x );
}

void Player::setPositionY( int y )
{
	if ( y < 0 || y > Game::getInstance()->getHeight() - _height ) return;
	GameObject::setPositionY( y );
}

int Player::getWidth() const { return _width; }

void Player::setWidth( int width )
{
	if ( _width == width ) return;

	_width_old = _width;
	_width = width;
	_dirty = true;
}

int Player::getHeight() const { return _height; }

void Player::setHeight( int height )
{
	if ( _height == height ) return;

	_height_old = _height;
	_height = height;
	_dirty = true;
}

void Player::childUpdate() {}

void Player::childRender()
{
	for ( int i = 0; i < _height_old; i++ ) {
		Console::setCursor( _positionX_old, _positionY_old + i );
		for ( int j = 0; j < _width_old; j++ ) {
			std::cout << char( 0x20 );
		}
	}

	for ( int i = 0; i < _height; i++ ) {
		Console::setCursor( _positionX, _positionY + i );
		for ( int j = 0; j < _width; j++ ) {
			std::cout << char( 178 );
		}
	}
}

void Player::childReset()
{
	GameObject::reset();

	_width_old = _width;
	_height_old = _height;
}

void Player::processInput( int pressedKey )
{
	
}
