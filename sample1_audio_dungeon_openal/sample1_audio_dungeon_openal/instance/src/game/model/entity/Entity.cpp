#include "../../../../include/Entity.h"

Entity::Entity(GameWorld & gameWorld)
	: gameWorld(gameWorld), removed(false) {
}

Entity::~Entity() {
}