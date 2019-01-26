#pragma once

#include "../../core/include/Util.h"
#include "../../core/include/Game.h"
#include "../../core/include/CollisionUtil.h"
#include "../../core/include/OpenALSound.h"

class Entity;
class Hero;
class Monster;
class Terrain;
class Exit;

class GameWorld {
public:
	static const double DISTANCE_PROXIMITY_EVENTS;
	static const double MAX_CONSTANT_VOLUME;
	Game & game;

	GameWorld(Game & game);
	virtual ~GameWorld();

	void init();
	void update(double deltaTime);
	void render(double deltaTime);
	int addEntity(const std::shared_ptr<Entity> & entity);
	int removeEntity(const std::shared_ptr<Entity> & entity);
	virtual bool movePlayerTo(int newX, int newY);
	void playHeroHitWall();
	void moveMonster();
	void playMonsterStep();
	void playMonsterEat();
	void playHeroStep();
	void renderMap();
	bool hasHeroWon();
	bool hasHeroLost();
	void calculateConstantSounds();
	void calculateConstantSounds(int heroX, int heroY);
protected:
	std::shared_ptr<Hero> hero = nullptr;
	std::shared_ptr<Monster> monster = nullptr;
	std::shared_ptr<Exit> exit = nullptr;
	std::shared_ptr<Terrain> terrain = nullptr;
private:
	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Entity>> entitiesToAdd;
	std::shared_ptr<OpenALSound> soundHeroHitWall = nullptr;
	std::shared_ptr<OpenALSound> soundMonsterStep = nullptr;
	std::shared_ptr<OpenALSound> soundMonsterEat = nullptr;
	std::shared_ptr<OpenALSound> soundHeroStep = nullptr;

	int addRemainingEntitiesToAdd();
	void updateInput(double deltaTime);
	void updateEntities(double deltaTime);
	bool checkRemoveFlatAndRemove(const std::shared_ptr<Entity> & entity);
};

