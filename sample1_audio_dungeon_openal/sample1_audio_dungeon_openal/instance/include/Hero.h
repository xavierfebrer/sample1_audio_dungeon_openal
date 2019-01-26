#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Entity.h"

class Hero : public Entity {
public:

	Hero(GameWorld & gameWorld, int x, int y, int life = 1);
	virtual ~Hero();

	virtual void create() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void collision(Entity* other) override;

	virtual void moveForward();
	virtual void moveBackwards();
	virtual void turnLeft();
	virtual void turnRight();

	virtual int getX();
	virtual int getY();
	virtual int getDir();
	virtual void setLife(int life);
	virtual int getLife();
	virtual bool hasReachedExit();
protected:
	int x;
	int y;
	int dir;	// 0, 1, 2, 3 -> north, east, south, west
	int life;
	bool reachedExit;

	virtual void move(int newX, int newY, int newHeroDir);
};