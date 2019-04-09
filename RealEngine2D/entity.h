#ifndef ENTITY_H
#define ENTITY_H


#include<vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include<RealEngine2D/sprite.h>
#include<RealEngine2D/input.h>


class Entity
{
public:

		Entity();
		~Entity();

		virtual void update(float deltaTime);

		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;

		void addChild(Entity* e);

		void removeChild(Entity* e);

		const std::vector<Entity*>& getChildren() { return children; };

		int childrenLenght() { return children.size(); };

		Sprite* getSprite() { return sprite; };

		void addSprite(std::string filepath);

		int guid() { return eid; };

		Entity* parent;
		std::vector<Entity*> children;
private:
		
		int eid;
		int nextEid;

		Sprite* sprite;
};



#endif // !ENTITY_H
