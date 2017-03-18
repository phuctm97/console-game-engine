#include "GameObject.h"
#include "Game.h"

GameObject::GameObject()
{
	_positionX = 0;
	_positionY = 0;
	_positionX_old = 0;
	_positionY_old = 0;
	_dirty = true;
}

GameObject::GameObject( int positionX, int positionY )
{
	_positionX = positionX;
	_positionY = positionY;
	_positionX_old = positionX;
	_positionY_old = positionY;
	_dirty = true;
}

GameObject::~GameObject() {}

int GameObject::getPositionX() const { return _positionX; }

void GameObject::setPositionX( int positionX )
{
	if ( positionX == _positionX ) return;

	_positionX_old = _positionX;
	_positionX = positionX;
	_dirty = true;
}

int GameObject::getPositionY() const { return _positionY; }

void GameObject::setPositionY( int positionY )
{
	if ( positionY == _positionY ) return;

	_positionY_old = _positionY;
	_positionY = positionY;
	_dirty = true;
}

void GameObject::update()
{
	childUpdate();
}

void GameObject::render()
{
	if ( !_dirty ) return;

	childRender();

	childReset();
}

void GameObject::reset()
{
	_positionX_old = _positionX;
	_positionY_old = _positionY;
	_dirty = false;
}
