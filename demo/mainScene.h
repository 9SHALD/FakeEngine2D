
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <realEngine2d/scene.h>
#include <realEngine2d/entity.h>
#include <realEngine2d/Input.h>
#include <vector>

#include "kingkong.h"

class mainScene : public Scene {
public:
	mainScene();
	virtual ~mainScene();

	virtual void update(float deltaTime);


private:
	Entity* pencils;
	//Entity* kingkong;
	Entity* rgba;
	Kingkong* kingkong;

};

#endif /* MAINSCENE_H */