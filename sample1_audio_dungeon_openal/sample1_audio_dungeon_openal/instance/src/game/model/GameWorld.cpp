#include "../../../include/GameWorld.h"
#include "../../../include/Entity.h"
#include "../../../include/Hero.h"
#include "../../../include/Monster.h"
#include "../../../include/Terrain.h"
#include "../../../include/Exit.h"

const double GameWorld::DISTANCE_PROXIMITY_EVENTS = 5.0;
const double GameWorld::MAX_CONSTANT_VOLUME = 0.75;

GameWorld::GameWorld(Game & game) : game(game) {
}

GameWorld::~GameWorld() {
}

void GameWorld::init() {
	std::vector<std::vector<int>> map;
	map.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
	map.push_back({1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
	map.push_back({1, 0, 1, 0, 0, 1, 1, 1, 0, 1});
	map.push_back({1, 0, 0, 0, 0, 1, 0, 1, 0, 1});
	map.push_back({1, 0, 0, 1, 1, 1, 0, 0, 0, 1});
	map.push_back({1, 1, 0, 1, 0, 1, 1, 1, 1, 1});
	map.push_back({1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
	map.push_back({1, 0, 1, 1, 1, 1, 0, 1, 0, 1});
	map.push_back({1, 0, 0, 0, 0, 1, 0, 1, 0, 1});
	map.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});

	soundHeroStep = std::shared_ptr<OpenALSound>(new OpenALSound("assets/sound/hero_step.wav"));
	soundHeroStep->init();
	soundHeroHitWall = std::shared_ptr<OpenALSound>(new OpenALSound("assets/sound/hero_hit_wall.wav"));
	soundHeroHitWall->init();
	soundMonsterStep = std::shared_ptr<OpenALSound>(new OpenALSound("assets/sound/monser_step.wav"));
	soundMonsterStep->init();
	soundMonsterEat = std::shared_ptr<OpenALSound>(new OpenALSound("assets/sound/monster_eat.wav"));
	soundMonsterEat->init();

	hero = std::shared_ptr<Hero>(new Hero(*this, 1, 1));
	addEntity(hero);
	monster = std::shared_ptr<Monster>(new Monster(*this, 4, 5));
	addEntity(monster);
	exit = std::shared_ptr<Exit>(new Exit(*this, 8, 8));
	addEntity(exit);
	terrain = std::shared_ptr<Terrain>(new Terrain(*this, map));
	addEntity(terrain);
}

void GameWorld::update(double deltaTime) {
	addRemainingEntitiesToAdd();
	updateInput(deltaTime);
	updateEntities(deltaTime);
}

void GameWorld::render(double deltaTime) {
	for (int i = entities.size() - 1; i >= 0; --i) {
		entities[i]->render(deltaTime);
	}
}

void GameWorld::renderMap() {
	std::vector<std::vector<int>> map = terrain->getMap();
	std::cout << std::endl << std::endl << std::endl;
	for (int y = 0; y < map.size(); ++y) {
		std::vector<int> subMap = map[y];
		for (int x = 0; x < map[y].size(); ++x) {
			if (hero->getX() == x && hero->getY() == y) {
				int dir = hero->getDir();
				std::cout << (dir == 0 ? "^" : (dir == 1 ? ">" : (dir == 2 ? "v" : (dir == 3 ? "<" : "H" ))));
			} else if (monster->getX() == x && monster->getY() == y) {
				std::cout << "M";
			} else if (exit->getX() == x && exit->getY() == y) {
				std::cout << "E";
			} else {
				std::cout << (map[y][x] == 0 ? "." : "#");
			}
			std::cout << " ";
		}
		std::cout << std::endl << std::endl;
	}
}

int GameWorld::addEntity(const std::shared_ptr<Entity> & entity) {
	int countAdded = 0;
	entitiesToAdd.push_back(entity);
	++countAdded;
	return countAdded;
}

int GameWorld::removeEntity(const std::shared_ptr<Entity> & entity) {
	int countRemoved = 0;
	for (int i = entities.size() - 1; i >= 0; --i) {
		if (entity == entities[i]) {
			entities.erase(entities.begin() + i);
			++countRemoved;
		}
	}
	for (int i = entitiesToAdd.size() - 1; i >= 0; --i) {
		if (entity == entitiesToAdd[i]) {
			entitiesToAdd.erase(entitiesToAdd.begin() + i);
			++countRemoved;
		}
	}
	return countRemoved;
}

bool GameWorld::movePlayerTo(int newX, int newY) {
	if (terrain->isBlocked(newX, newY)) {
		playHeroHitWall();
		moveMonster();
		if (monster->getX() == hero->getX() && monster->getY() == hero->getY()) {
			hero->collision(monster.get());
			monster->collision(hero.get());
			monster->stopRoaring();
			exit->stopWaterfall();
			playMonsterEat();
		} else {
			calculateConstantSounds();
		}
		return false;
	}
	if (monster->getX() == newX && monster->getY() == newY) {
		hero->collision(monster.get());
		monster->collision(hero.get());
		monster->stopRoaring();
		exit->stopWaterfall();
		playMonsterEat();
		return true;
	}
	if (exit->getX() == newX && exit->getY() == newY) {
		hero->collision(exit.get());
		exit->collision(hero.get());
		monster->stopRoaring();
		exit->stopWaterfall();
		return true;
	}
	if (hero->getX() != newX || hero->getY() != newY) {
		playHeroStep();
	}
	calculateConstantSounds(newX, newY);
	return true;
}

void GameWorld::calculateConstantSounds() {
	calculateConstantSounds(hero->getX(), hero->getY());
}

void GameWorld::calculateConstantSounds(int heroX, int heroY) {
	double distanceMonster = sqrt(pow(heroX - monster->getX(), 2) + pow(heroY - monster->getY(), 2));
	if (distanceMonster <= DISTANCE_PROXIMITY_EVENTS) {
		monster->setRoarVolume((1 - (distanceMonster / DISTANCE_PROXIMITY_EVENTS)) * MAX_CONSTANT_VOLUME);
	} else {
		monster->setRoarVolume(0.0);
	}

	double distanceExit = sqrt(pow(heroX - exit->getX(), 2) + pow(heroY - exit->getY(), 2));
	if (distanceExit <= DISTANCE_PROXIMITY_EVENTS) {
		exit->setWaterfallVolume((1 - (distanceExit / DISTANCE_PROXIMITY_EVENTS)) * MAX_CONSTANT_VOLUME);
	} else {
		exit->setWaterfallVolume(0.0);
	}
}

void GameWorld::playHeroHitWall() {
	soundHeroHitWall->play();
}

void GameWorld::playMonsterStep() {
	soundMonsterStep->play();
}

void GameWorld::playMonsterEat() {
	soundMonsterEat->play();
}

void GameWorld::playHeroStep() {
	soundHeroStep->play();
}

void GameWorld::moveMonster() {
	int x = monster->getX();
	int y = monster->getY();
	std::vector<std::shared_ptr<Vec2<int>>> directions;
	if (!terrain->isBlocked(x, y - 1)) directions.push_back(std::shared_ptr<Vec2<int>>(new Vec2<int>(x, y - 1)));
	if (!terrain->isBlocked(x + 1, y)) directions.push_back(std::shared_ptr<Vec2<int>>(new Vec2<int>(x + 1, y)));
	if (!terrain->isBlocked(x, y + 1)) directions.push_back(std::shared_ptr<Vec2<int>>(new Vec2<int>(x, y + 1)));
	if (!terrain->isBlocked(x - 1, y)) directions.push_back(std::shared_ptr<Vec2<int>>(new Vec2<int>(x - 1, y)));
	if (directions.size() > 0) {
		Vec2<int> newPos = directions[Util::randInt(0, directions.size() - 1)].get();
		monster->setX(newPos.x);
		monster->setY(newPos.y);
		playMonsterStep();
	}
}

int GameWorld::addRemainingEntitiesToAdd() {
	int countAdded = 0;
	if (entitiesToAdd.size() > 0) {
		for (int i = entitiesToAdd.size() - 1; i >= 0; --i) {
			entities.push_back(entitiesToAdd[i]);
			(entitiesToAdd[i])->create();
			++countAdded;
		}
		entitiesToAdd.clear();
	}
	return countAdded;
}

void GameWorld::updateInput(double deltaTime) {
}

void GameWorld::updateEntities(double deltaTime) {
	for (int i = 0; i < entities.size(); ++i) {
		if (!checkRemoveFlatAndRemove(entities[i])) {
			entities[i]->update(deltaTime);
			if (checkRemoveFlatAndRemove(entities[i])) {
				--i;
			}
		} else {
			--i;
		}
	}
}

bool GameWorld::checkRemoveFlatAndRemove(const std::shared_ptr<Entity> & entity) {
	return entity->removed && removeEntity(entity) > 0;
}

bool GameWorld::hasHeroWon() {
	return hero->hasReachedExit();
}

bool GameWorld::hasHeroLost() {
	return hero->getLife() <= 0;
}
