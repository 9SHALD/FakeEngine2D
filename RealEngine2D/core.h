#ifndef CORE_H
#define CORE_H


#include <gl/glew.h>
#include <glfw3.h>

#include<RealEngine2D/renderer.h>
#include<RealEngine2D/scene.h>
#include<RealEngine2D/entity.h>
#include<RealEngine2D/camera.h>
#include<RealEngine2D/input.h>

#include<iostream>


class Core
{
public:

	Core();

	~Core();

	Renderer renderer;

	void run(Scene* sc);

	float deltaTime() { return (float)_deltaTime; };

private:

	float _deltaTime;
	float calculateDeltaTime();
	
	Input input;
};



#endif // !CORE_H