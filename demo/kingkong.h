
#ifndef KINGKONG_H
#define KINGKONG_H

#include <realEngine2d/scene.h>
#include <realEngine2d/entity.h>
#include <realEngine2d/Input.h>

#include <vector>

class Kingkong : public Entity {
public:
	Kingkong();
	virtual ~Kingkong();

	virtual void update(float deltaTime);


private:
	Input* input;
};

#endif /* KINGKONG_H */