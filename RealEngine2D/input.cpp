#include "input.h"
Input* Input::instance = nullptr;
Input* Input::getInstance() {
	if (instance == nullptr) {
		instance = new Input();
	}
	return instance;
}

Input::Input() {
	_window = nullptr;

	for (unsigned int i = 0; i < LastKey; i++) {
		_keys[i] = false;
		_keysDown[i] = false;
		_keysPressed[i] = false;
	}

	for (unsigned int i = 0; i < LastButton; i++) {
		_buttons[i] = false;
		_buttonsDown[i] = false;
		_buttonsPressed[i] = false;
	}
}

Input::~Input() {
}

void Input::init(GLFWwindow* window) {
	Input::getInstance()->_window = window;
	updateInput();
}



void Input::updateInput() {
	glfwPollEvents();

	for (unsigned int i = 32; i < LastKey; i++) {
		handleKey(i);
	}

	for (unsigned int i = 0; i < LastButton; i++) {
		handleMouse(i);
	}
}

bool Input::getKey(int keyCode) {
	return Input::getInstance()->_keys[keyCode];
}

bool Input::getKeyDown(int keyCode) {
	if (Input::getInstance()->_keys[keyCode] && !Input::getInstance()->_keysDown[keyCode]) {
		Input::getInstance()->_keysDown[keyCode] = true;
		return true;
	} else if (!Input::getInstance()->_keys[keyCode] && Input::getInstance()->_keysDown[keyCode]) {
		Input::getInstance()->_keysDown[keyCode] = false;
	}
	return false;
}

bool Input::getKeyUp(int keyCode) {
	if (Input::getInstance()->_keys[keyCode] && !Input::getInstance()->_keysDown[keyCode] && !Input::getInstance()->_keysPressed[keyCode]) {
		Input::getInstance()->_keysDown[keyCode] = true;
		Input::getInstance()->_keysPressed[keyCode] = true;
		return false;
	} else if (!Input::getInstance()->_keys[keyCode] && Input::getInstance()->_keysDown[keyCode] && Input::getInstance()->_keysPressed[keyCode]) {
		Input::getInstance()->_keysDown[keyCode] = false;
		return false;
	}
	if (!Input::getInstance()->_keys[keyCode] && !Input::getInstance()->_keysDown[keyCode] && Input::getInstance()->_keysPressed[keyCode]) {
		Input::getInstance()->_keysPressed[keyCode] = false;
		return true;
	}
	return false;
}

bool Input::getButton(int keyCode) {
	return Input::getInstance()->_buttons[keyCode];
}

bool Input::getButtonDown(int keyCode) {
	if (Input::getInstance()->_buttons[keyCode] && !Input::getInstance()->_buttonsDown[keyCode]) {
		Input::getInstance()->_buttonsDown[keyCode] = true;
		return true;
	} else if (!Input::getInstance()->_buttons[keyCode] && Input::getInstance()->_buttonsDown[keyCode]) {
		Input::getInstance()->_buttonsDown[keyCode] = false;
	}
	return false;
}

bool Input::getButtonUp(int keyCode) {
	if (Input::getInstance()->_buttons[keyCode] && !Input::getInstance()->_buttonsDown[keyCode] && !Input::getInstance()->_buttonsPressed[keyCode]) {
		Input::getInstance()->_buttonsDown[keyCode] = true;
		Input::getInstance()->_buttonsPressed[keyCode] = true;
		return false;
	} else if (!Input::getInstance()->_buttons[keyCode] && Input::getInstance()->_buttonsDown[keyCode] && Input::getInstance()->_buttonsPressed[keyCode]) {
		Input::getInstance()->_buttonsDown[keyCode] = false;
		return false;
	}
	if (!Input::getInstance()->_buttons[keyCode] && !Input::getInstance()->_buttonsDown[keyCode] && Input::getInstance()->_buttonsPressed[keyCode]) {
		Input::getInstance()->_buttonsPressed[keyCode] = false;
		return true;
	}
	return false;
}
void Input::handleKey(unsigned int key) {
	if (glfwGetKey(_window, key) == GLFW_PRESS) {
		if (_keys[key] == false) {
			Input::getInstance()->_keys[key] = true;
			//std::cout << "key Pressed: " << key << std::endl;
		} else if (glfwGetKey(_window, key) == GLFW_RELEASE) {
			Input::getInstance()->_keys[key] = false;
			//std::cout << "key released: " << key << std::endl;
		}
	}
}

void Input::handleMouse(unsigned int button) {
	if (glfwGetMouseButton(_window, button) == GLFW_PRESS) {
		if (_buttons[button] == false) {
			Input::getInstance()->_buttons[button] = true;
			glfwSetInputMode(_window, GLFW_STICKY_MOUSE_BUTTONS, 1);
			//std::cout << "button Pressed: " << button << std::endl;
		} else if (glfwGetMouseButton(_window, button) == GLFW_RELEASE) {
			Input::getInstance()->_buttons[button] = false;
			//std::cout << "button released: " << button << std::endl;
		}
	}
}
