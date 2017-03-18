#include "Ball.h"
#include "Game.h"

Ball::Ball()
{
}

void Ball::move( int vx, int vy )
{
	int x = getPositionX();
	int y = getPositionY();
	x += vx;
	y += vy;

	setPositionX( x );
	setPositionY( y );
}

void Ball::setPositionX( int x )
{
	if ( x < _radius || x > Game::getInstance()->getWidth() - _radius ) return;
	GameObject::setPositionX( x );
}

void Ball::setPositionY( int y )
{
	if ( y < _radius || y > Game::getInstance()->getHeight() - _radius ) return;
	GameObject::setPositionY( y );
}

int Ball::getRadius() const { return _radius; }

void Ball::setRadius( int radius )
{
	if ( _radius == radius ) return;

	_radius_old = _radius;
	_radius = radius;
	_dirty = true;
}

void Ball::childUpdate()
{

}

void Ball::childRender()
{
	for ( int r = _radius_old; r > 0; r-- ) {
		Console::setCursor( _positionX_old - r, _positionY_old - _radius_old + r );
		for ( int i = _positionX_old - r; i < _positionX_old + r; i++ ) {
			std::cout << char( 0x20 );
		}
		Console::setCursor( _positionX_old - r, _positionY_old + _radius_old - r );
		for ( int i = _positionX_old - r; i < _positionX_old + r; i++ ) {
			std::cout << char( 0x20 );
		}
	}

	for ( int r = _radius; r > 0; r-- ) {
		Console::setCursor( _positionX - r, _positionY - _radius + r );
		for ( int i = _positionX - r; i < _positionX + r; i++ ) {
			std::cout << char( 233 );
		}
		Console::setCursor( _positionX - r, _positionY + _radius - r );
		for ( int i = _positionX - r; i < _positionX + r; i++ ) {
			std::cout << char( 233 );
		}
	}
}

void Ball::childReset()
{
	GameObject::reset();

	_radius_old = _radius;
}
