#include <RealEngine2D/entity.h>


Entity::Entity()
{
	_sprite = nullptr;
	xpos = 0;
	ypos = 0;
	xscale = 0;
	yscale = 0;
	rotation = 0;
}

Entity::~Entity()
{

}

void Entity::addChild(Entity* ent)
{
	children.push_back(ent);
	ent->parent = this;
}

void Entity::addSprite(std::string filepath)
{
	_sprite = nullptr;
	_sprite = new Sprite(filepath);
}
