#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>


class Camera {
	public:
		Camera();
		virtual ~Camera();
		void computeMatricesFromInputs(GLFWwindow* window);

		glm::mat4 getViewMatrix() { return _viewMatrix; };
		glm::vec3 getCursor() { return cursor; };


	private:
		glm::mat4 _viewMatrix;

		glm::vec3 position;
		glm::vec3 cursor;
		float speed;

		glm::vec3 right;
		glm::vec3 up;
};


#endif
