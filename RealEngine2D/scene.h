
#ifndef SCENE_H
#define SCENE_H

#include <RealEngine2D/entity.h>
#include <RealEngine2D/sprite.h>
#include <RealEngine2D/camera.h>

#include <vector>

class Scene{
public:
	Scene();
	~Scene();

	void addEntity(Entity* ent);

	Camera* getCamera() { return _camera; };
	int entitiesLength() { return _entities.size(); };

private:
	Camera* _camera;
	std::vector <Entity*> _entities;

};

#endif /* SCENE_H */