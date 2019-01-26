#pragma once

#include "Entity.h"

class Monster : public Entity {
public:

	Monster(GameWorld & gameWorld, int x, int y);
	virtual ~Monster();

	virtual void create() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void collision(Entity* other) override;

	virtual int getX();
	virtual void setX(int x);
	virtual int getY();
	virtual void setY(int y);

	virtual void startRoaring();
	virtual void stopRoaring();
	virtual void setRoarVolume(float volume);
protected:
	int x;
	int y;
	std::shared_ptr<OpenALSound> roar;
};