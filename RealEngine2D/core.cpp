#include<RealEngine2D/core.h>

Core::Core() {

}

Core::~Core() {
}

void Core::run(Scene* sc) {
	calculateDeltaTime();

	renderer.renderScene(sc);

	sc->updateScene((float)_deltaTime);

	Input::getInstance()->init(renderer.window());
		
}

float Core::calculateDeltaTime() {
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();

	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}
