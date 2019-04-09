#include "RealEngine2D/scene.h"

Scene::Scene() : Entity() {
	_camera = new Camera();
}

Scene::~Scene() {
	delete _camera;
}

void Scene::updateScene(float deltaTime) {
	this->_updateEntity(this, deltaTime);
}

void Scene::_updateEntity(Entity* entity, float deltaTime) {
	entity->update(deltaTime);

	std::vector<Entity*> children = entity->getChildren();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->_updateEntity(*child, deltaTime);
	}
}
