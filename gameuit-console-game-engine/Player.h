#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameObject.h"


class Player : public GameObject
{
private:
	int _width;
	int _width_old;

	int _height;
	int _height_old;

public:
	Player();

	~Player();

	void moveUp();

	void moveDown();

	void setPositionX( int x ) override;

	void setPositionY( int y ) override;

	int getWidth() const;

	void setWidth( int width );

	int getHeight() const;

	void setHeight( int height );

	void childUpdate() override;

	void childRender() override;

	void childReset() override;

	void processInput( int pressedKey );
};

#endif
