#include "Scene.h"
#include "Game.h"

Scene::Scene() {}

Scene::~Scene()
{
	for ( auto child: _children ) {
		delete child;
	}

	_children.clear();
}

void Scene::processInput( int pressedKey ) { }

void Scene::update()
{
	// update all children
	for ( auto child: _children ) {
		child->update();
	}

	childUpdate();
}

void Scene::render()
{
	// render all children
	for ( auto child: _children ) {
		child->render();
	}

	childRender();
}

void Scene::childUpdate() {}

void Scene::childRender() {}

const std::vector<GameObject*>& Scene::getChildren() const { return _children; }

void Scene::addChild( GameObject* object )
{
	_children.push_back( object );
}
