#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "Scene.h"
#include "Player.h"
#include "Ball.h"

class MainScene : public Scene
{
private:
	Player* _player1;
	Player* _player2;
	Ball* _ball;

	int _ballMoveX;
	int _ballMoveY;

public:
	MainScene();

	void init();

	bool isPointInsidePlayer( int px, int py, Player* player );

	bool ballCollidedWith( Player* player );

	void childUpdate() override;

	void childRender() override;

	void processInput( int pressedKey );
};

#endif
