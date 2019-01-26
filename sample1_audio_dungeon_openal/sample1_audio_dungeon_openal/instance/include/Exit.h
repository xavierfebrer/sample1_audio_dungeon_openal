#pragma once

#include "Entity.h"

class Exit : public Entity {
public:

	Exit(GameWorld & gameWorld, int x, int y);
	virtual ~Exit();

	virtual void create() override;
	virtual void update(double deltaTime) override;
	virtual void render(double deltaTime) override;
	virtual void collision(Entity* other) override;

	virtual int getX();
	virtual int getY();

	virtual void startWaterfall();
	virtual void stopWaterfall();
	virtual void setWaterfallVolume(float volume);
protected:
	int x;
	int y;
	std::shared_ptr<OpenALSound> waterfall;
};