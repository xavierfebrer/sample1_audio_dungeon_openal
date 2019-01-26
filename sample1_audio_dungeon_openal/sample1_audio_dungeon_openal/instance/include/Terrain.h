#pragma once

#include "Entity.h"

class Terrain : public Entity {
public:

	Terrain(GameWorld & gameWorld, std::vector<std::vector<int>> map);
	virtual ~Terrain();

	virtual void create() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void collision(Entity* other) override;

	virtual bool isBlocked(int x, int y);
	virtual std::vector<std::vector<int>> getMap();
protected:
	std::vector<std::vector<int>> map;
};