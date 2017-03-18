#ifndef __SCENE_H__
#define __SCENE_H__

#include <vector>
#include "GameObject.h"

class Game;

class Scene
{
private:
	std::vector<GameObject*> _children;

public:
	// Constructor
	Scene();

	// Destructor
	~Scene();

	// In-game Behaviors
	void processInput( int pressedKey );

	void update();

	void render();

	virtual void childUpdate();

	virtual void childRender();

	// Getters, Setters
	const std::vector<GameObject*>& getChildren() const;

	void addChild( GameObject* object );
};

#endif
