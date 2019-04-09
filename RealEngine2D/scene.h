
#ifndef SCENE_H
#define SCENE_H

#include <RealEngine2D/entity.h>
#include <RealEngine2D/sprite.h>
#include <RealEngine2D/camera.h>

#include <vector>

class Scene : public Entity {
public:
	Scene();
	~Scene();
	
	bool isRunning;

	Camera* getCamera() { return _camera; };

	void updateScene(float deltaTime);

private:
	Camera* _camera;

	void _updateEntity(Entity* entity, float deltaTime);

};

#endif /* SCENE_H */