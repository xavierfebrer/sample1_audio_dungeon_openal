#pragma once

#include "../../core/include/Util.h"
#include "../../core/include/Game.h"
#include "GameWorld.h"

class Entity {
public:
	bool removed;

	Entity(GameWorld & gameWorld);
	virtual ~Entity();

	virtual void create() = 0;
	virtual void update(double deltaTime) = 0;
	virtual void render(double deltaTime) = 0;
	virtual void collision(Entity* other) = 0;
protected:
	GameWorld & gameWorld;
};
