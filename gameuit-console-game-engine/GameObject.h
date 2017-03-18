#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <iostream>
#include "Console.h"

struct Data {};

class Game;

class GameObject
{
protected:
	// Object position
	int _positionX, _positionX_old;
	int _positionY, _positionY_old;
	bool _dirty = false;

public:
	// Constructor
	GameObject();

	GameObject( int positionX, int positionY );

	// Destructor
	~GameObject();

	// Getters, Setters
	int getPositionX() const;

	virtual void setPositionX( int positionX );

	int getPositionY() const;

	virtual void setPositionY( int positionY );

	// In-game Behaviors

	virtual void childUpdate() = 0;

	virtual void childRender() = 0;

	virtual void childReset() = 0;

	void update();

	void render();

protected:
	void reset();
};

#endif
