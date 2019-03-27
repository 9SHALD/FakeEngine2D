#include "RealEngine2D/scene.h"

Scene::Scene() {
	_camera = new Camera();
}

Scene::~Scene() {

}

void Scene::addEntity(Entity* ent) {
	_entities.push_back(ent);
}
