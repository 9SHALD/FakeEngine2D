#include "demo/mainScene.h"

mainScene::mainScene() : Scene(){

	pencils = new Entity();
	kingkong = new Entity();
	rgba = new Entity();

	pencils->addSprite("assets/pencils.tga");
	pencils->position = glm::vec3(300, 457, 0);
	pencils->scale = glm::vec3(1, 1, 1);

	kingkong->addSprite("assets/kingkong.tga");
	kingkong->position = glm::vec3(960, 540, 0);
	kingkong->scale = glm::vec3(1, 1, 1);

	rgba->addSprite("assets/rgba.tga");
	rgba->position = glm::vec3(462, 100, 0);
	rgba->scale = glm::vec3(1, 1, 1);
	
	addChild(pencils);
	addChild(kingkong);
	addChild(rgba);
}

mainScene::~mainScene() {
	delete pencils;
	delete kingkong;
	delete rgba;
}

void mainScene::update(float deltaTime) {
}
