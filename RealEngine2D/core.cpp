#include<RealEngine2D/core.h>

Core::Core() {

}

Core::~Core() {
}

void Core::run(Scene* sc) {
	if (sc->isRunning) {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		calculateDeltaTime();

		Input::getInstance()->init(renderer.window());

		// Get the viewmatrix from the camera
		sc->getCamera()->computeMatricesFromInputs(renderer.window());
		glm::mat4 _viewMatrix = sc->getCamera()->getViewMatrix();
		renderer.setViewMatrix(_viewMatrix);

		// Tell the renderer to render all the entities in the scene
		for (int i = 0; i < sc->children.size(); i++) {
			renderer.renderEntity(sc->children[i]);
		}
	}
}

float Core::calculateDeltaTime() {
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();

	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}
