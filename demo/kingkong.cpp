#include "demo/kingkong.h"
#include <iostream>

Kingkong::Kingkong() {
	addSprite("assets/kingkong.tga");
	position = glm::vec3(960, 540, 0);
	scale = glm::vec3(1, 1, 1);
}

Kingkong::~Kingkong() {
}

void Kingkong::update(float deltaTime) {
	if (input->getKeyUp(W)) {
		std::cout << "Pressed W" << std::endl;
		position.y -= 10;
	}
	if(input->getKey(S)){
		std::cout << "Pressed S" << std::endl;
		position.y += 1;
	}
	if (input->getKey(A)) {
		std::cout << "Pressed A" << std::endl;
		position.x -= 1;
	}
	if (input->getKey(D)) {
		std::cout << "Pressed D" << std::endl;
		position.x += 1;
	}
}
