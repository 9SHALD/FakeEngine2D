// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <RealEngine2D/scene.h>
#include <RealEngine2D/core.h>
#include "demo/mainScene.h"

int main( void )
{
	Core core;
	mainScene* MainScene = new mainScene();

	MainScene->isRunning = true;

	float rot_z = 0.0f;

	do {
		core.run(MainScene);

		glfwSwapBuffers(core.renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(core.renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(core.renderer.window()) == 0 );
	delete MainScene;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
