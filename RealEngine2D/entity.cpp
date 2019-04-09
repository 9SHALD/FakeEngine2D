#include <RealEngine2D/entity.h>


Entity::Entity()
{
	eid = nextEid;
	nextEid++;

	parent = NULL;

	sprite = nullptr;
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
}

Entity::~Entity()
{

}

void Entity::update(float deltaTime = 0) {
}

void Entity::addChild(Entity* e)
{
	if (e->parent != NULL) {
		e->parent->removeChild(e);
	}
	children.push_back(e);
	e->parent = this;
}

void Entity::removeChild(Entity* e) {
	std::vector< Entity* >::iterator it = children.begin();
	while (it != children.end()) {
		if ((*it)->eid == e->eid) {
			e->parent = NULL;
			it = children.erase(it);
		} else {
			++it;
		}
	}
}


void Entity::addSprite(std::string filepath)
{
	sprite = nullptr;
	sprite = new Sprite(filepath);
}
