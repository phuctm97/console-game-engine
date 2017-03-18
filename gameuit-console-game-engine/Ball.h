#ifndef __BALL_H__
#define __BALL_H__

#include "GameObject.h"

class Ball : public GameObject
{
private:
	int _radius;
	int _radius_old;

public:
	Ball();

	void move( int vx, int vy );

	void setPositionX( int x ) override;

	void setPositionY( int y ) override;

	int getRadius() const;

	void setRadius( int radius );

	void childUpdate() override;

	void childRender() override;

	void childReset() override;
};

#endif
